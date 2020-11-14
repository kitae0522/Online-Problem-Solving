def get_gcd(num1, num2):

    smaller = min(num1, num2)
    gcd = None
    for i in range(1, smaller + 1):
        if num1 % i == 0 and num2 % i == 0:
            gcd = i

    return gcd


def get_lcm(num1, num2):
    bigger = max(num1, num2)

    while True:
        if bigger % num1 == 0 and bigger % num2 == 0:
            break
        bigger += 1
    return bigger


if __name__ == "__main__":
    def main():

        num1, num2 = map(int, input().split())
        lcm = get_lcm(num1, num2)
        gcd = get_gcd(num1, num2)
        print(gcd)
        print(lcm)

    main()
