def count(S, n, target, lookup):
 
    if target == 0:
        return 1
 
    if target < 0 or n < 0:
        return 0
 
    key = (n, target)
 
    if key not in lookup:
 
        include = count(S, n, target - S[n], lookup)
 
        exclude = count(S, n - 1, target, lookup)
 
        lookup[key] = include + exclude
 
    return lookup[key]
 
 
# Coin Change Problem
if __name__ == '__main__':
 
    S = [1, 2, 3]       
    target = 4               
 
    lookup = {}
 
    print('The total number of ways to get the desired change is',
        count(S, len(S) - 1, target, lookup))
 