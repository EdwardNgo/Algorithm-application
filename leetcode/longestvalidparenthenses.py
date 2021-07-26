
def is_valid(parenthense_str):
    stack = []
    if len(parenthense_str) % 2 == 1:
        return False
    else:
        for child in parenthense_str:
            if child == "(":
                stack.append(child)
            elif child == ")" and len(stack) > 0:
                stack.pop()
            else:
                return False
    return len(stack) == 0

# 0(n^3)
def longest_valid_parenthenses(parenthense_str):
    n = len(parenthense_str)
    ans = 0
    for i in range(n+1):
        for j in range(i+1):
            if is_valid(parenthense_str[j:i]):
                # print(parenthense_str[j:i])
                # print(j)
                # print(i)
                if i-j > ans:
                    ans = i-j
    return ans 
# dp 0(n^2)
# goi dp[i] la do dai day ngoac ok ket thuc tai i. i luon phai la ")" 
# TH1: i-1 la "(": dp[i] = dp[i-2] + 2 .....()
# TH2: i-1 la ")": neu s[i-dp[i-1]-1] = "(" ->  dp[i] = dp[i-1] + dp[i - dp[i-1] - 2] + 2
def longest_valid_parenthenses_dp(parenthense_str):
    n = len(parenthense_str)
    ans = 0
    dp = [0]*n
    for i in range(1,n):
        if parenthense_str[i] == ")":
            if parenthense_str[i-1] == "(":
                if i >= 2:
                    dp[i] = dp[i-2] + 2
                else:
                    dp[i] = 2
            elif parenthense_str[i - dp[i-1] - 1] == "(" and i - dp[i-1] > 0:
                if i - dp[i-1] >= 2:
                    dp[i] = dp[i-1] + dp[i - dp[i-1] - 2] + 2
                else:
                    dp[i] = dp[i-1] + 2
        print(dp)
        ans = max(ans,dp[i])
    return ans
print(longest_valid_parenthenses_dp("()(())")) 
# print(longest_valid_parenthenses_dp("()(())")) - ans:6