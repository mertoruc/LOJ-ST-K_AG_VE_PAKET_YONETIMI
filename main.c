#include "lojistik.h"

int main() {
    printf("==========================================\n");
    printf(" Lojistik Agi ve Paket Yonetim Sistemi\n");
    printf("==========================================\n\n");

    // 1. GRAF SİSTEMİNİ KURMA
    Graph* turkey_map = init_graph();
    int ist = add_city(turkey_map, "Istanbul");
    int ank = add_city(turkey_map, "Ankara");
    int izm = add_city(turkey_map, "Izmir");
    int bur = add_city(turkey_map, "Bursa");
    int ant = add_city(turkey_map, "Antalya");

    // Şehirler arası yolları ekle (Mesafe km)
    add_edge(turkey_map, ist, ank, 450);
    add_edge(turkey_map, ist, bur, 150);
    add_edge(turkey_map, bur, izm, 330);
    add_edge(turkey_map, ank, ant, 480);
    add_edge(turkey_map, izm, ant, 460);

    // 2. HASH TABLE (PAKET) SİSTEMİNİ KURMA
    HashTable* package_db = init_hash_table();
    
    // Paket girişleri
    insert_package(package_db, "PKG771", "Ankara", 15);
    insert_package(package_db, "PKG772", "Izmir", 5);
    insert_package(package_db, "PKG773", "Antalya", 30);
    insert_package(package_db, "PKG774", "Bursa", 10);
    insert_package(package_db, "PKG775", "Istanbul", 22);

    // 3. HİBRİT ÇALIŞTIRMA (ÖNCE PAKET BUL, SONRA ROTAYI ÇİZ)
    char search_id[] = "PKG773";
    printf("[SORGULAMA] %s numarali paket araniyor...\n", search_id);
    Package* found = search_package(package_db, search_id);

    if (found != NULL) {
        printf("Paket Bulundu! Hedef: %s | Agirlik: %d kg\n\n", found->destination_city, found->weight);
        
        printf("[ROTA HESAPLAMA] Istanbul merkezden DFS ile rota cikariliyor...\n");
        // DFS her zaman Istanbul'dan (0) başlasın
        dfs_traversal(turkey_map, 0); 
    } else {
        printf("Paket sistemde bulunamadi!\n");
    }

    return 0;
}