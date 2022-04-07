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
 for (int i=0 ; i < 3 ; i++ ) {
    printf("Thread says hi!\n");
    sleep(1);
  }
  return NULL;
}

int exercise01(){
  pthread_t mythread;
	printf("Launching new thread . . .\n");  
  if ( pthread_create( &mythread, NULL, thread_function, NULL) ) {
    printf("error creating thread.");
    abort();
  }
  printf("Waiting on join\n");
  if ( pthread_join ( mythread, NULL ) ) {
    printf("error joining thread.\n");
    return(-1);
  }

  return(0);
  
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

  int j;
  for (int i=0; i<100; i++ ) {
    j=myglobal;
    j=j+1;
    printf(".");
    fflush(stdout);
   sleep(0.05);
    myglobal=j;
  }
  return NULL;
}

int exercise02(){
  pthread_t mythread;
  

  if ( pthread_create( &mythread, NULL, print_dots, NULL) ) {
    printf("error creating thread.");
    return -1;
  }

  for (int i=0; i<100; i++) {
    myglobal=myglobal+1;
    printf("o"); fflush(stdout);
    sleep(0.05);
  }
  if ( pthread_join ( mythread, NULL ) ) {
    printf("error joining thread.");
	return(-1);
  }
  printf("\nmyglobal equals %d\n",myglobal);
  return(0);
  
}

/*Exercise 03
Write a program that creates a variable number of threads, indicated with an argument.

Create a function that prints "Hello from thread" and the thread number and ends.
The parent receives the number of threads (integer) as an argument and executes a for loop that creates those threads. Then wait for all threads to finish and finish.
*/

void *hello(void *arg) {
        
 parm *p=(parm *)arg;
 printf("Hello from thread %d\n", p->id);
 return (NULL);
}

int exercise03(int argc, char * argv[]){
  int n;
        pthread_t *threads;
        pthread_attr_t pthread_custom_attr;
        parm *p; // structure that stores and int
		
		if(argc != 2){
			printf ("The number of arguments have to be one\n"); 

			return(-1);
		}
			
        n=atoi(argv[1]);
        if ((n < 1) || (n > MAX_THREAD)) { 
			  printf ("The no of thread should be between 1 and %d.\n",MAX_THREAD); 
		  	return(-1); 
		}

        threads=(pthread_t *)malloc(n*sizeof(*threads));
        pthread_attr_init(&pthread_custom_attr);
        p=(parm *)malloc(sizeof(parm)*n);
        
       /* Start up thread */
        for (int i=0; i<n; i++)
        {
                p[i].id=i;
                pthread_create(&threads[i], &pthread_custom_attr, hello, (void *)(p+i));
        }
        /* Synchronize the completion of each thread. */
        for (int i=0; i<n; i++)
                pthread_join(threads[i],NULL);
        free(p);
        return 0;
  
}

/*Exercise 04
Write a program that

Declares 2 functions, 1 and 2, where the identity of the thread that is executing is indicated.
function 1 sleeps 2 seconds and function 2 sleeps 5 seconds. -Next the main program must launch 2 threads, one for each function, write its own identity and terminate. -Write a new version where the parent waits for the children to finish before finishing.*/


void *func1 (){
  pthread_t tid = pthread_self(); /* thread identifier*/
  printf("I am thread 1 and I am going to execute func1 \n");
  sleep(2);
  printf("I am thread 1 and I have finished executing function 1\n");
  pthread_exit(NULL); /* Causes the termination of the thread*/
}

void *func2 (){
  pthread_t tid = pthread_self(); /* thread identifier*/
  printf("I am thread 2 and I am going to execute func2 \n");
  sleep(5);
  printf("I am thread 2 and I have finished executing function 2\n");
  pthread_exit(NULL); /* Causes the termination of the thread*/
}

int exercise04(){
  pthread_t thread1, thread2, thmain; /* threads declaration*/
  pthread_attr_t attr; /* threads atribute's declaration  */
  
 thmain = pthread_self();
  /*The main function itself is a thread*/

  /*initialize the parameters of the default threads*/
  pthread_attr_init (&attr);
  printf("I am the main function and I am going to launch the two threads \n");
  pthread_create (&thread1, &attr, func1, NULL);
  pthread_create (&thread2, &attr, func2, NULL);

  pthread_join(thread1,NULL);
  pthread_join(thread2,NULL);
  
  printf("I am main: I have launched the two threads and I finish\n");
  exit (0);
  
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

 int i;
  int addition=total_addition;
  addition = addition + 100;
  sleep(1);
  printf("Pthread =%d  wake up \n", (int)pthread_self());
  total_addition=addition;

}

 
int exercise05(){
pthread_t th[MAX_THREAD];
  int i;
  for (i=0;i<MAX_THREAD;i++) {
    pthread_create(&th[i], NULL,(void*)add, NULL);
  }
 
  for (i=0;i<MAX_THREAD;i++) {
    pthread_join(th[i], NULL);
  }
 
  printf("total addition = %d\n",
    total_addition);

  
}
