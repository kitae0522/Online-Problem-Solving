arr = [int(input()) for _ in range(9)]
arr.sort()
goal = sum(arr) - 100

for i in range(9):
    for j in range(i+1, 9):
        if arr[i] + arr[j] == goal:
            answer = [arr[n] for n in range(9) if n not in [i, j]]
            print(*answer, sep='\n')
            exit()
