"""
문제 링크 : https://nypc.github.io/2019/2019_online_3.html

code by Song Kitae(DKSH)
"""


if __name__ == "__main__":
    start_hp, count = map(int, input().split())
    max_hp = start_hp
    for i in range(count):
        log, H = map(int, input().split())
        if log == 1:
            if start_hp < 0:
                start_hp = 0
            else:
                start_hp -= H
        elif log == 2:
            if start_hp + H >= max_hp:
                start_hp += H
        elif log == 3:
            start_hp += H
            if start_hp > max_hp:
                max_hp = start_hp
    print(max_hp)
