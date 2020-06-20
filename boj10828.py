import sys


if __name__ == "__main__":
    input = sys.stdin.readline
    num = int(input())
    stack = []
    for i in range(num):
        cmd = input().rstrip()
        if " " in cmd: 
            c,n = cmd.split()
            stack.append(int(n))
        elif cmd == "pop":
            if not stack:
                print("-1")
            else:
                print(stack[-1])
                stack.pop(-1)
        elif cmd == "size":
            print(len(stack))
        elif cmd == "empty":
            if not stack:
                print("1")
            else:
                print("0")
        elif cmd == "top":
            if not stack:
                print("-1")
            else:
                print(stack[-1])
