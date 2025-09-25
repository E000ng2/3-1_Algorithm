#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> arr = {5, 10, 264, 362, 865, 63, 94, 475, 135, 932, 25, 9, 33, 287, 332, 745, 377, 820, 62, 1};

void Max_Heapify(vector<int> &arr, int idx, int arr_size){
    int left_idx = idx*2 + 1; //왼쪽 자식의 인덱스
    int right_idx = idx*2 + 2; // 오른쪽 자식의 인덱스
    int largest_idx = idx;
    int last_idx = arr_size - 1;

    //가장큰 값(현재 노드)보다 왼쪽 자식이 더 큰 경우
    if (left_idx <=last_idx && arr[left_idx] > arr[largest_idx]){
        largest_idx = left_idx;
    }


    //가장 큰 값(현재노드와 외쪽 노드를 비교한것)보다 오른쪽 자식이 더 큰경우
    if(right_idx <= last_idx && arr[right_idx] > arr[largest_idx]){
        largest_idx = right_idx;
    }


    //현재 노드가 양쪽 자식들보다 작은 경우
    if(largest_idx != idx){
        swap(arr[idx], arr[largest_idx]); //노드 교환
        Max_Heapify(arr, largest_idx, arr_size); //교환한 자식 노드 인덱스에서 부터 다시 비교
    }
}

void Build_Max_Heap(vector<int> &arr, int arr_size){
    for(int i = (arr_size/2 - 1); i >= 0; i--){
        Max_Heapify(arr,i, arr_size);
    }
}

void Heap_Sort(vector<int> &arr, int arr_size){
    Build_Max_Heap(arr, arr_size);
    int last_idx = arr_size -1;
    for(int i = last_idx; i >= 1; i--){
        swap(arr[0], arr[i]); // 가장 앞에 있는 노드와 마지막 노드 교환
        arr_size--;
        Max_Heapify(arr, 0, arr_size); // 마지막 노드를 제외하고 힙 생성
    }
}

int main() {
    int arr_size = arr.size();
    Heap_Sort(arr,arr_size);

    cout << '[' ;
    for(int i = 0; i < arr_size - 1; i++){
        cout << arr[i] << ','; 
    }
    cout << arr[arr_size-1] <<']';

    return 0;
}