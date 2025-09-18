#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "masukan Jumlah elemen array :";
    cin>> n;

    int* arr = new int (n); // new = alamat pointer dari elemen ke array awal yaitu 0 

    cout << " Masukan " << n << "angka \n";
    for (int i = 0; i < n; i++){
    cin >> arr[i];
    }
    cout <<"Isi array : ";
    for(int i = 0;i < n; i++){
        cout << arr[i]<<" ";

    }
    delete[] arr;
    return 0;
}