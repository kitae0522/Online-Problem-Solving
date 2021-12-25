a = int(input())

for _ in range((2*a)):
    print('@'*a, end='')
    print(' '*(3*a), end='')
    print('@'*a)
for _ in range(a):
    print('@@@@@'*a)
for _ in range(a):
    print('@'*a, end='')
    print(' '*(3*a), end='')
    print('@'*a)
for _ in range(a):
    print('@@@@@'*a)
