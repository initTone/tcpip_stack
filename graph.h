#ifndef __GRAPH__
#define __GRAPH__

#include "datathread.h"

#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define NODE_NAME_SIZE 16
#define INTF_NAME_SIZE 16
#define TOPO_NAME_SIZE 16
#define MAX_INTF_PER_NODE 10

typedef struct link_ link_t;

typedef struct node_ node_t;

typedef struct interface_
{
    char intf_name[INTF_NAME_SIZE];
    struct node_ *att_node;
    struct link_ *link;
} interface_t;

struct link_
{
    interface_t intf1;
    interface_t intf2;
    unsigned int cost;
};

struct node_
{
    char node_name[NODE_NAME_SIZE];
    interface_t *intf[MAX_INTF_PER_NODE];
    datathread_t graph_list;   
};

struct graph_
{
    char topology_name[TOPO_NAME_SIZE];
    datathread_t node_list;
} graph_t;

static inline node_t*
get_nbr_node(interface_t *intf)
{
    assert(intf->att_node);
    assert(intf->link);

    link_t* link = intf->link;
    if(&link->intf1 == intf)
        return link->intf2.att_node;
    else
        return link->intf1.att_node;
};

static inline int
get_node_intf_available_slot(node_t* node)
{
    for(int i = 0; i < MAX_INTF_PER_NODE; i++)
    {
        if(node->intf[i])
            continue;
        return i;
    }
    return -1;
};

static inline interface_t*
get_node_intf_by_name(node_t * node, char * name)
{
    for(int i = 0; i < MAX_INTF_PER_NODE; i++)
    {
        if(strcmp(node->intf[i]->intf_name, name))
            return node->intf[i];
    }
    return NULL;
};

/*
static inline node_t *
get_node_by_node_name(graph_t *topo, char *node_name)
{
      
}
*/
/*----------------------------------------------------Graph API------------------------------------------------*/

void dump_graph(graph_t * graph);

void dump_node(node_t * node);

void dump_intf(interface_t * intf);

graph_t * create_new_graph(char * name);
    
node_t  * create_graph_node(graph_t * graph, char * name);
    
void insert_link_between_two_nodes(node_t * node1, node_t * node2, char * name1, char * name2, int cost);


#endif
