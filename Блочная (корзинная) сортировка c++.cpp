#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<double>& arr) {
    int n = arr.size();
    vector<vector<double>> buckets(n);
    
    // Распределение элементов по корзинам
    for (double num : arr) {
        int index = num * n;
        buckets[index].push_back(num);
    }
    
    // Сортировка каждой корзины
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
    }
    
    // Объединение корзин
    int index = 0;
    for (auto& bucket : buckets) {
        for (double num : bucket) {
            arr[index++] = num;
        }
    }
}

int main() {
    vector<double> arr = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    cout << "Исходный массив: ";
    for (double num : arr) cout << num << " ";
    cout << endl;
    
    bucketSort(arr);
    
    cout << "Отсортированный массив: ";
    for (double num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}