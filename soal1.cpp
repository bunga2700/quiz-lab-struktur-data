#include <iostream>
#include <string>
using namespace std;

struct Mhs {
    string nim, nama;
    int nilai;
    Mhs* next;
};

void tambahMahasiswa(Mhs*& head, Mhs*& tail, string nim, string nama, int nilai) {
    Mhs* baru = new Mhs();
    baru->nim = nim;
    baru->nama = nama;
    baru->nilai = nilai;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
        tail = baru;
    } else { 
        tail->next = baru;
        tail = baru;
    }
}

void updateArray(Mhs* head, int*& arrNilai, int n) {
    delete[] arrNilai;
    arrNilai = new int[n];
    Mhs* temp = head;
    for (int i = 0; i < n; i++) { 
        arrNilai[i] = temp->nilai; 
        temp = temp->next; 
    }
}

void insertionSort(int arrNilai[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arrNilai[i], j = i - 1;
        while (j >= 0 && arrNilai[j] > key) { 
            arrNilai[j + 1] = arrNilai[j]; 
            j--; 
        }
        arrNilai[j + 1] = key;
    }
}

Mhs* linearSearch(Mhs* head, string target) {
    Mhs* temp = head;
    while (temp != nullptr) {
        if (temp->nim == target) return temp;
        temp = temp->next;
    }
    return nullptr;
}

int binarySearch(int arrNilai[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arrNilai[mid] == target) {
            return mid;
        } else if (target < arrNilai[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

void tampilkanMenu() {
    cout << endl;
    cout << "===== SISTEM PENGELOLAAN NILAI MAHASISWA =====" << endl;
    cout << "1. Tambah Data Mahasiswa" << endl;
    cout << "2. Tampilkan Data Mahasiswa" << endl;
    cout << "3. Urutkan Nilai (Insertion Sort)" << endl;
    cout << "4. Cari Mahasiswa berdasarkan NIM (Linear Search)" << endl;
    cout << "5. Cari Nilai (Binary Search)" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main() {
    Mhs* head = nullptr;
    Mhs* tail = nullptr;
    int* arrNilai = nullptr;
    int n = 0;
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1: {
                string nim, nama;
                int nilai;
                cout << "Masukkan NIM : ";
                cin >> nim;
                
                cin.ignore();
                cout << "Masukkan Nama  : ";
                getline(cin, nama);

                cout << "Masukkan Nilai : ";
                cin >> nilai;

                if (nilai < 0 || nilai > 100) {
                    cout << "Nilai harus antara 0-100!" << endl;
                    break;
                }

                tambahMahasiswa(head, tail, nim, nama, nilai);
                n++;
                updateArray(head, arrNilai, n);
                cout << "Data berhasil ditambahkan." << endl;
                break;
            }
            case 2: {
                Mhs* temp = head;
                if (temp == nullptr) {
                    cout << "Belum ada data mahasiswa." << endl;
                } else {
                    cout << "Daftar Mahasiswa :" << endl;
                    while (temp != nullptr) {
                        cout << "- " << temp->nim << " | " << temp->nama << " => " << temp->nilai << endl;
                        temp = temp->next;
                    }
                }
                break;
            }
            case 3: {
                if (n > 0) {
                    insertionSort(arrNilai, n);
                    cout << "Nilai berhasil diurutkan: ";
                    for (int i = 0; i < n; i++) {
                        cout << arrNilai[i] << " ";
                    }
                    cout << endl;
                } else {
                    cout << "Belum ada data untuk diurutkan." << endl;
                }
                break;
            }
            case 4: {
                string targetNIM;
                cout << "Masukkan NIM yang dicari: ";
                cin >> targetNIM;
                
                Mhs* hasil = linearSearch(head, targetNIM);
                if (hasil != nullptr) {
                    cout << "Ditemukan: " << hasil->nama << " (Nilai: " << hasil->nilai << ")" << endl;
                } else {
                    cout << "NIM tidak ditemukan." << endl;
                }
                break;
            }
            case 5: {
                int targetNilai;
                cout << "Masukkan Nilai yang dicari: ";
                cin >> targetNilai;
                
                int hasil = binarySearch(arrNilai, n, targetNilai);
                if (hasil != -1) {
                    cout << "Nilai " << targetNilai << " ditemukan pada indeks array ke-" << hasil << endl;
                    
                    Mhs* temp = head;
                    while (temp != nullptr) {
                        if (temp->nilai == targetNilai) {
                            cout << "- " << temp->nama << " (NIM: " << temp->nim << ")" << endl;
                        }
                        temp = temp->next;
                    }
                } else {
                    cout << "Nilai " << targetNilai << " tidak ditemukan." << endl;
                }
                break;
            }
            case 0:
                cout << "Program selesai. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    delete[] arrNilai;
    
    while (head != nullptr) {
        Mhs* hapus = head;
        head = head->next;
        delete hapus;
    }
    
    return 0;
}