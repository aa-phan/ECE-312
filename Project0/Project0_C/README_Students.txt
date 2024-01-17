There are 5 programs shown here.  These are for practice.  Here is what you need to do.

1.  Develop your solutions on CLion
Use an IDE (like CLion) to complete the programs. Make a directory called Project0 or Practice_Projects or whatever.  Start up CLion, and create a C project for your first project in a sub-directory of the directory that you just created.  Any files that you read in (such as a/print_squares_input.txt) should go in the cmake-build-debug directory.

For each of the problems, follow the instruction to complete the program. You will get an output which is in a file or characters printed to the console. Eyeball the output to check its correctness.  Then use some variation of the Linux command diff (also search for diff on the internet) to compare your own output to the golden output.

2. Test your solutions on a machine running the Linux OS
Make a folder on the Linux server kamek, and under it, make 5 folders, one for each practice problem.  Copy your solutions and the input files over to kamek, and then use gcc to compile the programs. Then run the programs. If you copy the golden ouptut also over to kamek, you can use the Linux 'diff' command to compare your output to the given one.
Linux also has an output redirect feature: for example, if you program is called a.out, you can redirect the output to a file by executing on the command line:
a.out > my_output.txt
Input redirect also exists to read from a file instead of from a keyboard.

Submission
----------
Submit your solutions in the following way:
a) zip your program files up.
b) rename the .zip file Project0_<your EID>.zip
c) Submit to Canvas.

Alternative way (less recommended) is to simply turn in your files individually, without zipping them up.

Do this before the deadline.  If we have time, we will look at your code and offer suggestions.  It will not be graded, although this assignment is not optional, but is mandatory.

