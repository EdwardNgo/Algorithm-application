def jumgameI(nums):
    max_index = 0
    for idx,num in enumerate(nums):
        if idx > max_index:
            return False
        max_index = max(max_index,num+idx)
    return True

# def jumgameII(nums):
#     n = len(nums)
#     dp = [999999]*n
#     dp[0] = 0
#     dp[1] = 1
#     for i in range(2,n):
#         if nums[i-1] + 
#         dp[i] = min(dp[i],dp[i-1] + 1)
#     print(dp)
#     return dp[-1]
nums = [2,3,0,1,4]
visited = [False]*len(nums)
pos = []
count = 0
min_count = 9999999
def _try(i):
    global count 
    global min_count
    for j in range(1,nums[i] + 1):
        count = count + 1
        print(i)
        if i >= len(nums) - 1:
            min_count = min(min_count,count)
            print('-')
            break
        else:
            _try(i+j)
        count = 0
        # pos.pop()
    return min_count

#min_jumps la so buoc ngan nhat toi index i
#DP thi van la O(n2) thoi
def jumpgameII(nums):
    min_jumps = [999999 for _ in range(len(nums))]
    min_jumps[0] = 0
    for i in range(1,len(nums)):
        for j in range(i):
            if i - j <= nums[j]:
                min_jumps[i] = min(min_jumps[i],min_jumps[j]+1)
    # print(min_jumps)
    return min_jumps[-1]

#Tham lam ta coi 1 lan di co dang [left,right] va buoc di xa nhat la farthest. Sau moi buoc di ta tang left,steps len 1 va right thanh farthest

def jumpgame_greedy(nums):
    left = right = 0
    steps = 0
    farthest = 0
    while right < len(nums) - 1:
        for i in range(left,right+1):
            farthest = max(farthest,nums[i]+i)
        left = left + 1
        right = farthest
        steps = steps + 1
    # print(steps)
    return steps


if __name__ == "__main__":
    # jumpgameII([2,3,0,1,4])
    jumpgame_greedy([2,3,0,1,4])