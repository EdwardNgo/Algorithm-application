import math
def countingbits(number):
    dp = [0]
    for i in range(1, number + 1):
        if i % 2 == 1:
            dp.append(dp[i - 1] + 1)
        else:
            dp.append(dp[i // 2])
    return dp

print(countingbits(16))