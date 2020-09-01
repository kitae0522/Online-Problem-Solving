"""
문제 링크 : https://contest.nypc.co.kr/problems/6

code by Song Kitae(DKSH)
"""


if __name__ == "__main__":
    cnt = int(input())
    for i in range(cnt):
        player = list(map(int, input().split()))
        bazziTeam = player[0:4]
        otherTeam = player[4:8]

        if max(bazziTeam) <= max(otherTeam) and sum(bazziTeam) > sum(otherTeam):
            print("S")
        elif sum(bazziTeam) <= sum(otherTeam) and max(bazziTeam) > max(otherTeam):
            print("I")
        else:
            print("R")
