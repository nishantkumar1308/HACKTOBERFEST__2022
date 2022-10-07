def rodCut(price, n):
 
    T = [0] * (n + 1)
 
    for i in range(1, n + 1):
        for j in range(1, i + 1):
            T[i] = max(T[i], price[j - 1] + T[i - j])
 
    return T[n]
 
 
if __name__ == '__main__':
 
    price = [1, 5, 8, 9, 10, 17, 17, 20]
    n = 4        
 
    print('Profit is', rodCut(price, n))
 
