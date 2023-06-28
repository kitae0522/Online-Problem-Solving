def convert_base(n: int, base: int):
    digits = tuple(str(i) for i in range(10)) + tuple(chr(ord('A') + i) for i in range(26))
    res = []
    if 2 <= base <= 36:
        while n > 0:
            n, r = divmod(n, base)
            res.append(digits[r])
        return ''.join(res[::-1])


if __name__ == '__main__':
    n, base = map(int, input().split())
    print(convert_base(n, base))
