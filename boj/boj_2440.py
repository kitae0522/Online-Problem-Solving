x = int(input())
for i in range(x + 1):
    for y in range(x - i):
        print("*", end="")
    print()
