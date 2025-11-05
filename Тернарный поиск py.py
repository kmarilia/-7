def ternary_search(arr, target, left=0, right=None):
    if right is None:
        right = len(arr) - 1
    
    if left <= right:
        # Делим диапазон на три части
        mid1 = left + (right - left) // 3
        mid2 = right - (right - left) // 3
        
        # Проверяем граничные точки
        if arr[mid1] == target:
            return mid1
        if arr[mid2] == target:
            return mid2
        
        # Определяем в какой трети продолжать поиск
        if target < arr[mid1]:
            return ternary_search(arr, target, left, mid1 - 1)
        elif target > arr[mid2]:
            return ternary_search(arr, target, mid2 + 1, right)
        else:
            return ternary_search(arr, target, mid1 + 1, mid2 - 1)
    
    return -1

# Пример использования
arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25]
target = 13
print("Массив:", arr)
print(f"Поиск элемента {target}")
result = ternary_search(arr, target)
print(f"Элемент найден на позиции: {result}")