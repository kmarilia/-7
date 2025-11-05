import math

def jump_search(arr, target):
    n = len(arr)
    step = int(math.sqrt(n))
    prev = 0
    
    # Прыжки через блоки
    while arr[min(step, n) - 1] < target:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1
    
    # Линейный поиск в найденном блоке
    for i in range(prev, min(step, n)):
        if arr[i] == target:
            return i
        if arr[i] > target:
            break
    
    return -1

# Пример использования
arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
target = 13
print("Массив:", arr)
print(f"Поиск элемента {target}")
result = jump_search(arr, target)
print(f"Элемент найден на позиции: {result}")