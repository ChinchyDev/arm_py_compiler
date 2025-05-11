# bubble_sort.py
arr = [5, 1, 4, 2, 8]
n = 5
i = 0

while i < n - 1:
    j = 0
    while j < n - i - 1:
        if arr[j] > arr[j + 1]:
            temp = arr[j]
            arr[j] = arr[j + 1]
            arr[j + 1] = temp
        j = j + 1
    i = i + 1

print(arr)
