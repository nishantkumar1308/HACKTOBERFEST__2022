def knapsack(v, w, W):
 
    T = [[0 for x in range(W + 1)] for y in range(len(v) + 1)]
 
    # do for i'th item
    for i in range(1, len(v) + 1):
 
        for j in range(W + 1):
 
            if w[i - 1] > j:
                T[i][j] = T[i - 1][j]
            else:
                T[i][j] = max(T[i - 1][j], T[i - 1][j - w[i - 1]] + v[i - 1])
 
    return T[len(v)][W]
 
 
if __name__ == '__main__':
 
    v = [20, 5, 10, 40, 15, 25]
    w = [1, 2, 3, 8, 7, 4]
 
    W = 10
 
    print('Knapsack value is', knapsack(v, w, W))
 
