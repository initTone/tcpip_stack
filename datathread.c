#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

void
init_datathread(datathread_t *datathread)
{
    datathread->graph = NULL;
    datathread->left = NULL;
    datathread->right = NULL;
}

void
datathread_add_next(datathread_t *datathread, graph_t *graph)
{
    if(!datathread->graph)
    {
        datathread->graph = graph;
        return;   
    }

	datathread_t *temp;
	temp->graph = datathread->graph;
	datathread->graph = graph;
	temp->left = datathread;
	datathread->right = temp;		
}
