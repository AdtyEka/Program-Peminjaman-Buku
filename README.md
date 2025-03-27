# Program Manajemen Perpustakaan

## Deskripsi
Program ini merupakan sistem manajemen perpustakaan sederhana yang memungkinkan pengguna untuk:
- Menambahkan data anggota perpustakaan
- Menambahkan data buku
- Melakukan peminjaman buku
- Menampilkan laporan data anggota, buku, dan peminjaman

## Cara Menggunakan
1. **Jalankan program**
   - Kompilasi kode dengan menggunakan compiler C++
   - Contoh perintah kompilasi: `g++ -o perpustakaan perpustakaan.cpp`
   - Jalankan program: `./perpustakaan`

2. **Pilih menu yang tersedia**
   - 1: Menambahkan anggota baru
   - 2: Menambahkan data buku
   - 3: Melakukan peminjaman buku
   - 4: Menampilkan laporan
   - 5: Keluar dari program

## Struktur Data
Program ini menggunakan struktur data berikut:
- `struct Anggota`: Menyimpan ID, nama, dan alamat anggota.
- `struct Buku`: Menyimpan ID, judul, pengarang, dan denda per hari keterlambatan.
- `struct Peminjaman`: Menyimpan ID anggota, daftar ID buku yang dipinjam, dan lama pinjam dalam hari.

## Fungsi Utama
- `tambahAnggota()`: Menambahkan anggota baru ke dalam daftar.
- `tambahBuku()`: Menambahkan buku baru ke dalam daftar.
- `peminjaman()`: Mencatat peminjaman buku oleh anggota.
- `hitungDenda()`: Menghitung denda berdasarkan lama pinjam.
- `laporan()`: Menampilkan data anggota, buku, dan peminjaman.

## Aturan Denda
- Jika keterlambatan hingga 5 hari: denda per hari sesuai dengan buku.
- Jika keterlambatan 6-8 hari: denda 4000 per hari.
- Jika keterlambatan 9-10 hari: denda 55000 per hari.
- Jika keterlambatan lebih dari 10 hari: denda 75000 per hari.

## Kontributor
Program ini dibuat oleh:
- **Aditya Eka Narayan**
- **NIM: A11.2024.15940**
- **Kelas: 4110**

## Lisensi
Program ini bersifat open-source dan dapat digunakan serta dimodifikasi sesuai kebutuhan.

---
Terima kasih telah menggunakan program ini!

