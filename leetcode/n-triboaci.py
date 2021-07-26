def tribonaci(n):
    dp = [0]*38
    dp[0] = 0
    dp[1] = 1
    dp[2] = 1

    for i in range(3,n+1):
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]

    return dp[n]

print(tribonaci(25))

def getMaximumGenerated(n):
    nums = [0]*101
    nums[0] = 0
    nums[1] = 1
    i = 1
    while  i*2+1<=n:
        nums[i*2] = nums[i]
        nums[i*2+1] = nums[i]+nums[i+1]
        i+=1

    print(nums)
    return max(nums[0:n+1])

print(getMaximumGenerated(0))
