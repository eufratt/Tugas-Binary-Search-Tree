#include <iostream>
#include <cstring>
using namespace std;

struct treeMahasiswa
{
    char nama[50];
    int nim;
    bool akar;
    treeMahasiswa* next;
    treeMahasiswa* prev;
};

struct dataMahasiswa {
    char nama[50];
    int nim;
    bool akar;
};


treeMahasiswa *root = nullptr, *bantu = NULL; 
FILE *file, *fileBaru;
void tambah();
void simpankeFile(treeMahasiswa *baru);
void cetakInOrder(treeMahasiswa *node);
void bacaDariFile();
void insertKeTree(treeMahasiswa* baru);
void hapusTree(treeMahasiswa* node);
void cariMahasiswa();
void hapusMahasiswa();
void simpanTreeRekursif(treeMahasiswa* node);

int main(){
    int menu;
    do{
        system("cls");
        cout << "Menu" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Cari Mahasiswa" << endl;
        cout << "3. Cetak Isi Pohon (InOrder Traversal)" << endl;
        cout << "4. Hapus Mahasiswa" << endl;
        cout << "5. Keluar Program" << endl;
        cout << "Pilih Menu : "; cin >> menu;
        switch (menu)
        {
        case 1:
            tambah();
            break;
        case 2:
            cariMahasiswa();
            break;
        case 3:
            bacaDariFile();
            cout << "Data Mahasiswa (InOrder Traversal):\n";
            cout << "-----------------------------------\n";
            cetakInOrder(root);
            system("pause");
            break;
        case 4:
            hapusMahasiswa();
            break;
        case 5:
            return 0;
        default:
            cout << "Pilihan tidak valid"<< endl;
            system("pause");
            break;
        }
    } while (menu != 5);
    

    return 0; 
}

void tambah(){
    treeMahasiswa* baru = new treeMahasiswa();
    cin.ignore();
    cout << "Masukkan Nama Mahasiswa : "; cin.getline(baru->nama, 50);
    cout << "Masukkan NIM Mahasiswa  : "; cin >> baru->nim;
    baru->next = nullptr;
    baru->prev = nullptr;
    if (root == nullptr)
    {
        root = baru;
        baru->akar = true;
        simpankeFile(baru);
        return;
    }
    bantu = root;
    while (true)
    {
        if (baru->nim < bantu->nim)
        {
            if (bantu->prev == nullptr)
            {
                bantu->prev = baru;
                simpankeFile(baru);
                return;
            }
            bantu = bantu->prev;
        }else if (baru->nim > bantu->nim)
        {
            if (bantu->next == nullptr)
            {
                bantu->next = baru;
                simpankeFile(baru);
                return;
            }
            bantu= bantu->next;
        }else{
            cout << "Nim sudah ada"<< endl;
            delete baru;
            system("pause");
            return;
        }
    }
}

void simpankeFile(treeMahasiswa *baru){
    file = fopen("dataMahasiswa.dat", "ab");
    if (file != nullptr) {
        dataMahasiswa data;
        strcpy(data.nama, baru->nama);
        data.nim = baru->nim;
        data.akar = baru->akar;
        fwrite(&data, sizeof(dataMahasiswa), 1, file); 
        fclose(file);
        cout << "Data dengan NIM " << baru->nim << " berhasil ditambahkan" << endl;
        system("pause");
    } else {
        cout << "Gagal membuka file.\n";
    }
}

void cetakInOrder(treeMahasiswa *node){
    if (node == nullptr) {
        return;
    }
    cetakInOrder(node->prev);
    cout << "Nama : " << node->nama << endl;
    cout << "NIM  : " << node->nim << endl;
    cout << "-------------------------" << endl;
    cetakInOrder(node->next); 
}

void bacaDariFile() {
    hapusTree(root);
    root = nullptr;
    file = fopen("dataMahasiswa.dat", "rb");
    if (file != nullptr) {
        dataMahasiswa temp;
        treeMahasiswa* listNode[100];
        int count = 0;
        treeMahasiswa* calonRoot = nullptr;

        while (fread(&temp, sizeof(dataMahasiswa), 1, file) == 1) {
            treeMahasiswa* baru = new treeMahasiswa;
            strcpy(baru->nama, temp.nama);
            baru->nim = temp.nim;
            baru->akar = temp.akar;
            baru->next = nullptr;
            baru->prev = nullptr;
            if (baru->akar)
            {
                calonRoot = baru;
            }
            listNode[count++] = baru;
        }
        fclose(file);

        if (calonRoot != nullptr) {
            root = calonRoot;
            cout << "Root: " << root->nama << endl; //cek apakah root keganti pas baca file
            for (int i = 0; i < count; ++i) {
                if (listNode[i] != calonRoot) {
                    insertKeTree(listNode[i]);
                }
            }
        }
    } else {
        cout << "File tidak ditemukan atau belum ada data.\n";
    }
}

