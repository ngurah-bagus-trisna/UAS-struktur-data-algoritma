# UAS Struktur Data dan Algoritma

```
Nama  : I Gusti Ngurah Bagus Trisna Andika
Kelas : IT201
NIM   : 230401010136
```

## How to compile

Di linux gunakan `g++`

```sh
g++ ./no1.cpp
```

# 1. Program sorting array bublesort & selection sort

![](./attachment/result-no1.png)

## Keteragan Code

### Buble Sort

Buat function untuk buble sort, membandingkan data pertama dan kedua yang berdekatan dalam array. Jika ada yang lebih besar, maka posisinya ditukar/ disini membuat dengan nama `sementaraNama` & `sementaraAlamat`. 

```cpp
void bubleSort(string listArr[][8], int n) {
  // Buat perulangan i kurang dari jumlah n atau saat fungsi dipanggil, nilai n = panjang array
  for (int i = 0; i < n; i++) {
    // pengulangan kembali, disini nilai j kurang dari nilai n-i-1.
    for (int j = 0; j < n-i-1; j++){
      // Jika listArr/Array dimensi pertama yaitu "Nama" > listArr sebelahnya, tukar.
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
```

### Selection Sort

Membuat fucntion untuk selection sort, disini sesuai dengan algoritma selection sort, saya membuat nilai terkecil yaitu value `i`, nantinya tukar posisi nilai terkecil yang ditemukan dengan nilai data awal. 

```cpp

// Fungsi selection sort
void selectionSort(string listArr[][8], int n) {
  // Perulangan dengan nilai panjang array - 1
  for (int i = 0; i < n-1; i++) {
    // buat variable minId = i, yang dijadikan nilai terkecil
    int minId = i;
    for (int j = i+1;j < n; j++) {
      // Jika list array dimensi pertama < dari list array dimensi pertama yang dikatakan telah terurut oleh  `minId = i`, maka index yang teruurut adalah j/ `minId = j`
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

```

### Fungsi menampilkan hasil

```cpp
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
```

### Main

Program main berjalan

```cpp
int main() {

  // Membuat variable dengan array 2 dimesi, dimensi pertama terdapat array nama, dan dimensi kedua terdapat array alamat

  string listNamaAlamat [2][8] = {
    {"Fahmi", "Romi", "Andri", "Fadilah", "Ruli", "Rudi", "Dendi", "Zaki"},
    {"Jakarta", "Solo", "Jakarta", "Banyuwangi", "Bandung", "Bali", "Purwokerto", "Madiun"} 
  };

  // Menampilkan tabel sebelum diurutkan
  cout << "Sebelum diurutkan" << endl;
  outputResult(listNamaAlamat, 8);

  // menampilkan tabel setelah diurutkan buble sort
  cout << "Setelah diurutkan Buble Sort" << endl;

  bubleSort(listNamaAlamat, 8);
  outputResult(listNamaAlamat, 8);


  // menampilkan setelah diurutkan selection sort 

    cout << "Setelah diurutkan Selection Sort" << endl;

  selectionSort(listNamaAlamat, 8);
  outputResult(listNamaAlamat, 8);

  return 0;
}
```

# 2. Program search index berdasarkan value dengan `binary serach`

![](./attachment/result-no2.png)

## Keterangan Kode

Karena disini value nya acak, jadi algoritmanya

- Urutkan terlebih dahulu value array
- Gunakan fungsi binary search untuk mencari target value
- Array yang sudah sorted, dan sudah dicari target value nya cocok kan dengan original array/array default sebelumnya, nantinya result menggunakan refrensi default array

### Buble Sort

Buat function untuk buble sort, membandingkan data pertama dan kedua yang berdekatan dalam array. Jika ada yang lebih besar, maka posisinya ditukar/swap

```cpp
// Fungsi bubule sort untuk sementara mengurutkan soal array. Karena binary search tidak tidak support array yang tidak tersorting 
void bubbleSort(int listArr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (listArr[j] > listArr[j + 1]) {
                // Swap 
                int sementara = listArr[j];
                listArr[j] = listArr[j + 1];
                listArr[j + 1] = sementara;
            }
        }
    }
}
```

### Binary Search

Fungsi ini dipanggil untuk menggurutkan array hasil result dari buble sort. Sesuai algoritma buble sort, yaitu 


```cpp
// Fungsi binary search untuk mencari target dalam array yang diurutkan
int binarySearch(int arr[], int n, int target) {

  // Menentukan value low, dan value high dalam array.
    int low = 0;
    int high = n - 1;

    // Buat pengulangan dengan kondisi true, jika low kurang/sama dengan high
    while (low <= high) {
      // Mencari index tengah
        int mid = (low + high) / 2;
        // buat kondisi, jika array tengah == target (Target disini adalah index yang dicari), maka mid adalah angka yang dicari. Jika array mid < target, low = mid + 1, jika > target high = mid - 1
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // export return -1 ketika value dalam array tidak ditemukan
}

```

### Fungsi findSortedArray untuk 
Fungsi untuk mencari array yang sudah di sorted, dan mencocokan dengan array default/orriginal_array. nantinya result yang ditampilkan menggunakan refrensi default array

```cpp
void findSortedArray(int original_arr[], int sorted_arr[], int n, int target) {
  // Variable indexSudahSorted, menampung hasil dari binarySearch 
    int indexSudahSorted = binarySearch(sorted_arr, n, target);

    // jika hasil return dari binarySearch/index yang sudah di sorted bukan -1, lanjutkan pengecekan.
    if (indexSudahSorted != -1) {
        cout << "Angka " << target << " ada di indeks ke ";
        bool first = true;

        // tampilkan hasil jika terdapat value lebih dari 1 array
        for (int i = 0; i < n; i++) {
          // Jika orignal array == target/indexnya maka tampilkan index
            if (original_arr[i] == target) {
                // Jika lebih dari satu
                if (!first) {
                    cout << " dan ";
                }
                // seharusnya index sebuah array dimulai dari 0, tetapi di soal untuk mengikuti pengecekan, ditambahkan angka +1 agar sesuai dengan test-case
                cout << i + 1;
                first = false;
            }
        }
        cout << endl;
    } else {
        cout << "Angka " << target << " tidak ada dalam array" << endl;
    }
}

```

### Main Program

```cpp
int main() {
    // panjang array
    const int arrLength = 9; 
    int defaultArr[arrLength] = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    int sortedArr[arrLength];

    // Salin array asli untuk diurutkan
    for (int i = 0; i < arrLength; i++) {
        sortedArr[i] = defaultArr[i];
    }

    // Urutkan array 
    bubbleSort(sortedArr, arrLength);

    // buat input user
    int inputUser;
    cout << "Masukkan angka yang ingin dicari (-1 untuk keluar): ";
    // buat looping, "Jika input user sudah masuk ke variable InputUser dan input user tidak bernilai -1, lanjutkan tampilkan hasil :
    // hanya akan berhenti loop/keluar dari aplikasi jika user input -1
    while (cin >> inputUser && inputUser != -1) {
        findSortedArray(defaultArr, sortedArr, arrLength, inputUser);
        cout << "Masukkan angka yang ingin dicari (-1 untuk keluar): ";
    }

    return 0;
}
```