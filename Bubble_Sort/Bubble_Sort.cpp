#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int arr[13] = {5,2,7,8,3,4,3,5,3,7,2,7,10};

int main(){
    /*
    for (j = 1; j < 배열크기) 1 ~ 마지막 원소 ( n-1번)
    for (i = 1; i <=  배열 크기 - j; i ++){
        int j = i - 1
        
        if(arr[i] < arr[j])
            // 바꾸기
        }
    
    */
    int arr_size = sizeof(arr)/sizeof(arr[0]);


    auto start = chrono::steady_clock::now();
    for(int i = 1; i < arr_size; i++){ // n-1번 실행
        for(int j = 1; j <= arr_size - i; j++){
            int k = j - 1;
            if(arr[j] < arr[k]){
                int temp = arr[k];
                arr[k] = arr[j];
                arr[j] = temp;
            }
        }
    }
    auto end = chrono::steady_clock::now();

    chrono::duration<double, milli> elapsed_ms = end - start;

    cout << elapsed_ms.count() << "ms" << endl;
    
    for(int i = 0; i < arr_size; i++){
        cout << arr[i];
    }

    return 0;
}