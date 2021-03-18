"""
문제 링크 : https://contest.nypc.co.kr/problems/4

code by Song Kitae(DKSH)
"""


if __name__ == "__main__":
    cmd = input()
    cnt = 0
    for i in range(len(cmd)):
        if cmd[i] == "S":
            cnt += 1
        elif cmd[i] == "T":
            if cnt // 4 == 0:
                cnt = 4
            else:
                cnt = cnt+4 - (cnt % 4)
    print(cnt)
