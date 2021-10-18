# Sympletron

## What is it?
Sympletron is a very simple programming language with embedded interpreter, which has the indivisibility of memory (instructions and data are stored in the same memory) and can do some very simple operations.
It can read an integer from the keyboard and place it at the specified address in its memory, it can display an integer or instruction number placed in the specified memory cell.
Sympletron also can add, subtract and multiply the numbers in the specified cell with the value placed in the accumulator (just like in assembly).
The list of commands is really small, but this project can be expanded, for example, to add the ability to work with floating point numbers, to change the memory representation to hexadecimal, to expand the memory, to save the memory state after the last execution, etc.

## How to build and run?
The executable file located in `bin/Debug/Project_Sympletron.exe.` All you need to do is just to run it.

## How to use?
### Subtracting with keyboard input
At the beginning the Sympletron will greet you. Then it will show you a list of commands and their codes after which it will offer you a "terminal" to work with it.

<img src="/screenshots/sympletron_greeting.png" alt="Greeting_of_Sympletron"/>

Then you can choose the type of input: enter 1 to select keyboard input, enter 2 to select input from the file. We choose the 1st option in this example.
After that you can start to input the commands. To finish entering commands you must enter 4300. Then you must enter -99999 to start the program execution.
After the program execution Sympletron displays all information about its state on the screen.

An example of subtracting two numbers is shown in the screenshot below.

`00? 1002`   - enter a number into the 2nd memory cell  
`01? 4003`   - go to the instruction on the 3rd memory cell  
`02? 0000`   - reserve the 2nd memory cell for data  
`03? 1005`   - enter a number into the 5th memory cell  
`04? 4006`   - go to the instruction on the 6th memory cell  
`05? 0000`   - reserve the 5th memory cell for data  
`06? 2002`   - put the number from the 2nd memory cell to the accumulator  
`07? 3105`   - subtract from the number in the accumulator the number in the 5th cell  
`08? 2110`   - output the number from the accumulator to the 10th memory cell  
`09? 4011`   - go to the instruction on the 11th memory cell  
`10? 0000`   - reserve the 10th memory cell for data  
`11? 4300`   - end the entering of commands  
`12? -99999` - start the program execution  

<img src="/screenshots/subtracting_with_keyboard.png" alt="Subrtacting"/>

### Loop implementation with input from the file
To input your program from the file you must put this file in `bin/Debug/` and name it `commands.txt`.

To show the implementation of conditional operators and loops let's solve a simple problem. 
If the user enters a negative number or equal to zero, this number will be displayed on the screen.
If the user enters a positive number, numbers down to 1 will be displayed.
The user is asked to enter two numbers, the first of which should always be 1, because it is an decrement, the second number is a condition for solving the problem.

`00? 1002` - enter a number into the 2nd memory cell  
`01? 4003` - go to the instruction on the 3rd memory cell  
`02? 0000` - reserve the 2nd memory cell for data  
`03? 1005` - enter a number into the 5th memory cell  
`04? 4006` - go to the instruction on the 6th memory cell  
`05? 0000` - reserve the 5th memory cell for data  
`06? 2005` - put the number from the 5th memory cell to the accumulator  
`07? 1105` - output to screen the number from the 5th memory cell  
`08? 4117` - go to the instruction on the 17th memory cell if accumulator less then 0  
`09? 4217` - go to the instruction on the 17nd memory cell if accumulator equals 0  
`10? 3102` - subtract from the number in the accumulator the number in the 2nd cell 
`11? 2113` - output the number from the accumulator to the 13th memory cell  
`12? 4014` - go to the instruction on the 14th memory cell  
`13? 0000` - reserve the 11th memory cell for data  
`14? 1113` - output to screen the number from the 13th memory cell  
`15? 4118` - go to the instruction on the 18nd memory cell if accumulator less then 0  
`16? 4218` - go to the instruction on the 18nd memory cell if accumulator equals 0  
`17? 4010` - go to the instruction on the 10th memory cell  
`18? 4300` - end the entering of commands in this branch  
`19? -99999` - start the program execution  

<img src="/screenshots/code_of_program.png" alt="Code"/>

The implementation of the loop is shown by the 10th-16th commands.

<img src="/screenshots/execution.png" alt="Execution"/>

## Updates
### Verion 1.1 (18.10.2021)
* New functionality: conditional statements and loops.
* The ability to read programs from a file has been added.
* Memory processing were improved.
* Code structure was redesigned.

## P. S. 
This is my first pet-project and first README file also. 
The project was written on C. And the main purpose of writting it is to improve my skills in using github and to try to write good description of this simple project.

## Support
You can contact me using email vitalymayer1706@gmail.com. I'd be happy to help you.