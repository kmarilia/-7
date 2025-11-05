#include <iostream>
#include <vector>
using namespace std;

int ternarySearch(vector<int>& arr, int target, int left, int right) {
    if (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        
        if (arr[mid1] == target) {
            return mid1;
        }
        if (arr[mid2] == target) {
            return mid2;
        }
        
        if (target < arr[mid1]) {
            return ternarySearch(arr, target, left, mid1 - 1);
        } else if (target > arr[mid2]) {
            return ternarySearch(arr, target, mid2 + 1, right);
        } else {
            return ternarySearch(arr, target, mid1 + 1, mid2 - 1);
        }
    }
    return -1;
}

int ternarySearch(vector<int>& arr, int target) {
    return ternarySearch(arr, target, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};
    int target = 13;
    cout << "Массив: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    cout << "Поиск элемента: " << target << endl;
    int result = ternarySearch(arr, target);
    cout << "Элемент найден на позиции: " << result << endl;
    
    return 0;
}