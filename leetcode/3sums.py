# Problem 3 sums
def threesums(nums):
    if len(nums) < 3:
        return []
    sol = set()
    nums.sort()
    for i in range(len(nums)):
        value_dict = {}
        for j in range(i+1,len(nums)):
            if j == i: continue
            target = -nums[i] - nums[j]
            if target in value_dict:
                sol.add((nums[i],nums[j],target))
            else:
                value_dict[nums[j]] = 1
    sol = [list(num) for num in sol]
    return sol

def ksum(nums):
    pass
print(threesums([-1,0,1,2,-1,-4]))