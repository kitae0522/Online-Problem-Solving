"""
문제 링크 : https://nypc.github.io/2019/2019_online_4.html

code by Song Kitae(DKSH)
"""


if __name__ == "__main__":
    res = 100
    tmp = 0

    n = int(input())
    arr1 = [int(x) for x in input().strip().split()]
    arr2 = [int(x) for x in input().strip().split()]
    for i in range(n):
        if arr1[i] == 0:
            tmp = 0
            break
        if arr2[i] == 0:
            continue
        tmp = arr1[i] // arr2[i]
        if tmp < res:
            res = tmp
    print(tmp)
