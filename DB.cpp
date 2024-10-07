#include <iostream>
using namespace std;

const int MAKSIMAL = 100;

string nama[MAKSIMAL];
float harga[MAKSIMAL];
int jumlah = 0;

void tambahBarang(const string& a, float t) {
  if (jumlah < MAKSIMAL) {
    nama[jumlah] = a;
    harga[jumlah] = t;
    jumlah++;
    cout<<"'"<<a<<"' berhasil ditambahkan.\n";
  } else {
    cout<<"Daftar belanja sudah.\n";
  }
}

void hapusBarang(int nomor) {
  if(nomor >=0 && nomor < jumlah) {
    cout<<"'"<<nama[nomor]<<"' berhasil dihapus.\n";
    for (int i= nomor;  i < jumlah - 1; i++) {
      nama[i] = nama[i + 1];
      harga[i] = harga[i + 1];
    }jumlah--;
  } else {
      cout<<"Nomor tidak valid!\n";
  }
}

void tampilkanDaftar() {
  cout<<"\nDaftar Belanja:\n";
  for (int i = 0; i < jumlah; i++){
    cout<<i + 1<<". "<<nama[i]<<" - Rp"<<harga[i]<<endl;
  } if (jumlah == 0) {
      cout<<"Daftar belanja kosong.\n";
  }
}


float hitungTotal() {
  float total = 0;
  for (int i = 0;i < jumlah; i++) {
    total += harga[i];
  }
  return total;
}

int main(){
  int pilihan;
  char namaBarang[50];
  float hargaBarang;

  do {
      cout<<"\n=== Daftar Belanja ===\n";
      cout<<"1. Tambah Barang\n";
      cout<<"2. Hapus Barang\n";
      cout<<"3. Tampilkan Daftar\n";
      cout<<"4. Hitung Total\n";
      cout<<"5. Keluar\n";
      cout<<"Pilih opsi (1-5): ";
      cin>>pilihan;
      cin.ignore();

      switch (pilihan){
          case 1: 
              cout<<"Masukkan nama barang: ";
              cin.getline(namaBarang, 50);
              cout<<"Masukkan harga barang: ";
              cin>>hargaBarang;
              tambahBarang(namaBarang, hargaBarang);
              break;
          case 2:
              tampilkanDaftar();
              int nomor;
              cout<<"Masukkan nomor barang yang ingin dihapus: ";
              cin>>nomor;
              hapusBarang(nomor - 1);
              break;
          case 3:
              tampilkanDaftar();
              break;
          case 4:
              cout<<"Total harga daftar belanja: Rp "<<hitungTotal()<<endl;
              break;
          case 5:
              cout<<"Keluar dari program.\n";
              break;
          default:
              cout<<"Pilihan invalid. Silahkan coba lagi.\n";
      }
  } while (pilihan != 5);

  return 0;
}
