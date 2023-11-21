#include "graph.h"
#include "net.h"
#include <stdlib.h>
#include <stdio.h>

graph_t * create_new_graph(char * name)
{
  graph_t * graph = (graph_t*) malloc(sizeof(graph_t));

  strncpy(graph->topology_name, name, TOPO_NAME_SIZE);

  graph->topology_name[TOPO_NAME_SIZE - 1] = '\0';

  init_thread(&graph->node_list);

  return graph;
}
    
node_t * create_graph_node(graph_t * graph, char * name)
{
  node_t * node = (node_t*) malloc(sizeof(node_t));

  strncpy(node->node_name, name, NODE_NAME_SIZE);

  node->node_name[NODE_NAME_SIZE - 1] = '\0';

  init_thread(&node->list);

  init_node_prop(&node->node_props);

  thread_add_next(&graph->node_list, &node->list);

  return node;
}
    
void insert_link_between_two_nodes(node_t * node1, node_t * node2, char * name1, char * name2, int cost)
{
  link_t * link = (link_t*) malloc(sizeof(link_t));

  strncpy(link->intf1.intf_name, name1, INTF_NAME_SIZE);

  link->intf1.intf_name[INTF_NAME_SIZE - 1] = '\0';

  strncpy(link->intf2.intf_name, name2, INTF_NAME_SIZE);

  link->intf2.intf_name[INTF_NAME_SIZE - 1] = '\0';

  link->intf1.link = link;

  link->intf2.link = link;

  link->intf1.att_node = node1;

  link->intf2.att_node = node2;

  init_intf_prop(&link->intf1.intf_props);

  init_intf_prop(&link->intf2.intf_props);

  intf_assign_mac_address(&link->intf1);

  intf_assign_mac_address(&link->intf2);

  link->cost = cost;

  int empty_intf_slot;

  empty_intf_slot = get_node_intf_available_slot(node1);

  node1->intf[empty_intf_slot] = &link->intf1;

  empty_intf_slot = get_node_intf_available_slot(node2);

  node2->intf[empty_intf_slot] = &link->intf2;
    
}

void dump_graph(graph_t * graph)
{
  printf("*************************\n");

  printf("-------------------------\n");

  printf(" ---- %s\n", graph->topology_name);

  printf("-------------------------\n");

  printf("*************************\n\n");

  thread_t * thread;
  thread_t * end;

  thread = &graph->node_list;
  end = &graph->node_list;

  thread = get_base(thread);

  thread_t * current;

  current = thread;

  for(; current != end; current = thread)
  {
      dump_node(node_from_thread(current));
      thread = thread->right;
  }
     
}

void dump_node(node_t* node)
{
  printf("-------------------------\n");

  printf(" -Node %s\n", node->node_name);

  printf("-------------------------\n");

  for(int i = 0; node->intf[i] != NULL; i++)
  {
      dump_intf(node->intf[i]);
  }
}

void dump_intf(interface_t * intf)
{
  printf(" --Interface %s\n", intf->intf_name);

  printf("Mac address = %s\n", intf->intf_props.mac_addr.mac);

  printf(" --Link\n");

  printf("Cost = %i\n\n", intf->link->cost);
}
