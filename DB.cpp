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


float hitung Total() {
  float total = 0;
  for (int i = 0;i < jumlah; i++) {
    total += harga[i];
  }
  return total;
}
