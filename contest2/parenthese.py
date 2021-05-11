# from queue import LifoQueue
def validParen(s):
    match = {'{':'}','(':')',"[":']'}
    stack = []
    for c in s:
        if c in match.keys():
            stack.append(c)
        # neu ma khong con phan tu nao trong stack tuc la co so ky tu la so le
        # neu con phan tu trong stack nhung k match
        elif not stack or match[stack.pop()] != c:
            return False
    #stack luc cuoi se khong con phan tu
    return not stack 

n = int(input())
for i in range(n):
    parenthese_str = input()
    if validParen(parenthese_str):
        print(1)
    else:
        print(0)
