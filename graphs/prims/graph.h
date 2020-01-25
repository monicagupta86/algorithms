#include <stdio.h>
#include <stdlib.h>

#define MAX_INT 0x7fffffff

typedef struct edge_ {
	int cost;
	int from;
 	int to;
} edge_t;

typedef struct vertex_ {
	edge_t *edge;
	int no_edges;
	int connected;
} vertex_t;

typedef struct graph_ {
	vertex_t *vertex;
	int no_vertices;
} graph_t;

graph_t read_graph(char *filename);
