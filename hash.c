#include "lojistik.h"

HashTable* init_hash_table() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < HASH_SIZE; i++) {
        ht->buckets[i] = NULL;
    }
    return ht;
}

// TİP B HASH FONKSİYONU: DJB2 Algoritması (String tabamlı mükemmel dağılım sağlar)
unsigned long hash_type_b(char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % HASH_SIZE;
}

// ZİNCİRLEME (CHAINING) İLE PAKET EKLEME
void insert_package(HashTable* ht, char* id, char* city, int weight) {
    unsigned long index = hash_type_b(id);
    
    Package* new_pkg = (Package*)malloc(sizeof(Package));
    strcpy(new_pkg->package_id, id);
    strcpy(new_pkg->destination_city, city);
    new_pkg->weight = weight;
    new_pkg->next = NULL;

    // Eğer o indekste eleman yoksa direkt ekle
    if (ht->buckets[index] == NULL) {
        ht->buckets[index] = new_pkg;
    } else {
        // ÇAKIŞMA (COLLISION) DURUMU: Linked List'in sonuna ekle (Zincirleme)
        Package* temp = ht->buckets[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_pkg;
    }
}

Package* search_package(HashTable* ht, char* id) {
    unsigned long index = hash_type_b(id);
    Package* temp = ht->buckets[index];
    
    while (temp != NULL) {
        if (strcmp(temp->package_id, id) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL; // Bulunamadı
}