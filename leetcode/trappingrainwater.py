def solution(height):
    ans = 0
    for i in range(len(height)):
        left_max = 0
        right_max = 0
        for j in range(len(height)-1,-1,-1):
            left_max = max(left_max,height[j])
        for j in range(len(height)):
            right_max = max(right_max,height[j])
        print(left_max)
        print(right_max)
        ans += min(left_max,right_max) - height[i]
    return ans

print(solution([4,2,0,3,2,5]))