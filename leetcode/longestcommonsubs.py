def lcs(str1,str2):
    # dp[i][j] = lcs(i,j) do dai day con chung cua str1[0:i] va str2[0:j]
    dp = [[0]*(len(str2)+1) for i in range(len(str1)+1)]
    for i in range(len(str1)):
        for j in range(len(str2)):
            if str1[i] == str2[j]:
                dp[i+1][j+1] = dp[i][j] + 1
            else:
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j])
    print(dp)
    return dp[len(str1)][len(str2)]
print(lcs("abc","abcd"))