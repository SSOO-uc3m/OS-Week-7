#include "week_07.h"

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>



/*
Exercise 01
Write a program that creates 1 thread that prints a message 3 times: "Thread says hi!", sleeps 1 second between each message and then indicates that it ends. The parent thread program must wait until the child thread terminates
*/
void * thread_function (void *arg) {
 
  return NULL;
}

int exercise01(){

  
}


/*
  Exercise 02
Make a program that:

declares a global variable "myglobal”
creates 1 thread print_dots.
The program then makes a for up to 20 in the increments myglobal by 1. Then it ends up printing the value of myglobal.
The function print_dots executes a loop 20 where in each turn the value of myglobal is assigned to an auxiliary variable that is incremented. A "." Is printed. per lap. When finished, it sleeps 1sec and saves the auxiliary value in myglobal.
Request:

a) Implement the program

b) Run the program and see what happens to the value of myglobal. Is it the same if it is run multiple times?
  */

int myglobal=0; 

void * print_dots(void *arg) {

  return NULL;
}

int exercise02(){

  
}

/*Exercise 03
Write a program that creates a variable number of threads, indicated with an argument.

Create a function that prints "Hello from thread" and the thread number and ends.
The parent receives the number of threads (integer) as an argument and executes a for loop that creates those threads. Then wait for all threads to finish and finish.
*/

void *hello(void *arg) {
        
        return (NULL);
}

int exercise03(){

  
}

/*Exercise 04
Write a program that

Declares 2 functions, 1 and 2, where the identity of the thread that is executing is indicated.
function 1 sleeps 2 seconds and function 2 sleeps 5 seconds. -Next the main program must launch 2 threads, one for each function, write its own identity and terminate. -Write a new version where the parent waits for the children to finish before finishing.*/


void *func1 (){
 
}

void *func2 (){
 
}

int exercise04(){

  
}

/*
Exercise 05
Write a program that adds values in concurrency using threads.

The program declares a global variable sum_total
A procedure called add that increments total_addition by 100 using an intermediate local variable, sleeps for a second, and assigns the internal variable to total_addition.
The main then creates 10 threads add, waits for them to finish, prints the computed sum value, and terminates.
*/

int total_addition=0; 

void * add (void *arg) {

  return NULL;
}

 
int exercise05(){

  
}
