#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 20;

class HashTable {
private:
    vector<pair<int, string>> table;
    vector<int> status;
    
    int hash1(int key) {
        return key % TABLE_SIZE;
    }

    int hash2(int key) {
        return 19 - (key % 19);
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
        status.resize(TABLE_SIZE, 0);
    }

    void insert(int key, string value) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;
        int deletedIndex = -1;

        while (true) {
            if (status[index] == 1 && table[index].first == key) {
                table[index].second = value;
                return;
            }
            if (status[index] == 2 && deletedIndex == -1) {
                deletedIndex = index;
            }
            if (status[index] == 0) {
                if (deletedIndex != -1) {
                    index = deletedIndex;
                }
                table[index] = make_pair(key, value);
                status[index] = 1;
                return;
            }
            index = (index + step) % TABLE_SIZE;
            if (index == initialIndex) {
                break;
            }
        }

        if (deletedIndex != -1) {
            table[deletedIndex] = make_pair(key, value);
            status[deletedIndex] = 1;
        } else {
            cout << "Table penuh" << endl;
        }
    }

    void search(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == key) {
                cout << "Data ditemukan : " << table[index].second << " (Indeks: " << index << ")" << endl;
                return;
            }
            index = (index + step) % TABLE_SIZE;
            if (index == initialIndex) {
                break;
            }
        }
        cout << "Data tidak ditemukan" << endl;
    }

    void remove(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == key) {
                status[index] = 2;
                cout << "Data berhasil dihapus" << endl;
                return;
            }
            index = (index + step) % TABLE_SIZE;
            if (index == initialIndex) {
                break;
            }
        }
        cout << "Data tidak ditemukan" << endl;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";
            if (status[i] == 1) {
                cout << table[i].first << " - " << table[i].second;
            } else if (status[i] == 2) {
                cout << "DELETED";
            } else {
                cout << "EMPTY";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(251401001, "Ando");
    ht.insert(251401023, "Bunga");   
    ht.insert(251401041, "Citra"); 
    
    ht.insert(251401002, "Deni");
    ht.insert(251401022, "Elis");

    ht.insert(251401003, "Friska");
    ht.insert(251401004, "Gani");
    ht.insert(251401005, "Heni");
    ht.insert(251401006, "Indah");
    ht.insert(251401007, "Jaya");
    ht.insert(251401008, "Kia");
    ht.insert(251401009, "Lani");
    ht.insert(251401010, "Meisrik");
    ht.insert(251401011, "Naya");
    ht.insert(251401012, "Ona");

    cout << "Tampilan Awal Hash Table (15 Data): " << endl;
    ht.display();
    cout << endl;

    cout << "Uji Search" << endl;
    cout << "Mencari NIM 251401041 (Citra): " << endl;
    ht.search(251401041);
    cout << endl;
    
    cout << "Uji Remove: " << endl;
    cout << "Menghapus NIM 251401023 (Bunga): " << endl;
    ht.remove(251401023);
    cout << endl;

    cout << "Hash Table Setelah Penghapusan: " << endl;
    ht.display();

    return 0;
}