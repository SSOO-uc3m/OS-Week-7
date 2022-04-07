#ifndef WEEK_07_H    
#define WEEK_07_H   

#define MAX_THREAD 10

typedef struct {
        int id;
} parm;

void * thread_function (void *arg);

int exercise01();

void * print_dots(void *arg);

int exercise02();

void *hello(void *arg);

int exercise03();

void *func1 ();

void *func2 ();

int exercise04();

void * add (void *arg) ;
 
int exercise05();

#endif /* WEEK_07_H */