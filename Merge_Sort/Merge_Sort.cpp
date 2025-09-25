#include <bits/stdc++.h>
#include <chrono>
#include <vector>

using namespace std;

vector<int> arr = {5,2,7,8,3,4,3,5,3,7,2,7,10};

void Merge(vector<int> &arr, int left, int mid, int right){
    int n1 = mid - left + 1; // 왼쪽 부분 배열의 크기
    int n2 = right - mid; // 오른쪽 부분 배열의 크기

    vector<int> L(n1); // 왼쪽 임시 배열
    vector<int> R(n2); // 오른쪽 임시 배열

    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    for(int i = 0; i < n2; i++){
        R[i] = arr[mid + 1 + i];
    }

    int idx_L = 0;
    int idx_R = 0;
    int idx = left;

    while (idx_L < n1 && idx_R < n2){
        if(L[idx_L] <= R[idx_R]){
            arr[idx] = L[idx_L];
            idx_L++;
            idx++;
        }
        else{
            arr[idx] = R[idx_R];
            idx_R++;
            idx++;
        }
    }

    while(idx_L < n1){
        arr[idx] = L[idx_L];
        idx_L++;
        idx++;
    }

    while (idx_R < n2){
        arr[idx] = R[idx_R];
        idx_R++;
        idx++;
    }

}

void Merge_Sort(vector<int> &arr, int left, int right){
    if(left >= right){
        return;
    }

    int mid = (left + right)/2;

    Merge_Sort(arr, left, mid);
    Merge_Sort(arr, mid+1, right);

    Merge(arr, left, mid, right);
}



int main(){
    int arr_size = arr.size();
    Merge_Sort(arr, 0, arr_size-1);
    for(int i = 0; i < arr_size; i++){
        cout << arr[i] << ' ';
    }
   
    return 0;
}