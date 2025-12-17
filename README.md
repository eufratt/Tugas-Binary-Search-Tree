
# Tugas Binary Search Tree Mahasiswa

Program ini merupakan implementasi **Binary Search Tree (BST)** menggunakan bahasa **C++** untuk mengelola data mahasiswa.
Data mahasiswa disimpan secara permanen dalam file biner `dataMahasiswa.dat` dan dapat dibaca kembali untuk membangun ulang BST.

BST disusun berdasarkan **NIM** sebagai key utama.

## Deskripsi Program

Program menyediakan menu untuk:

* Menambah data mahasiswa
* Mencari mahasiswa berdasarkan NIM
* Menampilkan seluruh data mahasiswa menggunakan InOrder Traversal
* Menghapus data mahasiswa
* Menyimpan ulang data BST ke file

Setiap kali program membaca data, BST akan direkonstruksi dari file agar data tetap konsisten.

## Struktur Data

### Struct treeMahasiswa

Digunakan sebagai node pada Binary Search Tree.

* nama
* nim
* akar
* prev (anak kiri)
* next (anak kanan)

### Struct dataMahasiswa

Digunakan untuk penyimpanan data ke file biner.

* nama
* nim
* akar

## Fitur Program

### 1. Tambah Mahasiswa

* Input nama dan NIM
* Data dimasukkan ke BST berdasarkan NIM
* Data langsung disimpan ke file

### 2. Cari Mahasiswa

* Pencarian berdasarkan NIM
* Menggunakan mekanisme pencarian BST

### 3. Cetak Isi Pohon

* Menampilkan seluruh data mahasiswa
* Menggunakan InOrder Traversal (kiri - root - kanan)

### 4. Hapus Mahasiswa

* Menghapus node BST berdasarkan NIM
* Menangani kasus:

  * Node tanpa anak
  * Node dengan satu anak
  * Node dengan dua anak
* Setelah penghapusan, file ditulis ulang dari BST terbaru

## Algoritma yang Digunakan

* Binary Search Tree
* InOrder Traversal
* File handling (fread dan fwrite)
* Rekonstruksi BST dari file

## Struktur Folder

```
/
├─ TugasPTB_124240092.cpp
├─ dataMahasiswa.dat
└─ README.md
```

## Cara Menjalankan Program

1. Compile program:

   ```
   g++ TugasPTB_124240092.cpp -o bst_mahasiswa
   ```

2. Jalankan program:

   ```
   ./bst_mahasiswa
   ```

Catatan:
Program menggunakan `system("cls")` dan `system("pause")` sehingga disarankan dijalankan di Windows.

## Tujuan Pembelajaran

* Memahami konsep Binary Search Tree
* Mengimplementasikan insert, search, traversal, dan delete
* Menggabungkan BST dengan penyimpanan file
* Melatih penggunaan pointer dan manajemen memori

## License

Program ini dibuat untuk keperluan **pembelajaran dan tugas kuliah**.

