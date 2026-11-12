#include <iostream>
#include <string>
using namespace std;

struct NodeQ {
    string nama;
    NodeQ* next;
};

struct NodeS {
    string judulBuku;
    NodeS* next;
};

struct NodeBST {
    int id;
    NodeBST* left;
    NodeBST* right;
};

void enqueue(NodeQ*& front, NodeQ*& rear, string nama) {
    NodeQ* baru = new NodeQ();
    baru->nama = nama;
    baru->next = nullptr;
    if (rear == nullptr) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
}

void dequeue(NodeQ*& front, NodeQ*& rear) {
    if (front == nullptr) {
        cout << "Antrean kosong!" << endl;
        return;
    }
    NodeQ* hapus = front;
    cout << "Mahasiswa yang dilayani: " << front->nama << endl;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete hapus;
}

void tampilkanQueue(NodeQ* front) {
    NodeQ* temp = front;
    if (temp == nullptr) { 
        cout << "Antrean kosong." << endl;
        return;
    }
    cout << "Isi Antrean Peminjaman: ";
    while (temp != nullptr) {
        cout << temp->nama;
        if (temp->next != nullptr){
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void push(NodeS*& top, string buku) {
    NodeS* baru = new NodeS();
    baru->judulBuku = buku;
    baru->next = top;
    top = baru;
}

void pop(NodeS*& top) {
    if (top == nullptr) {
        cout << "Riwayat kosong!" << endl;
        return;
    }
    NodeS* hapus = top;
    cout << "Buku terakhir dikembalikan: " << top->judulBuku << endl;
    top = top->next;
    delete hapus;
}

void tampilkanStack(NodeS* top) {
    NodeS* temp = top;
    if (temp == nullptr) { 
        cout << "Riwayat kosong." << endl;
        return;
    }
    cout << "Riwayat Pengembalian:" << endl;
    while (temp != nullptr) {
        cout << "- " << temp->judulBuku << endl;
        temp = temp->next;
    }
}

void insertBST(NodeBST*& node, int id) {
    if (node == nullptr) {
        node = new NodeBST();
        node->id = id;
        node->left = nullptr;
        node->right = nullptr;
        return;
    }
    if (id < node->id) {
        insertBST(node->left, id);
    } else {
        insertBST(node->right, id);
    }
}

void searchBST(NodeBST* root, int target) {
    NodeBST* temp = root;
    while (temp != nullptr) {
        if (target == temp->id) {
            cout << "ID Buku " << target << " DITEMUKAN!" << endl;
            return;
        } else if (target < temp->id) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    cout << "ID Buku " << target << " TIDAK DITEMUKAN." << endl;
}

void preOrder(NodeBST* node) {
    if (node != nullptr) {
        cout << node->id << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(NodeBST* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->id << " ";
        inOrder(node->right);
    }
}

void postOrder(NodeBST* node) {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->id << " ";
    }
}

void tampilkanMenu() {
    cout << endl;
    cout << "===== SISTEM PERPUSTAKAAN =====" << endl;
    cout << "1. Tambah Antrean Peminjaman (Queue)" << endl;
    cout << "2. Proses Peminjaman (Dequeue)" << endl;
    cout << "3. Catat Pengembalian Buku (Stack)" << endl;
    cout << "4. Tambah ID Buku (Insert BST)" << endl;
    cout << "5. Cari ID Buku (Search BST)" << endl;
    cout << "6. Tampilkan Traversal BST" << endl;
    cout << "7. Lihat Antrean & Riwayat" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main() {
    NodeQ *front = nullptr, *rear = nullptr;
    NodeS* topStack = nullptr;
    NodeBST* root = nullptr;
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1: {
                string nama;
                cout << "Masukkan Nama Mahasiswa: ";
                cin >> nama;
                enqueue(front, rear, nama);
                cout << nama << " berhasil masuk antrean." << endl;
                break;
            }
            case 2:
                dequeue(front, rear);
                break;
            case 3: {
                string buku;
                cout << "Masukkan Judul Buku yang dikembalikan: ";
                cin >> buku;
                push(topStack, buku);
                cout << buku << " berhasil dicatat di riwayat." << endl;
                break;
            }
            case 4: {
                int id;
                cout << "Masukkan ID Buku: ";
                cin >> id;
                insertBST(root, id);
                cout << "ID Buku " << id << " berhasil ditambahkan." << endl;
                break;
            }
            case 5: {
                int id;
                cout << "Masukkan ID Buku yang dicari: ";
                cin >> id;
                searchBST(root, id);
                break;
            }
            case 6: {
                if (root == nullptr) {
                    cout << "Belum ada data buku." << endl;
                    break;
                }
                cout << "Pre-Order  : "; preOrder(root); cout << endl;
                cout << "In-Order   : "; inOrder(root); cout << "(Terurut)" << endl;
                cout << "Post-Order : "; postOrder(root); cout << endl;
                break;
            }
            case 7:
                tampilkanQueue(front);
                tampilkanStack(topStack);
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);  
    return 0;
}