#include <iostream> 

using namespace std;

class Segitiga {
private:
    float alas;
    float tinggi;
public:
    Segitiga(float a, float t) : alas(a), tinggi(t) {} 
    float luas() { 
        return (alas * tinggi) / 2; 
    }
    float getAlas() { 
        return alas;
    }
    float getTinggi() { 
        return tinggi;
    }
};

class Persegipanjang {
private:
    float panjang;
    float lebar;
public:
    Persegipanjang(float p, float l) : panjang(p), lebar(l) {} 
    float luas() { 
        return panjang * lebar; 
    }
    float getPanjang() { 
        return panjang;
    }
    float getLebar() { 
        return lebar;
    }
};

class Prisma {
private:
    Segitiga alasSegitiga;
    Persegipanjang alasPrisma;
    float tinggiPrisma;
public:
    Prisma(float a, float t, float p) : alasSegitiga(a, t), alasPrisma(p, a), tinggiPrisma(p) {} 
    float volume() { 
        return alasSegitiga.luas() * tinggiPrisma; 
    }
};

int main() {
    float alasSegitiga, tinggiSegitiga, panjangPersegi;
    cout << "Masukkan alas segitiga: ";
    cin >> alasSegitiga;
    cout << "Masukkan tinggi segitiga: ";
    cin >> tinggiSegitiga;
    cout << "Masukkan panjang persegi panjang (juga sebagai tinggi prisma): ";
    cin >> panjangPersegi;

    Prisma prisma(alasSegitiga, tinggiSegitiga, panjangPersegi);

    cout << "Volume Prisma Segitiga = " << prisma.volume() << endl;

    return 0;
}

/*Public: Anggota kelas yang dideklarasikan sebagai public dapat diakses dari luar kelas. Ini berarti bahwa anggota tersebut dapat diakses dan dimodifikasi dari mana saja di program. Misalnya, dalam kode yang Anda berikan, fungsi luas() dalam kelas Segitiga dan Persegipanjang dideklarasikan sebagai public, sehingga dapat dipanggil dari dalam Prisma atau dari fungsi main().

Private: Anggota kelas yang dideklarasikan sebagai private hanya dapat diakses oleh anggota lain dari kelas yang sama. Ini berarti bahwa anggota tersebut tidak dapat diakses atau dimodifikasi dari luar kelas. Misalnya, dalam kode yang Anda berikan, variabel alas dan tinggi dalam kelas Segitiga serta variabel panjang dan lebar dalam kelas Persegipanjang dideklarasikan sebagai private, sehingga hanya dapat diakses dari dalam kelas masing-masing.


Fungsi get yang Anda lihat dalam kode tersebut adalah metode akses atau metode getter yang digunakan untuk mengakses nilai variabel pribadi (private) dari suatu kelas dari luar kelas tersebut. Ini merupakan praktik yang baik dalam paradigma pemrograman berorientasi objek (OOP) karena menerapkan konsep enkapsulasi, yang merupakan salah satu prinsip dasar dalam OOP.

Dalam konteks kode yang diberikan, metode-metode get digunakan untuk mengakses nilai-nilai pribadi (private) dari objek Segitiga dan Persegipanjang. Ini memungkinkan untuk mengakses nilai-nilai tersebut dari luar kelas Segitiga dan Persegipanjang, namun tetap mempertahankan sifat privatitas variabel-variabel tersebut, yang berarti variabel tersebut tidak dapat dimodifikasi secara langsung dari luar kelas.

Dengan menggunakan metode-metode getter seperti getAlas(), getTinggi(), getPanjang(), dan getLebar(), kita dapat mengambil nilai-nilai yang dimiliki oleh objek Segitiga dan Persegipanjang dan menggunakannya dalam pembuatan objek Prisma, sesuai dengan yang dibutuhkan dalam logika program. Ini membantu dalam memisahkan antara implementasi internal dari kelas dengan cara kelas tersebut berinteraksi dengan dunia luar, yang merupakan prinsip penting dalam desain yang baik dalam OOP.*/