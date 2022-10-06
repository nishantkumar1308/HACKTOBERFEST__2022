def isValidCell(x, y, N):
    return not (x < 0 or y < 0 or x >= N or y >= N)
 
 
def countPaths(maze, i, j, dest, visited):
 
    N = len(maze)
 
    if (i, j) == dest:
        return 1
 
    count = 0
 
    visited[i][j] = True
 
    if isValidCell(i, j, N) and maze[i][j] == 1:
 
        if i + 1 < N and not visited[i + 1][j]:
            count += countPaths(maze, i + 1, j, dest, visited)
 
        if i - 1 >= 0 and not visited[i - 1][j]:
            count += countPaths(maze, i - 1, j, dest, visited)
 
        if j + 1 < N and not visited[i][j + 1]:
            count += countPaths(maze, i, j + 1, dest, visited)
 
        if j - 1 >= 0 and not visited[i][j - 1]:
            count += countPaths(maze, i, j - 1, dest, visited)
 
    visited[i][j] = False
 
    return count
 
 
def findCount(maze, src, dest):
 
    i, j = src
 
    x, y = dest
 
    if not maze or not len(maze) or not maze[i][j] or not maze[x][y]:
        return 0
 
    N = len(maze)
 
    visited = [[False for x in range(N)] for y in range(N)]
 
    return countPaths(maze, i, j, dest, visited)
 
 
if __name__ == '__main__':
 
    maze = [
        [1, 1, 1, 1],
        [1, 1, 0, 1],
        [0, 1, 0, 1],
        [1, 1, 1, 1]
    ]
 
    src = (0, 0)
 
    dest = (3, 3)
 
    print("The total number of unique paths are", findCount(maze, src, dest))
 