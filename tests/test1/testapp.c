#include "graph.h"
#include <stdio.h>

extern graph_t *build_first_topo();

int main(int argc, char * argv[])
{
    graph_t *topo = build_first_topo();

	dump_graph(topo);

	node_t * node = get_node_by_node_name(topo, "R1_re");

	printf("Find Node ------- %s\n", node->node_name);

    return 0;
}
