#include "graph.h"

extern graph_t *build_first_topo();

/*void
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
}*/

/*node_t * create_graph_node(graph_t * graph, char * name)
{

    node_t* node = (node_t*) malloc(sizeof(node_t));

    strncpy(node->node_name, name, NODE_NAME_SIZE);

    node->node_name[NODE_NAME_SIZE - 1] = '\0';

    init_nlthread(&node->graph_list);	

    nlthread_add_next(&graph->node_list, node);

    glthread_add_next(&node->graph_list, graph);

    return node;
}*/

int main(int argc, char * argv[])
{
    graph_t *topo = build_first_topo();

	nlthread_t *thread;

	thread = &topo->node_list;

	printf("%s\n", thread->node);

	printf("%s\n", thread->right->node->node_name);

	//dump_graph(topo);
	/*
	graph_t *topo = create_new_graph("Hello New Graph");
    
    node_t  *R0_re = create_graph_node(topo, "R0_re");

	node_t  *R1_re = create_graph_node(topo, "R1_re");

	node_t  *R2_re = create_graph_node(topo, "R2_re");
	*/
    return 0;
}
