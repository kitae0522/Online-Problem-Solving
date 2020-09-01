"""
문제 링크 : https://contest.nypc.co.kr/problems/10

code by Song Kitae(DKSH)
"""


def f(arr):
    mathe = ("+", "-", "*", "/", ".")
    for x in mathe:
        for y in mathe:
            if (x and y == ".") and (x == "/" and int(arr[1]) == 0) and (y == "/" and int(arr[2]) == 0):
                continue
            res = eval(arr[0] + x + arr[1] + y + arr[2])
            if res == float(arr[3]):
                print(arr[0] + x + arr[1] + y + arr[2] + "=" + arr[3])
                return


if __name__ == "__main__":
    N = int(input())

    for i in range(N):
        arr = input().split()
        f(arr)
