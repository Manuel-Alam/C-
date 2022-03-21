Name: Manuel Alam
Student Number: 101182018 

All files:

h files:
Control.h //Declare methods and variables to be coded in Control.cc
defs.h //Declare constants to be used across all the classes and h files.
List.h //Declare methods and variables to be coded in List.cc
Location.h //Declare methods and variables to be coded in Location.cc
Product.h //Declare methods and variables to be coded in Product.cc
Queue.h //Declare methods and variables to be coded in Queue.cc
Store.h //Declare methods and variables to be coded in Store.cc
StoreLocation.h //Declare methods and variables to be coded in StoreLocation.cc
View.h //Declare methods and variables to be coded in View.cc
WHLocation.h //Declare methods and variables to be coded in WHLocation.cc


cc files:

Control.cc //Class used to create Control objects and methods.
List.cc //Class used to create List objects and methods.
Location.cc //Superclass used to create Location objects and methods.
Product.cc //Class used to create Product objects and methods.
Queue.cc //Class used to create Queue objects and methods.
Store.cc //Class used to create Store objects and methods.
StoreLocation.cc //Sub Class used to create StoreLocation objects and methods.
View.cc //Class used to create View objects and methods.
WHLocation.cc //Sub Class used to create WHLocation objects and methods.
main.cc//Tester code used to test all the classes

.o files://all these are used to compile the program
Control.o
List.o
Location.o
main.o
Product.o
Queue.o
Store.o
StoreLocation.o
View.o
WHLocation.o

Comments:

I commented out the initStore() method in the Control class, so uncomment it if you need.

How to compile:

1. To compile all the files at once type "make" into the terminal.

2. The "make" command will compile all the files together and create object files and an executable "a3".

3. To run the program type "./a3" into the console.

4. Once the program is ran, a menu will pop up with 6 options.

5. Selecting options from 1 to 5 will cause the console to output the tester methods.

6. After selecting any option from 1 to 5 the selection menu will pop up again.

7. If option 0 is selected then the program will terminate.


