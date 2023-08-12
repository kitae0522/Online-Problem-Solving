def f(x: str):
    cnt: int = 0
    while len(x) > 1:
        y: int = sum(int(digit) for digit in x)
        x: str = str(y)
        cnt += 1
    return cnt, x in {'3', '6', '9'}

x = input()
rtrn_val_1, rtrn_val_2 = f(x)
print(rtrn_val_1)
print("YES" if rtrn_val_2 else "NO")