import sys

if __name__ == "__main__":
    N = int(sys.stdin.readline())
    array = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
    res = []

    array.sort()

    for i in range(N):
        if i == 0:
            res.append(array[i][1])
            continue
        chk = 1

        for j in range(len(res)):
            if array[i][0] >= res[j]:
                chk = 0
                res[j] = array[i][1]
                break

        if chk == True:
            res.append(array[i][1])

    print(len(res))