void insertKeTree(treeMahasiswa* baru) {
    if (root == nullptr) {
        root = baru;
        return;
    }

    treeMahasiswa* bantu = root;
    while (true) {
        if (baru->nim < bantu->nim) {
            if (bantu->prev == nullptr) {
                bantu->prev = baru;
                return;
            }
            bantu = bantu->prev;
        } else if (baru->nim > bantu->nim) {
            if (bantu->next == nullptr) {
                bantu->next = baru;
                return;
            }
            bantu = bantu->next;
        } else {
            delete baru;
            return;
        }
    }
}

void hapusTree(treeMahasiswa* node) {
    if (node == nullptr) return;
    hapusTree(node->prev);
    hapusTree(node->next);
    delete node;
}


void cariMahasiswa() {
    int cariNIM;
    cout << "Masukkan NIM yang dicari: ";
    cin >> cariNIM;

    bacaDariFile();

    treeMahasiswa* hasil = root;
    while (hasil != nullptr) {
        if (cariNIM == hasil->nim) {
            cout << "Data ditemukan:\n";
            cout << "Nama : " << hasil->nama << endl;
            cout << "NIM  : " << hasil->nim << endl;
            system("pause");
            return;
        } else if (cariNIM < hasil->nim) {
            hasil = hasil->prev;
        } else {
            hasil = hasil->next;
        }
    }

    cout << "Data dengan NIM " << cariNIM << " tidak ditemukan.\n";
    system("pause");
}


void hapusMahasiswa() {
    int hapusNIM;
    cout << "Masukkan NIM yang ingin dihapus: ";
    cin >> hapusNIM;

    bacaDariFile();  // Load tree dari file

    treeMahasiswa* parent = nullptr;
    treeMahasiswa* current = root;

    // Cari node yang ingin dihapus
    while (current != nullptr && current->nim != hapusNIM) {
        parent = current;
        if (hapusNIM < current->nim)
            current = current->prev;
        else
            current = current->next;
    }

    if (current == nullptr) {
        cout << "Data dengan NIM tersebut tidak ditemukan.\n";
        system("pause");
        return;
    }

    // Kasus: dua anak
    if (current->prev != nullptr && current->next != nullptr) {
        treeMahasiswa* succParent = current;
        treeMahasiswa* succ = current->next;
        while (succ->prev != nullptr) {
            succParent = succ;
            succ = succ->prev;
        }

        // Copy data successor ke current
        strcpy(current->nama, succ->nama);
        current->nim = succ->nim;

        // Hapus successor
        if (succParent->prev == succ)
            succParent->prev = succ->next;
        else
            succParent->next = succ->next;

        delete succ;
    }
    // Kasus: 0 atau 1 anak
    else {
        treeMahasiswa* child = (current->prev != nullptr) ? current->prev : current->next;

        if (parent == nullptr)
            root = child;  // Jika hapus root
        else if (parent->prev == current)
            parent->prev = child;
        else
            parent->next = child;

        delete current;
    }

    // Simpan ulang seluruh pohon ke file
    fileBaru = fopen("dataMahasiswa.dat", "wb");
    if (fileBaru == nullptr) {
        cout << "Gagal membuka file untuk menyimpan ulang.\n";
        return;
    }

    simpanTreeRekursif(root);

    fclose(fileBaru);
    cout << "Data berhasil disimpan ulang ke file.\n";

    system("pause");
}

void simpanTreeRekursif(treeMahasiswa* node) {
    if (node == nullptr) return;

    simpanTreeRekursif(node->prev);

    dataMahasiswa data;
    strcpy(data.nama, node->nama);
    data.nim = node->nim;
    data.akar = (node == root);  // hanya true untuk root
    fwrite(&data, sizeof(dataMahasiswa), 1, fileBaru);

    simpanTreeRekursif(node->next);
}