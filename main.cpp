#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct Anggota {
    int id;
    string nama;
    string alamat;
};


struct Buku {
    int id;
    string judul;
    string pengarang;
    int denda;
};


struct Peminjaman {
    int idAnggota;
    vector<int> idBuku;
    int lamaPinjam;
};


vector<Anggota> dataAnggota;
vector<Buku> dataBuku;
vector<Peminjaman> dataPeminjaman;


vector<Anggota> tambahAnggota(vector<Anggota> dataAnggota) {
    int id;
    string nama, alamat;


    for (int i = 1; i < 4; i++) {
        cout << "ID Anggota: ";
        cin >> id;
        cout << "Nama: ";
        cin.ignore();
        getline(cin, nama);
        cout << "Alamat: ";
        getline(cin, alamat);
        dataAnggota.push_back({id, nama, alamat});
        cout << endl;
    }

    return dataAnggota;
}


vector<Buku> tambahBuku(vector<Buku> dataBuku) {
    int id, denda;
    string judul, pengarang;


    for (int i = 1; i < 4; i++) {
        cout << "ID Buku: ";
        cin >> id;
        cout << "Judul: ";
        cin.ignore();
        getline(cin, judul);
        cout << "Pengarang: ";
        getline(cin, pengarang);
        cout << "Denda per hari keterlambatan: ";
        cin >> denda;
        dataBuku.push_back({id, judul, pengarang, denda});
        cout << endl;
    }

    return dataBuku;
}


vector<Peminjaman> peminjaman(vector<Peminjaman> dataPeminjaman) {
    int idAnggota, idBuku, lamaPinjam;
    cout << "ID Anggota: ";
    cin >> idAnggota;
    cout << endl;

    vector<int> bukuDipinjam;


    for (int i = 1; i < 4; i++) {
        cout << "ID Buku yang dipinjam: ";
        cin >> idBuku;
        bukuDipinjam.push_back(idBuku);
        cout << endl;
    }

    cout << "Lama Pinjam (hari): " ;
    cin >> lamaPinjam;
    cout << endl;

    dataPeminjaman.push_back({idAnggota, bukuDipinjam, lamaPinjam});
    return dataPeminjaman;
}
int hitungDenda(int lamaPinjam, int dendaPerBuku) {
    int denda = 0;
    int terlambat = lamaPinjam - 7;

    if (terlambat > 0) {
        if (terlambat <= 5) {
            denda = terlambat * dendaPerBuku;
        } else if (terlambat <= 8) {
            denda = terlambat * 4000;
        } else if (terlambat <= 10) {
            denda = terlambat * 55000;
        } else {
            denda = terlambat * 75000;
        }
    }
    return denda;
}
string laporan() {
    string hasil = "Laporan Anggota dan Buku";
    hasil += "Data Anggota: \n";
    for (auto anggota : dataAnggota) {
        hasil += "ID: " + to_string(anggota.id) + ", Nama: " + anggota.nama + ", Alamat: " + anggota.alamat + "\n ";
    }
    hasil += "Data Buku:";
    for (auto buku : dataBuku) {
        hasil += "ID: " + to_string(buku.id) + ", Judul: " + buku.judul + ", Pengarang: " + buku.pengarang + ", Denda: " + to_string(buku.denda) + "\n";
    }
    hasil += "Data Peminjaman:";
    for (auto pinjam : dataPeminjaman) {
        hasil += "ID Anggota: " + to_string(pinjam.idAnggota) + ", Lama Pinjam: " + to_string(pinjam.lamaPinjam) + " hari";
        for (int idBuku : pinjam.idBuku) {
            auto it = find_if(dataBuku.begin(), dataBuku.end(), [idBuku](Buku b) { return b.id == idBuku; });
            if (it != dataBuku.end()) {
                hasil += "  Buku: " + it->judul + ", Denda Keterlambatan: " + to_string(hitungDenda(pinjam.lamaPinjam, it->denda)) + " per buku";
            }
        }
    }

    return hasil;
}

int main() {
    int pilihan;

    while (true) {
        cout <<"===================="<< endl;
        cout << "Menu Pilihan:"<< endl;
        cout <<"===================="<< endl;
        cout <<" Aditya Eka Narayan "<< endl;
        cout <<"   A11.2024.15940   "<< endl;
        cout <<"        4110        "<< endl;
        cout <<"===================="<< endl;
        cout << "1. Anggota"<< endl;
        cout << "2. Data Buku"<< endl;
        cout << "3. Peminjaman"<< endl;
        cout << "4. Laporan"<< endl;
        cout << "5. Keluar"<< endl;
        cout <<"===================="<< endl;
        cout << "Pilih [1-5]: ";
        cin >> pilihan;
        cout << endl;

        if (pilihan == 1) {
            dataAnggota = tambahAnggota(dataAnggota);
        } else if (pilihan == 2) {
            dataBuku = tambahBuku(dataBuku);
        } else if (pilihan == 3) {
            dataPeminjaman = peminjaman(dataPeminjaman);
        } else if (pilihan == 4) {
            cout << laporan() << endl;
        } else if (pilihan == 5) {
            cout <<"===================="<< endl;
            cout << "Terima kasih" << endl;
            cout <<"===================="<< endl;
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
    return 0;
}
