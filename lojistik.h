#ifndef LOJISTIK_H
#define LOJISTIK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_SIZE 10
#define MAX_CITIES 20

/* ================= HASH TABLE (PAKET YÖNETİMİ) ================= */
// Paket Düğümü (Çakışmalarda Zincirleme / Chaining için Linked List yapısı)
typedef struct Package {
    char package_id[20];
    char destination_city[50];
    int weight;
    struct Package* next; // Zincirleme pointer'ı
} Package;

// Hash Table Yapısı
typedef struct HashTable {
    Package* buckets[HASH_SIZE];
} HashTable;

/* ================= GRAF (ŞEHİR YOL YÖNETİMİ) ================= */
// Yol/Kenar Yapısı
typedef struct Edge {
    int target_city_index;
    int distance;
    struct Edge* next;
} Edge;

// Graf Yapısı
typedef struct Graph {
    char city_names[MAX_CITIES][50];
    Edge* adjacency_list[MAX_CITIES];
    int num_cities;
} Graph;

/* Fonksiyon Prototipleri */
HashTable* init_hash_table();
unsigned long hash_type_b(char* str); // Tip B Hash Fonksiyonu
void insert_package(HashTable* ht, char* id, char* city, int weight);
Package* search_package(HashTable* ht, char* id);

Graph* init_graph();
int add_city(Graph* g, char* city_name);
void add_edge(Graph* g, int src, int dest, int distance);
void dfs_traversal(Graph* g, int start_vertex);

#endif