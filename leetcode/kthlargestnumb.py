def solution(nums,k):
    nums.sort()
    return nums[-k]

def findminrotated(nums):
    left,right = 0, len(nums) - 1
    while left < right:
        mid = (left + right ) // 2
        if nums[mid] > nums[right]:
            left = mid + 1
        elif nums[mid] == nums[right]:
            right = right - 1
        else:
            right  = mid
    print(left)
    print(right)
    return nums[left]

findminrotated([1,3,3])