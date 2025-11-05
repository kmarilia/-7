def bead_sort(arr):
    # Находим максимальный элемент для определения высоты
    max_val = max(arr)
    
    # Создаем "абак" - матрицу бусин
    beads = [[0] * len(arr) for _ in range(max_val)]
    
    # Расставляем бусины
    for i, num in enumerate(arr):
        for j in range(num):
            beads[j][i] = 1
    
    # "Падение" бусин под гравитацией
    for j in range(len(arr)):
        sum_col = sum(beads[i][j] for i in range(max_val))
        for i in range(max_val):
            beads[i][j] = 1 if i < sum_col else 0
    
    # Считываем результат
    result = []
    for i in range(max_val):
        result.append(sum(beads[i]))
    
    return result[::-1]  # Переворачиваем, так как считали сверху вниз

# Пример использования
arr = [3, 1, 4, 1, 2]
print("Исходный массив:", arr)
sorted_arr = bead_sort(arr)
print("Отсортированный массив:", sorted_arr)