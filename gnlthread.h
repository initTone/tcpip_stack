#ifndef __GNTHREAD__
#define __GNTHREAD__

#include "thread_defs.h"

typedef struct _nlthread
{
    node_t          * node;
    struct _nlthread *left;
    struct _nlthread *right;
} nlthread_t;

typedef struct _glthread
{
    graph_t         * graph;
    struct _glthread *left;
    struct _glthread *right;
} glthread_t;

void
init_glthread(glthread_t *glthread);

void
init_nlthread(nlthread_t *nlthread);

void
glthread_add_next(glthread_t *glthread, graph_t *graph);

void
nlthread_add_next(nlthread_t *nlthread, node_t *node);


#endif /* __GLUETHREAD__ */
