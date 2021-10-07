# Sympletron

## What is it?
Sympletron is a very simple compiler, which has the indivisibility of memory (instructions and data are stored in the same memory) and can do some very simple operations.
It can read an integer from the keyboard and place it at the specified address in its memory, it can display an integer or instruction number placed in the specified memory cell.
Sympletron also can add, subtract and multiply the numbers in the specified cell with the value placed in the accumulator (just like in assembly).
The list of commands is really small, but this project can be expanded, for example, to add the ability to work with floating point numbers, to change the memory representation to hexadecimal, to expand the memory, to save the memory state after the last execution, etc.

## How to build and run?
The executable file located in `bin/Debug/Project_Sympletron.exe.` All you need to do is just to run it.

## How to use?
At the beginning the Sympletron will greet you. Then it will show you a list of commands and their codes after which it will offer you a "terminal" to work with it.

<img src="/screenshots/greeting.png" alt="Greeting_of_Sympletron"/>

Then you can start to input the commands. To finish entering commands you must enter 43000. After that to start the program execution you must enter -99999.
After the program execution Sympletron displays all information about its state on the screen.

An example of subtracting two numbers is shown in the screenshot below.

`000? 10010`  //enter a number into the 10th memory cell  
`001? 10011`  //enter a number into the 11th memory cell  
`002? 20010`  //put the number from the 10th memory cell to the accumulator  
`003? 31011`  //subtract from the number in the accumulator the number in the 11th cell  
`004? 21012`  //output the number from the accumulator to the 12th memory cell  
`005? 43000`  //end the entering of commands  
`006? -99999` //start the program execution  

<img src="/screenshots/subtracting.png" alt="Subrtacting"/>

## P. S. 
This is my first pet-project and first README file also. 
The project was written on C. And the main purpose of writting it is to improve my skills in using github and to try to write good description of this simple project.

## Support
You can contact me using email vitalymayer1706@gmail.com. I'd be happy to help you