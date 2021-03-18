"""
문제 링크 : https://contest.nypc.co.kr/problems/5

code by Song Kitae(DKSH)
"""


def convertInt(li):
    for i in range(len(li)):
        li[i] = int(li[i])
    return li


if __name__ == "__main__":
    time_arr = []
    attempt_arr = []
    for x in range(3):
        time = input().split(':')
        time_arr.append(time[0]+time[1]+time[2])
    convertInt(time_arr)
    cnt = int(input())
    for y in range(cnt):
        attempt = input().split(':')
        attempt_arr.append(attempt[0]+attempt[1]+attempt[2])
    convertInt(attempt_arr)
    for i in range(cnt):
        if attempt_arr[i] <= time_arr[2]:
            print("***")
        elif attempt_arr[i] >= time_arr[2] and attempt_arr[i] <= time_arr[1]:
            print("**")
        elif attempt_arr[i] >= time_arr[1] and attempt_arr[i] <= time_arr[0]:
            print("*")
        elif attempt_arr[i] > time_arr[0]:
            print(":(")
