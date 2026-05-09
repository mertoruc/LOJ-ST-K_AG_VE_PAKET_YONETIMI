# Lojistik Ağı ve Paket Yönetim Sistemi 📦

Bu proje, C dili ile geliştirilmiş çok katmanlı bir lojistik rotalama ve paket yönetim sistemidir. Sistem; paketlerin bellekte hızlıca indekslenip bulunmasını sağlayan bir **Hash Tablosu (Hash Table)** ve şehirler arası kargo rotalarını analiz eden bir **Graf (Graph)** yapısını entegre bir şekilde kullanır.

## 🚀 Proje Özellikleri ve Algoritmalar

Bu sistem, belirli parametreler ve kısıtlamalar doğrultusunda optimize edilerek tasarlanmıştır:

* **Hash Fonksiyonu (Tip B - DJB2):** Metinsel paket ID'lerini benzersiz indekslere dönüştürmek için dünya çapında yaygın olarak kullanılan string tabanlı *DJB2 Hash Algoritması* kullanılmıştır. Arama zaman karmaşıklığı O(1)'dir.
* **Çakışma Yönetimi (Chaining):** Hash tablosunda aynı indekse düşen paketler, veri kaybını önlemek amacıyla *Zincirleme (Bağlı Liste / Linked List)* yöntemiyle bellekte dinamik olarak birbirine bağlanır.
* **Ağ Gezinmesi (DFS):** Türkiye haritası üzerindeki şehirler arası rotalar bir Graf yapısında tutulur. Belirli bir paketin hedef şehre ulaşması için geçmesi gereken optimum rotalar *Derinlik Öncelikli Arama (Depth First Search)* algoritması ile hesaplanır.

## 📁 Dosya Mimarisi

Proje, spagetti koddan kaçınmak ve sürdürülebilirliği artırmak adına modüler (çoklu dosya) yapıda tasarlanmıştır:

* `lojistik.h`: Projenin omurgasıdır. Graph, Hash Table, Package ve Edge struct yapılarını ve fonksiyon imzalarını barındırır.
* `hash.c`: Paketlerin sisteme eklenmesi, aranması ve DJB2 hash mantığının işlendiği katmandır.
* `graph.c`: Şehirlerin graf düğümleri olarak eklenmesi, mesafelerin tanımlanması ve DFS algoritmasının çalıştığı lojistik katmandır.
* `main.c`: Sistemin başlatıldığı, örnek verilerin yüklendiği ve hibrit test senaryosunun (paket bulma + rota çizme) yürütüldüğü ana programdır.

## 💻 Kurulum ve Çalıştırma

Projeyi yerel makinenizde çalıştırmak için bilgisayarınızda GCC derleyicisinin (MinGW vb.) kurulu olması gerekmektedir.

1. Repoyu bilgisayarınıza klonlayın.
2. Terminal (veya komut istemcisi) üzerinden projenin bulunduğu dizine gidin.
3. Tüm modülleri tek bir çalıştırılabilir dosya haline getirmek için aşağıdaki derleme komutunu çalıştırın:
   ```bash
   gcc main.c hash.c graph.c -o lojistik_sistemi
