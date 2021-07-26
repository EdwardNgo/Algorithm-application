def houserobber(nums):
    if len(nums) <= 2:
        return max(nums)
    dp = [0]*len(nums)
    dp[0] = nums[0]
    dp[1] = max(nums[0],nums[1])
    for i in range(2,len(nums)):
        dp[i] = max(dp[i-1],dp[i-2] + nums[i])
    print(dp)
    return max(dp)

print(houserobber([3,2,3,4]))

def houserobberII(nums):
    if len(nums) <= 2:
        return max(nums)
    dp1 = [0]*len(nums)
    dp1[0] = nums[0]
    dp1[1] = max(nums[0],nums[1])
    for i in range(2,len(nums)-1):
        dp1[i] = max(dp1[i-1],dp1[i-2] + nums[i])

    dp2 = [0]*len(nums)
    dp2[1] = nums[1]
    for i in range(2,len(nums)):
        dp2[i] = max(dp2[i-1],dp2[i-2] + nums[i])

    return max(max(dp1),max(dp2))
print(houserobberII([3,2,3,4]))