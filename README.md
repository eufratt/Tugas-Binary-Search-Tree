
# Tugas Binary Search Tree

Program ini merupakan implementasi struktur data **Binary Search Tree (BST)** dalam bahasa **C++** untuk keperluan tugas kuliah. BST digunakan untuk menyimpan dan mencari data secara efisien berdasarkan kunci tertentu. 

## Deskripsi Singkat

BST adalah struktur data pohon biner yang setiap nilai simpul (node) pada subtree kiri selalu lebih kecil daripada nilai simpul induknya, dan setiap nilai di subtree kanan selalu lebih besar. BST mendukung operasi seperti **insert**, **search**, **traversal**, dan **delete** dengan kompleksitas rata-rata *O(log n)*. ([Wikipedia][1])

Program ini membaca data dari file (misal `dataMahasiswa.dat`) dan kemudian melakukan operasi BST seperti penambahan data dan pencarian. File utama kode adalah `TugasPTB_124240092.cpp`.

## Fitur Program

* **Membaca data mahasiswa** dari file eksternal
* **Menyisipkan (insert)** node ke dalam BST
* **Pencarian (search)** data dalam BST
* **Traversal BST** dalam urutan tertentu (inorder / preorder / postorder)
* **Menampilkan hasil pencarian** ke layar

## Struktur Folder

```
/
├─ TugasPTB_124240092.cpp        # Source C++ program utama
├─ dataMahasiswa.dat             # File data awal mahasiswa
└─ README.md                     # Penjelasan proyek
```

## Cara Menjalankan

1. **Clone** repository:

   ```
   git clone https://github.com/eufratt/Tugas-Binary-Search-Tree.git
   ```

2. **Masuk ke direktori** project:

   ```
   cd Tugas-Binary-Search-Tree
   ```

3. **Compile program** dengan g++ (atau compiler C++ lain):

   ```
   g++ TugasPTB_124240092.cpp -o bst_program
   ```

4. **Jalankan program**:

   ```
   ./bst_program
   ```

   Sesuaikan nama output dan path file `dataMahasiswa.dat` jika perlu.

## Contoh Penggunaan

Setelah menjalankan program:

1. Program akan memuat data dari file `dataMahasiswa.dat`.
2. Kamu bisa memilih menu untuk mencari data berdasarkan kunci tertentu.
3. Hasil pencarian BST ditampilkan di layar.

## Tentang Binary Search Tree

Binary Search Tree adalah struktur data berbasis pohon biner yang memungkinkan operasi pencarian, penyisipan, dan penghapusan dilakukan dengan relatif cepat jika pohon terjaga seimbang. Elemen kiri dari sebuah node selalu lebih kecil dari node tersebut, sedangkan elemen kanan selalu lebih besar. ([Wikipedia][1])

## License

Project ini bersifat open source dan dapat digunakan untuk **pembelajaran atau tugas kuliah**.


