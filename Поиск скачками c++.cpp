#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int jumpSearch(vector<int>& arr, int target) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;
    
    // Прыжки через блоки
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }
    
    // Линейный поиск в найденном блоке
    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == target) {
            return i;
        }
        if (arr[i] > target) {
            break;
        }
    }
    
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 13;
    cout << "Массив: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    cout << "Поиск элемента: " << target << endl;
    int result = jumpSearch(arr, target);
    cout << "Элемент найден на позиции: " << result << endl;
    
    return 0;
}