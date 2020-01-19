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

void delete_connected_edges (vertex_list_t *vertex_list, int idx)
{
    vertex_t *vertex = &vertex_list->vertex[idx];

    while ((vertex->no_edges > 0) &&
           vertex_list->vertex[vertex->edge[0].from].connected &&
           vertex_list->vertex[vertex->edge[0].to].connected) {

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

void init_graph (vertex_list_t *vertex_list)
{
    for (int i = 1; i <= vertex_list->no_vertices; i++) {
        heapify_vertex(&vertex_list->vertex[i]);
        vertex_list->vertex[i].connected = 0;
    }
}

edge_t find_starting_minimum_edge (vertex_list_t *vertex_list)
{
    edge_t min = {MAX_INT, 0, 0};
    int no_vertices = vertex_list->no_vertices;
    vertex_t *vertex = vertex_list->vertex;

    for (int i = 1; i <= no_vertices; i++) {
        if ((vertex[i].no_edges > 0) && vertex[i].edge[0].cost < min.cost) {
            min = vertex[i].edge[0];
        }
    }

    //printf("First minimum edge %d (%d, %d)\n", min.cost, min.from, min.to);
    vertex[min.from].connected = 1;
    vertex[min.to].connected = 1;

    delete_connected_edges(vertex_list, min.from);
    delete_connected_edges(vertex_list, min.to);

    return min;
}

edge_t find_next_connected_minimum (vertex_list_t *vertex_list)
{
    edge_t min = {MAX_INT, 0, 0};
    int no_vertices = vertex_list->no_vertices;
    vertex_t *vertex = vertex_list->vertex;

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

    delete_connected_edges(vertex_list, min.from);
    delete_connected_edges(vertex_list, min.to);

    return min;
}

void prims_minimum_spanning_tree (vertex_list_t *vertex_list)
{
    init_graph(vertex_list);

	printf("Prim's Minimum Cost Spanning Tree...\n");
    edge_t min = find_starting_minimum_edge(vertex_list);
    printf("%d (%d, %d)\n", min.cost, min.from, min.to);

    for (int i = 2; i < vertex_list->no_vertices; i++) {
        min = find_next_connected_minimum(vertex_list);
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
    vertex_list_t vertex_list = read_graph(argv[1]);

    prims_minimum_spanning_tree(&vertex_list);

    return 0;
}
