# 📚 QUIZ LAB STRUKTUR DATA

Nama : Bunga Lestari

NIM  : 251401023

Lab  : 3 

---

## 📝 Deskripsi Program

### 1. Pengelolaan Nilai Mahasiswa

Program ini digunakan untuk mengelola data mahasiswa berupa NIM, nama, dan nilai. Pengguna dapat menambahkan, melihat, mengurutkan, serta mencari data mahasiswa melalui menu yang tersedia.

**Implementasi program:**

- **Single Linked List:** Menyimpan data mahasiswa yang terdiri dari NIM, nama, dan nilai.
- **Dynamic Array:** Menyimpan salinan nilai mahasiswa untuk keperluan pengurutan dan pencarian.
- **Insertion Sort:** Mengurutkan nilai mahasiswa dari terkecil ke terbesar.
- **Linear Search:** Mencari data mahasiswa berdasarkan NIM.
- **Binary Search:** Mencari nilai tertentu pada array nilai yang sudah diurutkan.

### 2. Sistem Antrean dan Pengelolaan Buku Perpustakaan

Program ini digunakan untuk mengelola antrean mahasiswa, mencatat buku yang dikembalikan, serta menyimpan dan mencari ID buku.

**Implementasi program:**

- **Queue:** Menyimpan nama mahasiswa dalam antrean dan melayani mahasiswa berdasarkan urutan kedatangan (FIFO).
- **Stack:** Menyimpan judul buku yang dikembalikan. Buku terakhir yang dicatat menjadi data pertama yang diambil (LIFO).
- **Binary Search Tree (BST):** Menyimpan ID buku dan menyediakan fitur pencarian berdasarkan ID.
- **Tree Traversal:** Menampilkan data ID buku menggunakan metode Preorder, Inorder, dan Postorder.

### 3. Sistem Pencarian Rute Kampus

Program ini digunakan untuk mencari rute di lingkungan kampus (A–F) berdasarkan jarak yang telah ditentukan.

**Implementasi program:**

- **Graph:** Merepresentasikan hubungan antar lokasi kampus yang saling terhubung.
- **Adjacency Matrix:** Menyimpan hubungan dan bobot jarak antar lokasi.
- **Breadth-First Search (BFS):** Menelusuri lokasi secara melebar, dimulai dari titik yang dipilih pengguna.
- **Depth-First Search (DFS):** Menelusuri lokasi secara mendalam dari titik awal yang dipilih.
- **Dijkstra:** Menghitung jarak terpendek sekaligus menampilkan jalur dari titik awal ke titik tujuan.

### 4. Pengelolaan Data Mahasiswa Menggunakan Hash Table

Program ini digunakan untuk mengelola data mahasiswa berdasarkan NIM. Sebanyak 15 data mahasiswa telah disiapkan di dalam program untuk menguji proses penyimpanan, pencarian, dan penghapusan data.

**Implementasi program:**

- **Hash Table:** Menyimpan pasangan NIM dan nama mahasiswa dalam tabel berkapasitas 20 slot.
- **Hash Function:** Menentukan indeks penyimpanan menggunakan dua fungsi hashing.
- **Double Hashing:** Menentukan posisi alternatif ketika terjadi benturan indeks (*collision*).
- **Status Slot:** Menandai kondisi setiap slot sebagai EMPTY (kosong), atau DELETED (sudah dihapus).

Setelah data dimasukkan, program menampilkan isi Hash Table, melakukan pencarian NIM, menghapus data NIM, kemudian menampilkan kembali tabel untuk melihat hasil perubahan.

---

## 📂 Struktur Repository

Seluruh program disimpan dalam satu repository dengan file C++ yang terpisah untuk setiap soal.

```text
quiz-lab-struktur-data/
│
├── README.md
│
├── soal1.cpp
│
├── soal2.cpp
│
├── soal3.cpp
│
├── soal4.cpp
```

---
## 🎥 Video Penjelasan Program

Video ini berisi penjelasan mengenai kode, algoritma yang digunakan, serta demonstrasi hasil eksekusi dari setiap program.

🔗 **Link YouTube:**
https://youtu.be/USuJNHoPnm0?si=vLVwva66YlSAErpm

