def exponential_search(arr, target):
    n = len(arr)
    
    # Если элемент в начале
    if arr[0] == target:
        return 0
    
    # Экспоненциальное увеличение диапазона
    i = 1
    while i < n and arr[i] <= target:
        i *= 2
    
    # Бинарный поиск в найденном диапазоне
    left = i // 2
    right = min(i, n - 1)
    
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1

# Пример использования
arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25]
target = 15
print("Массив:", arr)
print(f"Поиск элемента {target}")
result = exponential_search(arr, target)
print(f"Элемент найден на позиции: {result}")