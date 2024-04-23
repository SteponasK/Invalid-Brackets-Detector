#include <iostream>
#include <fstream>
#include <stack>
#include <string>

class BracketDetector {
private:
	std::string filePath;
	std::ifstream file;
	std::stack<std::pair<char, std::pair<int, int>>> bracketStack;

	void readLine(const std::string& line, int lineNumber) {
		for (int i = 0; i < line.length(); ++i) {
			char symbol = line[i];
			if (symbol == '(' || symbol == '[' || symbol == '{') {
				bracketStack.push(std::make_pair(symbol, std::make_pair(lineNumber, i + 1)));
			}
			else if (symbol == ')' || symbol == ']' || symbol == '}') {
				handleClosingBracket(symbol, lineNumber, i);
			}
		}
	}

	void handleClosingBracket(char symbol, int lineNumber, int position) {
		if (bracketStack.empty()) {
			std::cout << "Invalid bracket " << symbol << " found at " << filePath << ':'
				<< lineNumber << ':' << (position + 1) << '.' << std::endl;
		}
		else {
			char top = bracketStack.top().first;
			if ((symbol == ')' && top != '(') || (symbol == ']' && top != '[') || (symbol == '}' && top != '{')) {
				std::cout << "Invalid bracket " << symbol << " found at " << filePath << ':'
					<< lineNumber << ':' << (position + 1) << '.' << std::endl;
			}
			else {
				bracketStack.pop();
			}
		}
	}

	void printInvalidBrackets() {
		while (!bracketStack.empty()) {
			char top = bracketStack.top().first;
			std::cout << "Invalid bracket " << top << " found at " << filePath << ':'
				<< bracketStack.top().second.first << ':' << bracketStack.top().second.second << '.' << std::endl;
			bracketStack.pop();
		}
	}

public:
	BracketDetector(std::string& path) : filePath(path) {}

	bool openFile() {
		file.open(filePath);
		return file.is_open();
	}

	void closeFile() {
		file.close();
	}

    void detectInvalidBrackets() {
        std::string line;
        int lineNumber = 1;

		while (std::getline(file, line)) {
			readLine(line, lineNumber);
			++lineNumber;
		}
    }
};

int main(int argc, char* argv[]) {

	if (argc != 2) {
		return 1;
	}

	std::string filePath = argv[1];
	BracketDetector detector(filePath);

	if (!detector.openFile()) {
		std::cout << "File '" << filePath << "' could not be opened" << std::endl;
		return 1;
	}

	detector.detectInvalidBrackets();
	detector.closeFile();

	return 0;
}

