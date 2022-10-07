def findLIS(arr):
 
    if not arr:
        return []
 
    LIS = [[] for _ in range(len(arr))]
 
    LIS[0].append(arr[0])
 
    for i in range(1, len(arr)):
 
        for j in range(i):
 
            if arr[j] < arr[i] and len(LIS[j]) > len(LIS[i]):
                LIS[i] = LIS[j].copy()
 
        LIS[i].append(arr[i])
 
    j = 0
    for i in range(len(arr)):
        if len(LIS[j]) < len(LIS[i]):
            j = i
 
    print(LIS[j])
 
 
if __name__ == '__main__':
 
    arr = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
    findLIS(arr)
 
