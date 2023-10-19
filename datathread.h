#ifndef __DATATHREAD__
#define __DATATHREAD__



typedef struct _datathread
{
    struct _datathread * left;
    struct _datathread * right;
} datathread_t;

void
init_datathread(datathread_t *datathread);

void
datathread_add_next(datathread_t *datathread, graph_t *graph);


#endif
