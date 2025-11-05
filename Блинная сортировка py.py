def pancake_sort(arr):
    n = len(arr)
    
    # Постепенно уменьшаем размер неотсортированной части
    for curr_size in range(n, 1, -1):
        # Находим индекс максимального элемента
        max_idx = arr.index(max(arr[:curr_size]))
        
        # Если максимальный элемент не на своем месте
        if max_idx != curr_size - 1:
            # Переворачиваем до максимального элемента
            if max_idx != 0:
                arr[:max_idx + 1] = arr[:max_idx + 1][::-1]
            # Переворачиваем всю неотсортированную часть
            arr[:curr_size] = arr[:curr_size][::-1]
    
    return arr

# Пример использования
arr = [3, 1, 4, 1, 5, 9, 2, 6]
print("Исходный массив:", arr)
sorted_arr = pancake_sort(arr.copy())
print("Отсортированный массив:", sorted_arr)