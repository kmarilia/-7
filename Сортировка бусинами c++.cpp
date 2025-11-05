#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void beadSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int n = arr.size();
    
    vector<vector<int>> beads(maxVal, vector<int>(n, 0));
    
    // Расставляем бусины
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i]; j++) {
            beads[j][i] = 1;
        }
    }
    
    // "Падение" бусин под гравитацией
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < maxVal; i++) {
            sum += beads[i][j];
        }
        for (int i = 0; i < maxVal; i++) {
            beads[i][j] = (i < sum) ? 1 : 0;
        }
    }
    
    // Считываем результат
    for (int i = 0; i < maxVal; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += beads[i][j];
        }
        arr[maxVal - 1 - i] = sum;
    }
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 2};
    cout << "Исходный массив: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    beadSort(arr);
    
    cout << "Отсортированный массив: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}