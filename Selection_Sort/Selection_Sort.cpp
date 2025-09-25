#include <bits/stdc++.h>
#include <chrono>
using namespace std;


int arr[13] = {5,2,7,8,3,4,3,5,3,7,2,7,10};

int main(){
    int arr_size = sizeof(arr)/sizeof(arr[0]); // 배열의 크기

    auto start = chrono::steady_clock::now();

    for(int i = 1; i < arr_size; i++){ // 인덱스
        int key = arr[i]; // 현재 원소의 값
        int j = i - 1; // 비교할 원소의 인덱스

        while (j >= 0 && arr[j] > key){ 
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key; // 교환 종료
    }

    auto end = chrono::steady_clock::now();

    chrono::duration<double, milli> elapsed_ms = end - start;

    cout << elapsed_ms.count() << "ms" << endl;

    for(int i = 0; i < arr_size; i++){
        cout << arr[i];
    }
    return 0;
}