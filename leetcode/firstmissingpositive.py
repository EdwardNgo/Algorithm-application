def firstMissingPositive(nums):
    if not nums:
        return 1
    
    h = {}
    
    for i in range(len(nums)):
        
        if nums[i]>=0 and nums[i] not in h:
            
            h[nums[i]] = 1

    for i in range(1,len(nums)+1):
        
        if i not in h:
            
            return i
        
        
    return i+1

print(firstMissingPositive([0,1,2]))