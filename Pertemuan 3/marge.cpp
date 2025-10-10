#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menggabungkan dua subarray yang sudah terurut
void merge(vector<int>& arr, int left, int mid, int right) {
   
    // Hitung ukuran dua subarray yang akan digabungkan
    int n1 = mid - left + 1;  // Ukuran subarray kiri 
    int n2 = right - mid;     // Ukuran subarray kanan 

    // Buat array temporer untuk menyimpan kedua subarray
    vector<int> L(n1), R(n2);

    // Salin data ke array temporer L[] dan R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Inisialisasi index untuk subarray kiri, kanan, dan array utama
    int i = 0;   // Index awal subarray pertama (kiri)
    int j = 0;   // Index awal subarray kedua (kanan)
    int k = left; // Index awal subarray yang akan digabungkan

    // Gabungkan array temporer kembali ke arr[left..right]
    while (i < n1 && j < n2) {
        // Bandingkan elemen dari kedua subarray
        if (L[i] <= R[j]) {
            arr[k] = L[i];  // Jika elemen kiri lebih kecil, masukkan ke array utama
            i++;
        } else {
            arr[k] = R[j];  // Jika elemen kanan lebih kecil, masukkan ke array utama
            j++;
        }
        k++;
    }

    // Salin sisa elemen dari L[] jika ada
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Salin sisa elemen dari R[] jika ada
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi utama merge sort yang mengimplementasikan divide and conquer
void mergeSort(vector<int>& arr, int left, int right) {
   
    // Base case: jika subarray hanya memiliki 1 elemen atau kurang
    if (left >= right)
        return;

    // Cari titik tengah untuk membagi array menjadi dua
    int mid = left + (right - left) / 2;

    // Rekursif: urutkan bagian kiri dan kanan
    mergeSort(arr, left, mid);      // Urutkan separuh kiri
    mergeSort(arr, mid + 1, right); // Urutkan separuh kanan
   
    // Gabungkan kedua bagian yang sudah terurut
    merge(arr, left, mid, right);
}

// Fungsi utilitas untuk mencetak array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//main program
int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;
   
    vector<int> data(n);
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
   
    cout << "Array sebelum diurutkan: ";
    printArray(data);
   
    // Panggil merge sort untuk mengurutkan array
    mergeSort(data, 0, n - 1);
   
    cout << "Array setelah diurutkan: ";
    printArray(data);
   
    return 0;
}