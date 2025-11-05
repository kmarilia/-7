#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void flip(vector<int>& arr, int idx) {
    int start = 0;
    while (start < idx) {
        swap(arr[start], arr[idx]);
        start++;
        idx--;
    }
}

int findMaxIndex(vector<int>& arr, int n) {
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

void pancakeSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int currSize = n; currSize > 1; currSize--) {
        int maxIdx = findMaxIndex(arr, currSize);
        
        if (maxIdx != currSize - 1) {
            if (maxIdx != 0) {
                flip(arr, maxIdx);
            }
            flip(arr, currSize - 1);
        }
    }
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    cout << "Исходный массив: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    pancakeSort(arr);
    
    cout << "Отсортированный массив: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}