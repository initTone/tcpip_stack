#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

void
init_glthread(glthread_t *glthread)
{
    glthread->graph = NULL;
    glthread->left = NULL;
    glthread->right = NULL;
}

void
init_nlthread(nlthread_t *nlthread)
{
    nlthread->node = NULL;
    nlthread->left = NULL;
    nlthread->right = NULL;
}


void
glthread_add_next(glthread_t *glthread, graph_t *graph)
{
    if(!glthread->graph)
    {
        glthread->graph = graph;
        return;   
    }

	glthread_t *temp;
	temp->graph = glthread->graph;
	glthread->graph = graph;
	temp->left = glthread;
	glthread->right = temp;		
}

void
nlthread_add_next(nlthread_t *nlthread, node_t *node)
{

    if(!nlthread->node)
    {
        nlthread->node = node;
        return;   
    }

	nlthread_t *temp;
	temp->node = nlthread->node;
	nlthread->node = node;
	temp->left = nlthread;
	nlthread->right = temp;
	
}
