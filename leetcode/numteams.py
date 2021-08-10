def solution(nums):
    if len(nums) < 3:
        return 0

    res = 0
    greater = [0]*len(nums)#so luong phan tu phia truoc lon hon phan tu o vi tri i trong mang nums
    less = [0]*len(nums)

    for i in range(len(nums) - 1):
        for j in range(i+1,len(nums)):
            if nums[j] > nums[i]:
                greater[i] += 1
            else:
                less[i] += 1
    print(greater)
    print(less)
    for i in range(len(nums) - 2):
        for j in range(i+1,len(nums)):
            if nums[j] > nums[i]:
                res +=  greater[j]
            else:
                res += less[j]
    
    return res

print(solution([2,5,3,4,1]))