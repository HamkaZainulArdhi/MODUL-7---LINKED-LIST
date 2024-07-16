#include <iostream>
using namespace std;

struct melist {
    string data;
    melist* next;
};

melist *head;
melist *tail;
melist *simpul_baru;

void inisialisasi() {
    head = NULL;
    tail = NULL;
}

bool list_kosong() {
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
}

void buat_simpul(string dataMasukkan) {
    simpul_baru = new melist;
    simpul_baru->data = dataMasukkan;
    simpul_baru->next = NULL;
}

void tambah_belakang(string data_user) {
    buat_simpul(data_user);
    if (list_kosong() == true) {
        head = simpul_baru;
        tail = simpul_baru;
        simpul_baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = simpul_baru;
        simpul_baru->next = head;
    }
}

void tambah_depan(string data_user) {
    buat_simpul(data_user);
    if (list_kosong() == true) {
        head = simpul_baru;
        tail = simpul_baru;
        simpul_baru->next = head;
    } else {
        simpul_baru->next = head;
        head = simpul_baru;
        tail->next = simpul_baru;
    }
}

void hapus_belakang() {
    if (list_kosong() == true) {
        cout << "Tidak ada data" << endl;
    } else {
        melist *helper;
        helper = head;
        tail = head;
        if (helper->next == head) {
            head = NULL;
            tail = NULL;
            delete helper;
        } else {
            while (helper->next != head) {
                helper = helper->next;
            }
            while (tail->next != helper) {
                tail = tail->next;
            }
            tail->next = head;
            helper->next = NULL;
            delete helper;
        }
    }
}

void hapus_depan() {
    if (list_kosong() == true) {
        cout << "Tidak ada data" << endl;
    } else {
        melist *helper;
        helper = head;
        tail = head;
        if (helper->next == head) {
            head = NULL;
            tail = NULL;
            delete helper;
        } else {
            while (tail->next != helper) {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            helper->next = NULL;
            delete helper;
        }
    }
}

void tampil_list() {
    if (list_kosong() == true) {
        cout << "Tidak ada data" << endl;
    } else {
        tail = head;
        do {
            cout << tail->data << " ";
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    }
}

int main() {
    int pilih;
    string data_user;
    bool lanjut = true;
    do {
        cout << endl;
        cout << "MENU" <<endl;
        cout << "1. tambah_belakang" <<endl;
        cout << "2. tambah_depan" <<endl;
        cout << "3. hapus_belakang" <<endl;
        cout << "4. hapus_depan" <<endl;
        cout << "5. tampilkan list" <<endl;
        cout << "6. keluar" <<endl;
        cout << "pilih : ";
        cin >> pilih ;
        cout <<endl;

        switch (pilih) {

            case 1:
            cout << "tambah_belakang : " ; 
            cin >> data_user;
            tambah_belakang(data_user);
            break;

            case 2:
            cout << "tambah_depan : " ; 
            cin >> data_user;
            tambah_depan(data_user);
            break;

            case 3:
            hapus_belakang();
            cout << "data belakang telah terhapus" << endl;
            break;

            case 4:
            hapus_depan();
            cout << "data depan telah terhapus" << endl;
            break;
            
            case 5:
            cout << "daftar list" <<endl;
            tampil_list();
            break;
            
            case 6:
            cout << "terima kasih " ; 
            lanjut = false;
            break;


        } 
    } while (lanjut);

    }