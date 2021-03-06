#include "graph.h"

graph_t read_graph(char *filename)
{
    FILE *fptr;
    size_t len;
    char *line;
    graph_t graph;

    if ((fptr = fopen(filename, "r")) == NULL) {
        printf("Error: Opening file: %s\n", filename);
        exit(1);
    }

    if (getline(&line, &len, fptr) == -1) {
        printf("Error: Unexpected end of file encountered while reading number of vertices\n");
        exit(1);
    } else if (1 != sscanf(line, "%d", &graph.no_vertices)) {
        printf("Error: Parse failed while reading number of vertices\n");
        exit(1);
    } else if (graph.no_vertices <= 0) {
        printf("Error: Unexpected number of vertices: %d\n", graph.no_vertices);
        exit(1);
    }

    graph.vertex = (vertex_t *)malloc(sizeof(vertex_t) * (graph.no_vertices + 1));
    if (!graph.vertex) {
        printf("Error allocating vertex memory\n");
        fclose(fptr);
        exit(1);
    }

    for (int i = 1; i <= graph.no_vertices; i++) {
        vertex_t *vertex = &graph.vertex[i];
        if (getline(&line, &len, fptr) == -1) {
            printf("Error: Unexpected end of file encountered while reading number of edges for vertex %d\n", i);
            exit(1);
        } else if (1 != sscanf(line, "%d", &vertex->no_edges)) {
            printf("Error: Parse failed while reading number of edges for vertex %d\n", i);
            exit(1);
        } else if (vertex->no_edges <= 0) {
            printf("Error: Unexpected number of edges (%d) for vertex: %d\n",
                   vertex->no_edges, i);
            exit(1);
        }

        vertex->edge = (edge_t *)malloc(sizeof(edge_t) * (vertex->no_edges));
        if (!vertex->edge) {
            printf("Error allocating edge memory for vertex %d\n", i);
            fclose(fptr);
            exit(1);
        }
        
        for (int j = 0; j < vertex->no_edges; j++) {
            if (getline(&line, &len, fptr) == -1) {
                printf("Error: Unexpected end of file encountered while reading edge %d on vertex %d\n",
                       j + 1, i);
                exit(1);
            } else if (2 != sscanf(line, "%d %d", &vertex->edge[j].to, &vertex->edge[j].cost)) {
                printf("Error: Parse failed while reading edge %d on vertex %d\n", j + 1, i);
                exit(1);
            } else if ((vertex->edge[j].to < 1) || (vertex->edge[j].to > graph.no_vertices)) {
                printf("Error: Invalid to edge %d for edge (%d) on vertex: %d\n",
                       vertex->edge[j].to, j + 1, i);
                exit(1);
            }
            vertex->edge[j].from = i;
        }
    }

    return graph;
}
