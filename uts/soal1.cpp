#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk pasien hewan
struct Pasien {
    string nama;
    string jenis;
    int umur;
    int tingkatDarurat;
};

// Fungsi untuk menukar posisi dua pasien (digunakan saat sorting)
void swapPasien(Pasien &a, Pasien &b) {
    Pasien temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk mengurutkan pasien berdasarkan prioritas darurat
// Jika tingkat darurat lebih tinggi, maka berada di depan antrian
void urutkanPasien(Pasien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Tukar posisi jika pasien berikut lebih darurat
            if (arr[j].tingkatDarurat < arr[j + 1].tingkatDarurat) {
                swapPasien(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int jumlah;
    cout << "Masukkan jumlah pasien: ";
    cin >> jumlah;
    cin.ignore(); // membersihkan buffer newline

    // Buat array dinamis untuk daftar pasien
    Pasien *daftar = new Pasien[jumlah];

    // Input data pasien
    for (int i = 0; i < jumlah; i++) {
        cout << "\nPasien " << i + 1 << ":\n";
        cout << "Nama hewan: ";
        getline(cin, daftar[i].nama);
        cout << "Jenis hewan: ";
        getline(cin, daftar[i].jenis);
        cout << "Umur: ";
        cin >> daftar[i].umur;
        cout << "Tingkat darurat (1-5): ";
        cin >> daftar[i].tingkatDarurat;
        cin.ignore(); // bersihkan newline
    }

    // Urutkan pasien berdasarkan tingkat darurat (descending)
    urutkanPasien(daftar, jumlah);

    // Tampilkan urutan penanganan pasien
    cout << "\n=== Daftar Prioritas Penanganan ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". " << daftar[i].nama << " (" 
             << daftar[i].umur << " tahun) - Darurat "
             << daftar[i].tingkatDarurat << endl;
    }

    delete[] daftar; // hapus memori dinamis
    return 0;
}
