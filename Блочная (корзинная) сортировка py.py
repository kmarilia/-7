def bucket_sort(arr):
    # Создаем пустые корзины
    n = len(arr)
    buckets = [[] for _ in range(n)]
    
    # Распределяем элементы по корзинам
    for num in arr:
        index = int(num * n)  # Для чисел в диапазоне [0,1)
        buckets[index].append(num)
    
    # Сортируем каждую корзину
    for bucket in buckets:
        bucket.sort()
    
    # Объединяем корзины
    result = []
    for bucket in buckets:
        result.extend(bucket)
    
    return result

# Пример использования
arr = [0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51]
print("Исходный массив:", arr)
sorted_arr = bucket_sort(arr)
print("Отсортированный массив:", sorted_arr)