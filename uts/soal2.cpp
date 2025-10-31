#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk menyimpan data film
struct Film {
    string judul;
    int tahun;
    int rating;
    Film* next; // pointer ke film berikutnya
};

// Fungsi untuk membuat node film baru
Film* buatFilm(string judul, int tahun, int rating) {
    Film* baru = new Film;
    baru->judul = judul;
    baru->tahun = tahun;
    baru->rating = rating;
    baru->next = NULL;
    return baru;
}

// Fungsi untuk menambah film ke akhir linked list
void tambahFilm(Film*& head, string judul, int tahun, int rating) {
    Film* baru = buatFilm(judul, tahun, rating);
    if (head == NULL) {
        head = baru;
    } else {
        Film* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

// Fungsi untuk menghapus film berdasarkan judul
void hapusFilm(Film*& head, string judul) {
    if (head == NULL) {
        cout << "Daftar film kosong.\n";
        return;
    }

    Film* temp = head;
    Film* prev = NULL;

    // mencari node yang judulnya sesuai
    while (temp != NULL && temp->judul != judul) {
        prev = temp;
        temp = temp->next;
    }

    // jika tidak ditemukan
    if (temp == NULL) {
        cout << "Film tidak ditemukan.\n";
        return;
    }

    // jika film dihapus ada di awal list
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp; // hapus node dari memori
}

// Fungsi untuk menampilkan semua film
void tampilkanFilm(Film* head) {
    Film* temp = head;
    while (temp != NULL) {
        cout << temp->judul << " (" << temp->tahun << ") - " << temp->rating << endl;
        temp = temp->next;
    }
}

// Fungsi untuk menghitung jumlah film tersisa
int hitungFilm(Film* head) {
    int count = 0;
    Film* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Film* head = NULL;
    int n;
    cout << "Masukkan jumlah film awal: ";
    cin >> n;
    cin.ignore(); // membersihkan newline di buffer

    // input data film awal
    for (int i = 0; i < n; i++) {
        string judul;
        int tahun, rating;

        cout << "\nFilm " << i + 1 << ":\n";
        cout << "Judul: ";
        getline(cin, judul);
        cout << "Tahun: ";
        cin >> tahun;
        cout << "Rating: ";
        cin >> rating;
        cin.ignore();

        tambahFilm(head, judul, tahun, rating);
    }

    char hapus;
    cout << "\nApakah ingin menghapus film? (y/n): ";
    cin >> hapus;
    cin.ignore();

    if (hapus == 'y' || hapus == 'Y') {
        string judulHapus;
        cout << "Masukkan judul film yang sudah ditonton: ";
        getline(cin, judulHapus);
        hapusFilm(head, judulHapus);
    }

    // Output sesuai contoh
    cout << "\nContoh Keluaran :\n";
    tampilkanFilm(head);
    cout << "\nTotal film tersisa: " << hitungFilm(head) << endl;

    return 0;
}