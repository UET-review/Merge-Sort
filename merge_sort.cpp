#include <iostream>

using namespace std;

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int l, int k, int r){

    int n1 = k - l + 1;
    int n2 = r - k;

    // Create temp array
    int L[n1];
    int R[n2];
    for(int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }

    for(int i = 0; i < n2; i++){
        R[i] = arr[k + 1 + i];
    }

    // Merge 2 array
    int i = 0; // Left array
    int j = 0; // Right array
    int t = l; // Temp array

    while(i < n1 && j < n2){
        if (L[i] <= R[j]) arr[t++] = L[i++];
        else arr[t++] = R[j++];
    }

    // Copy cac phan tu con lai cua mang ben trai
    while (i < n1){
        arr[t++] = L[i++];
    }

    // Copy cac phan tu con lai cua mang ben phai
    while(j < n2){
        arr[t++] = R[j++];
    }

}

void merge_sort(int arr[], int l, int r){
    if(l < r){
        int k = (l+r)/2;

        // Left
        merge_sort(arr, l, k);
        //Right
        merge_sort(arr, k+1, r);

        // Merge
        merge(arr, l, k, r );
    }
}

int main(){
    int n = 8;
    int arr[8] = {7, 2, 9, 4, 3, 8, 6, 1};
    cout << "Origin array:" << endl;
    print(arr, n);
    merge_sort(arr, 0, n-1);
    cout << "Merge sort result:" << endl;
    print(arr, n);
    return 0;
}