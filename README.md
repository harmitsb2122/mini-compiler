# Instructions

## Instructions to run

- Open terminal
- Type: make fname=<filename> .A file parser would be created.
- Type: ./parser <inputfilename.txt> to generate the output
- In case the .y file (to be executed) is updated, one has to type: make clean ,before executing the above commands.
- input test cases are named as per the convention <testi.c> .

Output convention :

- Line no represents the line number (new block of code) which has been tested.
- The TAC is generated during the parsing process and the subsequent errors are shown.

Notes :

- Labels are HANDLED
- Arithmetic expressions are HANDLED
- while statements are HANDLED
- nested while statements are HANDLED
- relational operations are HANDLED (Basic)
- Basic declarations of variables with types arrays,integers,characters,floating points numbers and structs are HANDLED.
- Scope checking is HANDLED.
- Currently complex conditionals are HANDLED.
- typecasting is HANDLED.
- Data Types - char -> 1 byte ; int , float, pointer ->4 bytes each ; long -> 8 bytes.
