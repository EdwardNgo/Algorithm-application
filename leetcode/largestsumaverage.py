#DP[i][j] la gia tri lon nhat cua day ket thuc tai i va co j nhat cat
#DP[i][0] = avg(arr[:i+1])
#DP[0][j] = 0
#DP[i][j] = max(dp[i][j],dp[k][j-1] + avg(arr[k+1:i+1])) voi k chay tu 0 den i - 1
def solution(nums,K):
    def avg(arr):
        return sum(arr)/len(arr)
    dp = [[0 for _ in range(K)] for _ in range(len(nums))]
    dp[0][0] = nums[0]
    for i in range(len(nums)):
        for j in range(K):
            if j == 0:
                dp[i][j] = avg(nums[:i+1])
            else:
                for k in range(i):
                    #vi tri cac nhat cat 
                    #dp[k][j-1] la nhat cat thu i-1 va tai diem k
                    #avg la gia tri dat duoc phia sau k
                    dp[i][j] = max(dp[i][j],dp[k][j-1] + avg(nums[k+1:i+1]))

    return dp[len(nums) - 1][K-1]

print(solution([9,1,2,3,9],3))