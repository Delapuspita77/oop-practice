#include <iostream>
#include <string> 
#include <vector> //Library untuk penggunaan struktur data vektor
#include <ctime> //Library untuk mendapatkan wakstu secara real time
#include <algorithm> // Library untuk transformasi huruf dan operasi lain pada koleksi data

using namespace std;

// Mendeklarasi kelas Barang
class Barang {
private:
    string nama;
    int stok;

public:
    Barang(string nama, int stok) : nama(nama), stok(stok) {}

    string getNama() const {
        return nama;
    }

    int getStok() const {
        return stok;
    }

    void tambahStok(int jumlah) {
        stok += jumlah;
    }

    void kurangiStok(int jumlah) {
        if (stok >= jumlah) {
            stok -= jumlah;
        } else {
            cout << "Stok tidak mencukupi untuk pengurangan." << endl;
        }
    }
};

// Mendeklarasi kelas Gudang
class Gudang {
private:
    vector<Barang> daftarBarang;
    vector<pair<time_t, string>> riwayatPerubahan;

public:
    void tambahBarang(const Barang& barang) {
    // Periksa apakah barang sudah ada di dalam daftarBarang
    string namaBarangLower = barang.getNama();
    transform(namaBarangLower.begin(), namaBarangLower.end(), namaBarangLower.begin(), ::tolower);
    for (auto& item : daftarBarang) {
        string itemNamaLower = item.getNama();
        transform(itemNamaLower.begin(), itemNamaLower.end(), itemNamaLower.begin(), ::tolower);
        if (itemNamaLower == namaBarangLower) {
            item.tambahStok(barang.getStok()); // Tambah jumlah stok barang jika sudah ada
            cout << "Stok barang " << item.getNama() << " bertambah sebanyak " << barang.getStok() << endl;
            catatPerubahan(item.getNama(), barang.getStok(), "penambahan stok sebanyak"); // Catat perubahan stok
            return;
        }
    }
    // Jika barang belum ada, tambahkan barang ke dalam daftarBarang
    daftarBarang.push_back(barang);
    cout << "Barang " << barang.getNama() << " berhasil ditambahkan ke gudang." << endl;
    catatPerubahan(barang.getNama(), barang.getStok(), "penambahan stok sebanyak"); // Catat perubahan saat barang ditambahkan
    }

    void tambahStok(const string& namaBarang, int jumlah) {
        string namaBarangLower = namaBarang;
        transform(namaBarangLower.begin(), namaBarangLower.end(), namaBarangLower.begin(), ::tolower);
        for (auto& barang : daftarBarang) {
            string itemNamaLower = barang.getNama();
            transform(itemNamaLower.begin(), itemNamaLower.end(), itemNamaLower.begin(), ::tolower);
            if (itemNamaLower == namaBarangLower) {
                barang.tambahStok(jumlah); // Menambah stok barang yang sudah ada
                catatPerubahan(barang.getNama(), jumlah, "penambahan stok sebanyak"); // Catat perubahan stok
                cout << "Stok barang " << barang.getNama() << " bertambah sebanyak " << jumlah << endl;
                return;
            }
        }
        cout << "Barang " << namaBarang << " belum ditemukan di gudang. Silakan taambah barang terlebih dahulu." << endl;
    }

    void kurangiStok(const string& namaBarang, int jumlah) {
        string namaBarangLower = namaBarang;
        transform(namaBarangLower.begin(), namaBarangLower.end(), namaBarangLower.begin(), ::tolower);
        for (auto& barang : daftarBarang) {
            string itemNamaLower = barang.getNama();
            transform(itemNamaLower.begin(), itemNamaLower.end(), itemNamaLower.begin(), ::tolower);
            if (itemNamaLower == namaBarangLower) {
                barang.kurangiStok(jumlah);
                catatPerubahan(barang.getNama(), jumlah, "pengurangan stok sebanyak");
                cout << "Stok barang " << barang.getNama() << " berkurang sebanyak " << jumlah << endl;
                return;
            }
        }
        cout << "Barang " << namaBarang << " tidak ditemukan di gudang." << endl;
    }

    void tampilkanStok() const {
        cout << "Stok Barang di Gudang:" << endl;
        for (const auto& barang : daftarBarang) {
            cout << "Nama Barang: " << barang.getNama() << ", Jumlah: " << barang.getStok() << endl;
        }
    }

    void catatPerubahan(const string& namaBarang, int jumlah, const string& tipePerubahan) {
            time_t now = time(0);
            tm* localTime = localtime(&now);
            char buffer[80];
            strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localTime);
            string waktu(buffer);

            riwayatPerubahan.push_back({now, "Waktu: " + waktu + ", Barang: " + namaBarang + ", " + tipePerubahan + " " + to_string(jumlah)});
    }

    void tampilkanRiwayatPerubahan() const {
        cout << "Riwayat Perubahan Stok Barang:" << endl;
        for (const auto& perubahan : riwayatPerubahan) {
            cout << perubahan.second << endl;
        }
    }
};

int main() {
    Gudang gudang;

    // Menambahkan beberapa barang awal ke gudang
    gudang.tambahBarang(Barang("Tisu", 50));
    gudang.tambahBarang(Barang("Mie Instan", 100));

    int pilihan;
    string namaBarang;
    int jumlah;

    cout << "======================================\n";
    cout << "Ini adalah program sistem pergudangan!\n";
    cout << "Silakan coba masukkan barang apapun!\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah barang\n";
        cout << "2. Tambah stok barang\n";
        cout << "3. Kurangi stok barang\n";
        cout << "4. Tampilkan stok barang\n";
        cout << "5. Tampilkan riwayat perubahan\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama barang: ";
                cin.ignore(); // Membersihkan karakter newline (\n) yang masih ada di buffer
                getline(cin, namaBarang); // Membaca keseluruhan baris, termasuk spasi
                cout << "Masukkan jumlah barang yang akan ditambahkan: ";
                cin >> jumlah;
                gudang.tambahBarang(Barang(namaBarang, jumlah));
                break;
            case 2:
                cout << "Masukkan nama barang: ";
                cin.ignore();
                getline(cin, namaBarang);
                cout << "Masukkan jumlah barang yang akan ditambahkan: ";
                cin >> jumlah;
                gudang.tambahStok(namaBarang, jumlah);
                break;
            case 3:
                cout << "Masukkan nama barang: ";
                cin.ignore();
                getline(cin, namaBarang);
                cout << "Masukkan jumlah barang yang akan dikurangi: ";
                cin >> jumlah;
                gudang.kurangiStok(namaBarang, jumlah);
                break;
            case 4:
                gudang.tampilkanStok();
                break;
            case 5:
                gudang.tampilkanRiwayatPerubahan();
                break;
            case 6:
                cout << "Terima Kasih.\n";
                break;
            default:
                cout << "Error.\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}
