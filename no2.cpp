// Nama     : I Gusti Ngurah Bagus Trisna Andika
// Kelas    : IT201
// NIM      : 230401010136 

// Aplikasi pencari index array dengan binary search

#include <iostream>

using namespace std;

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

// Fungsi binary search untuk mencari target dalam array yang diurutkan
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
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

// fungsi untuk mencari array yang sudah di sorted, dan mencocokan dengan array default/orriginal_array. nantinya result yang ditampilkan menggunakan refrensi default array
void findSortedArray(int original_arr[], int sorted_arr[], int n, int target) {
    int indexSudahSorted = binarySearch(sorted_arr, n, target);

    // jika hasil return dari binarySearch/index yang sudah di sorted bukan -1, lanjutkan pengecekan.
    if (indexSudahSorted != -1) {
        cout << "Angka " << target << " ada di indeks ke ";
        bool first = true;

        // tampilkan hasil jika terdapat value lebih dari 1 array
        for (int i = 0; i < n; i++) {
            if (original_arr[i] == target) {
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