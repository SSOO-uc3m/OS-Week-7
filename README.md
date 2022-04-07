# Lab Introduction to Processes

## Goals

- Practice with thread concepts. 
- Using threads system calls in POSIX. 


## Statements

###  Exercise 01

Write a program that creates 1 thread that prints a message 3 times: "Thread says hi!", sleeps 1 second between each message and then indicates that it ends. The parent thread program must wait until the child thread terminates.

###  Exercise 02

Make a program that:

- declares a global variable "myglobal”
- creates 1 thread ``print_dots``. 
- The program then makes a for up to 20 in the increments myglobal by 1. Then it ends up printing the value of myglobal.
- The function ``print_dots`` executes a loop 20 where in each turn the value of myglobal is assigned to an auxiliary variable that is incremented. A "." Is printed. per lap. When finished, it sleeps 1sec and saves the auxiliary value in myglobal.

Request:

a) Implement the program

b) Run the program and see what happens to the value of myglobal. Is it the same if it is run multiple times?

When modifying a global variable concurrently by parent and child thread, we cannot know what the final value will be. In each case it can come out differently, both in printing order and in number. Below are 2 running examples:
````
./main o.o.o...o.o.o.o..o.oo.o.o.o.o.o.o..o.o.oo.o.o.o.o.o..o.o.o.o..o.o.o.oo.o.o.o..........................ooooo.o.o.o.o.o.o.o..o.o.o.o.oo.o.o.o.o.o.o.o.o.o.o.oo.o.o.o.o.o.o.o.o.o.o.ooooooooooooooooooooooo
myglobal equals 123

./main
o.o.o.o.o.o.oo.ooo.o.o.oo.......o.o.oo.o..o.o.oo..oo..oo.o..oo..oo.oooooooooooooooooo.o.o.oo..oo..oo.o..oo.oooo.o.o..o.ooo.o.o.o..o.oo.o.ooo..o..oo..o.o.o.oo.o.o..o.o.o.o..oo..oo......................
myglobal equals 101
````

###  Exercise 03

Write a program that creates a variable number of threads, indicated with an argument. 

- Create a function that prints "Hello from thread" and the thread number and ends.
- The parent receives the number of threads (integer) as an argument and executes a for loop that creates those threads. Then wait for all threads to finish and finish.

###  Exercise 04

Write a program that 

- Declares 2 functions, 1 and 2, where the identity of the thread that is executing is indicated. 
- function 1 sleeps 2 seconds and function 2 sleeps 5 seconds. 
 -Next the main program must launch 2 threads, one for each function, write its own identity and terminate.
 -Write a new version where the parent waits for the children to finish before finishing.
 
 ###  Exercise 05
 
Write a program that adds values in concurrency using threads. 

- The program declares a global variable total_addition 
- A procedure called ``add`` that increments ```total_addition``` by 100 using an intermediate local variable, sleeps for a second, and assigns the internal variable to ```total_addition```.
- The main then creates 10 threads ``add``, waits for them to finish, prints the computed sum value, and terminates.

As a variant, eliminate sleep time and indicate what happens.
