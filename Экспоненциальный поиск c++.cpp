#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& arr, int target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int exponentialSearch(vector<int>& arr, int target) {
    int n = arr.size();
    
    if (arr[0] == target) {
        return 0;
    }
    
    int i = 1;
    while (i < n && arr[i] <= target) {
        i *= 2;
    }
    
    return binarySearch(arr, target, i / 2, min(i, n - 1));
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};
    int target = 15;
    cout << "Массив: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    cout << "Поиск элемента: " << target << endl;
    int result = exponentialSearch(arr, target);
    cout << "Элемент найден на позиции: " << result << endl;
    
    return 0;
}