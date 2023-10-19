#include "graph.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

graph_t * create_new_graph(char * name)
{
    graph_t* graph = (graph_t*) malloc(sizeof(graph_t));
    
    strncpy(graph->topology_name, name, TOPO_NAME_SIZE);

    graph->topology_name[TOPO_NAME_SIZE - 1] = '\0';

    init_glthread(&graph->node_list);

    return graph;
}
    
node_t * create_graph_node(graph_t * graph, char * name)
{

    node_t* node = (node_t*) malloc(sizeof(node_t));

    strncpy(node->node_name, name, NODE_NAME_SIZE);

    node->node_name[NODE_NAME_SIZE - 1] = '\0';

    init_nlthread(&node->graph_list);	

    nlthread_add_next(&graph->node_list, node);

    glthread_add_next(&node->graph_list, graph);

    return node;
}
    
void insert_link_between_two_nodes(node_t * node1, node_t * node2, char * name1, char * name2, int cost)
{
    link_t* link = (link_t*) malloc(sizeof(link_t));

    strncpy(link->intf1.intf_name, name1, INTF_NAME_SIZE);

    link->intf1.intf_name[INTF_NAME_SIZE - 1] = '\0';

    strncpy(link->intf2.intf_name, name2, INTF_NAME_SIZE);

    link->intf2.intf_name[INTF_NAME_SIZE - 1] = '\0';

    link->intf1.link = link;

    link->intf2.link = link;

    link->intf1.att_node = node1;

    link->intf2.att_node = node2;

    link->cost = cost;

    int empty_intf_slot;

    empty_intf_slot = get_node_intf_available_slot(node1);

    node1->intf[empty_intf_slot] = &link->intf1;

    empty_intf_slot = get_node_intf_available_slot(node2);

    node2->intf[empty_intf_slot] = &link->intf2;
    
}

void dump_graph(graph_t * graph)
{

    printf("Topology Name = %s\n", graph->topology_name);

    nlthread_t *thread = &graph->node_list;

    nlthread_t *current = thread;

    for(int i = 0; i < 2; i++)
    {
        dump_node(thread->node);
		thread = thread->right;
    }
     
}

void dump_node(node_t* node)
{
    printf("Node Name = %s\n", node->node_name);

	/*interface_t *intf;

    for(int i = 0; i < MAX_INTF_PER_NODE; i++)
    {
		intf = &node->intf[i];
        dump_intf(intf);
    }
	*/
}

void dump_intf(interface_t * intf)
{
    printf("Interace Name = %s\n", intf->intf_name);

    printf("Link cost = %i\n", intf->link->cost);    
}
