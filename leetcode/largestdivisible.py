def largestdivisible(nums):
    n = len(nums)
    nums.sort()
    sol = [[num] for num in nums]
    # print(sol)
    for i in range(n):
        for j in range(i):
            if nums[i]%nums[j] == 0 and len(sol[i]) < len(sol[j])+1:
                sol[i] = sol[j] + [nums[i]]
    # print(sol)
    ans = max(sol,key=len)
    ans.sort()
    return ans

            
print(largestdivisible([1,2,3,4,6,24]))
