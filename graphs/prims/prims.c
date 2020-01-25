#include "graph.h"

// Prim's algorithm to find Minimum Spanning Tree for a given graph
// Maintain a heap of edges by cost per vertex
// Starting from first minimum edge across all edges
// Scan next minimum edge that is connected to the already selected vertices
// and not forming a cycle

void heapify (edge_t array[], int idx, int n)
{
    int l_idx, r_idx;
    int min_idx;
    edge_t min;

    while (1) {
        l_idx = 2 * idx + 1;
        r_idx = 2 * idx + 2;

        if ((r_idx < n) && (array[r_idx].cost < array[l_idx].cost)) {
            min = array[r_idx];
            min_idx = r_idx;
        } else if (l_idx < n) {
            min = array[l_idx];
            min_idx = l_idx;
        } else {
            break;
        }
        if (min.cost < array[idx].cost) {
            array[min_idx] = array[idx];
            array[idx] = min;
            idx = min_idx;
        } else {
            break;
        }
    }
}

void delete_connected_edges (graph_t *graph, int idx)
{
    vertex_t *vertex = &graph->vertex[idx];

    while ((vertex->no_edges > 0) &&
           graph->vertex[vertex->edge[0].from].connected &&
           graph->vertex[vertex->edge[0].to].connected) {

        vertex->edge[0] = vertex->edge[vertex->no_edges - 1];
        vertex->no_edges--;
        heapify(vertex->edge, 0, vertex->no_edges);
    }
}

void heapify_vertex (vertex_t *vertex)
{
    int n = vertex->no_edges;

    for (int i = (n - 2)/2; i >= 0; i--) {
        heapify(vertex->edge, i, n);
    }
}

void init_graph (graph_t *graph)
{
	/* For all vertices:
	 * Arrange their edges in min heap by cost
	 */
    for (int i = 1; i <= graph->no_vertices; i++) {
        heapify_vertex(&graph->vertex[i]);
        graph->vertex[i].connected = 0;
    }
}

edge_t find_starting_minimum_edge (graph_t *graph)
{
    edge_t min = {MAX_INT, 0, 0};
    int no_vertices = graph->no_vertices;
    vertex_t *vertex = graph->vertex;

	/* Find least cost edge from all vertices */
    for (int i = 1; i <= no_vertices; i++) {
        if ((vertex[i].no_edges > 0) && vertex[i].edge[0].cost < min.cost) {
            min = vertex[i].edge[0];
        }
    }

    //printf("First minimum edge %d (%d, %d)\n", min.cost, min.from, min.to);
    vertex[min.from].connected = 1;
    vertex[min.to].connected = 1;

    delete_connected_edges(graph, min.from);
    delete_connected_edges(graph, min.to);

    return min;
}

edge_t find_next_connected_minimum (graph_t *graph)
{
    edge_t min = {MAX_INT, 0, 0};
    int no_vertices = graph->no_vertices;
    vertex_t *vertex = graph->vertex;

	/* Find least cost connected edge from all vertices */
    for (int i = 1; i <= no_vertices; i++) {
        if ((vertex[i].no_edges > 0) && (vertex[i].edge[0].cost < min.cost)) {
            int from_connected = vertex[vertex[i].edge[0].from].connected;
            int to_connected = vertex[vertex[i].edge[0].to].connected;
            if (from_connected ^ to_connected) {
                min = vertex[i].edge[0];
            }
        }
    }

    //printf("Next minimum (connected) edge %d (%d, %d)\n", min.cost, min.from, min.to);
    vertex[min.from].connected = 1;
    vertex[min.to].connected = 1;

    delete_connected_edges(graph, min.from);
    delete_connected_edges(graph, min.to);

    return min;
}

void prims_minimum_spanning_tree (graph_t *graph)
{
    init_graph(graph);

	printf("Prim's Minimum Cost Spanning Tree...\n");
    edge_t min = find_starting_minimum_edge(graph);
    printf("%d (%d, %d)\n", min.cost, min.from, min.to);

    for (int i = 2; i < graph->no_vertices; i++) {
        min = find_next_connected_minimum(graph);
        printf("%d (%d, %d)\n", min.cost, min.from, min.to);
    }
}

int main (int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <graph_file_path>\n", argv[0]);
        exit(1);
    }

	printf("Reading graph from file: %s\n", argv[1]);
    graph_t graph = read_graph(argv[1]);

    prims_minimum_spanning_tree(&graph);

    return 0;
}
