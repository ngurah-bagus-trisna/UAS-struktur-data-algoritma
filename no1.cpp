// Nama   : I Gusti Ngurah Bagus Trisna Andika
// Kelas  : IT201
// NIM    : 230401010136

// iomanip saya gunakan untuk setwidth dalam print table

#include <iomanip>
#include <iostream>

using namespace std;

// Disini saya gunakan array 2 dimensi, dimensi pertama saya gunakan untuk menyimpan array nama, dimensi ke dua saya gunakan untuk menyimpan array alamat 

// Buat function untuk buble sort, membandingkan data pertama atau disini saya buat dengan nama "sementaraNama/Alamat", dan nantinya akan saling ditukar/swap 
void bubleSort(string listArr[][8], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-i-1; j++){
      if (listArr[0][j] > listArr[0][j+1]) {
        // Swap nama
        string sementaraNama = listArr[0][j];
        listArr[0][j] = listArr[0][j+1];
        listArr[0][j+1] = sementaraNama; 

        // Swap alamat 
        string sementaraAlamat = listArr[1][j];
        listArr[1][j] = listArr[1][j+1];
        listArr[1][j+1] = sementaraAlamat; 
      }
    }
  }
}

// buat function selectionSort, 

void selectionSort(string listArr[][8], int n) {
  for (int i = 0; i < n-1; i++) {
    int minId = i;
    for (int j = i+1;j < n; j++) {
      if (listArr[0][j] < listArr[0][minId]) {
        minId = j;
      }
    }

    // swap nama
    string sementaraNama = listArr[0][i];
    listArr[0][i] = listArr[0][minId];
    listArr[0][minId] = sementaraNama; 

    // swap alamat
    string sementaraAlamat = listArr[1][i];
    listArr[1][i] = listArr[1][minId];
    listArr[1][minId] = sementaraAlamat; 
  }
}

// Buat fungsi untuk output hasil result. Karena disini terdapat pengulangan 3 kali untuk print table.

void outputResult(string listArr[][8], int n) {
  cout << setfill('-') << setw(41) << "-" << setfill(' ') << endl; 
  cout << left << setw(20) << "| Nama " << setw(20) << "| Alamat" << "|" << endl;
  cout << setfill('-') << setw(41) << "-" << setfill(' ') << endl; 
  for (int i = 0 ; i < n; i++) {
    cout << "| " << left << setw(18) << listArr[0][i] << "| " << setw(18) << listArr[1][i]  << "|" << endl;
  }
  cout << setfill('-') << setw(41) << "-" << setfill(' ') << endl; 

}


int main() {

  string listNamaAlamat [2][8] = {
    {"Fahmi", "Romi", "Andri", "Fadilah", "Ruli", "Rudi", "Dendi", "Zaki"},
    {"Jakarta", "Solo", "Jakarta", "Banyuwangi", "Bandung", "Bali", "Purwokerto", "Madiun"} 
  };

  cout << "Sebelum diurutkan" << endl;
  outputResult(listNamaAlamat, 8);


  cout << "Setelah diurutkan Buble Sort" << endl;

  bubleSort(listNamaAlamat, 8);
  outputResult(listNamaAlamat, 8);

    cout << "Setelah diurutkan Selection Sort" << endl;

  selectionSort(listNamaAlamat, 8);
  outputResult(listNamaAlamat, 8);

  return 0;
}