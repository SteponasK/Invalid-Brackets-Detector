## Invalid Bracket Detector
* This application detects invalid brackets in a given file. The possible brackets are [] {} (). 
## 🚫 Error
* Invalid bracket information is printed in this format:

    ```
    Invalid bracket <bracket_type> found at <file_path>:<line_number>:<column_number>.
    ```
## ➕ Additions:
  * Does your application support files larger than your computer’s RAM?
  * * Current implementation reads given file line by line, so it is memory-efficient. So it should handle files larger than computers RAM. 
* * If there are performance issues, and we need to optimise reading, we could read the file by chunks.

* After your program finishes processing the input from the file, some other module should process this input. Another module can do it in parallel. What is the best “place” in the program to call this module? The module can be called by function nextProcessor(input string)

* * The best place to call __nextProccessor()__, would be right after line 87 if we want to process all the errors after the __whole__ file was scanned:
``` detector.detectInvalidBrackets();```


## ⬇️ Getting Started:
* Clone the repo:
    ```
    https://github.com/SteponasK/Invalid-Brackets-Detector.git
    ```
* run main.cpp file.
* * DONT FORGET COMMAND LINE ARGUMENTS!:
    ```
     Usage: ./bracket_detector <filePath>
    ```


## 👑 Authors
* SteponasK - initial work.