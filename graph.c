#include "lojistik.h"

Graph* init_graph() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->num_cities = 0;
    for (int i = 0; i < MAX_CITIES; i++) {
        g->adjacency_list[i] = NULL;
    }
    return g;
}

int add_city(Graph* g, char* city_name) {
    strcpy(g->city_names[g->num_cities], city_name);
    g->num_cities++;
    return g->num_cities - 1; // Eklenen şehrin indeksini döner
}

void add_edge(Graph* g, int src, int dest, int distance) {
    Edge* new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->target_city_index = dest;
    new_edge->distance = distance;
    new_edge->next = g->adjacency_list[src];
    g->adjacency_list[src] = new_edge;
    
    // Çift yönlü yol varsayımı
    Edge* new_edge_rev = (Edge*)malloc(sizeof(Edge));
    new_edge_rev->target_city_index = src;
    new_edge_rev->distance = distance;
    new_edge_rev->next = g->adjacency_list[dest];
    g->adjacency_list[dest] = new_edge_rev;
}

// DFS REKÜRSİF YARDIMCI FONKSİYONU
void dfs_util(Graph* g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf(" -> %s", g->city_names[vertex]);

    Edge* temp = g->adjacency_list[vertex];
    while (temp != NULL) {
        int connected_vertex = temp->target_city_index;
        if (!visited[connected_vertex]) {
            dfs_util(g, connected_vertex, visited);
        }
        temp = temp->next;
    }
}

// DFS (DERİNLİK ÖNCELİKLİ ARAMA) BAŞLATICISI
void dfs_traversal(Graph* g, int start_vertex) {
    bool visited[MAX_CITIES] = {false};
    printf("DFS Gezinme Rotasi: %s", g->city_names[start_vertex]);
    visited[start_vertex] = true;
    
    Edge* temp = g->adjacency_list[start_vertex];
    while (temp != NULL) {
        if (!visited[temp->target_city_index]) {
            dfs_util(g, temp->target_city_index, visited);
        }
        temp = temp->next;
    }
    printf("\n");
}