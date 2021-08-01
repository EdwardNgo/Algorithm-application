# goi dp[i] la so coin nho nhat phai dung khi tra i gia tri
# dp[0] = 0 
# dp[i] = dp[i-coin] + 1 for coin in coins if dp

def mincoin(coins,amount):
    dp = [999999]*(amount+1)
    dp[0] = 0
    for i in range(1,amount+1):
        for coin in coins:
            if i >= coin:
                sub_res = dp[i - coin]
                if sub_res != 999999 and sub_res + 1 < dp[i]:
                    dp[i] = sub_res + 1
    # print(dp)
    if dp[amount] == 999999:
        return -1
    else:
        return dp[amount]

# print(mincoin([1,2,5],11))

def mincostticket(days,costs):
    dp = [999999]*366
    dp[0] = 0
    class_type = [1,7,30]
    i=1
    while days[-1] - days[0] > 30*i:
        i+=1
        dp[days[-1]] = costs[2]*i
    if days[-1] - days[0] < 30:
        dp[days[-1]] = costs[2]
    # print(dp[days[-1]])
    for i in range(1,366):
        if i not in days:
            dp[i] = dp[i-1]
        for idx,j in enumerate(class_type):
            if i == 1:
                dp[i] = min(dp[i],costs[idx])
            if i - j >= 0:
                sub_res = dp[i-j]
                if sub_res != 999999 and sub_res + costs[idx] < dp[i]:
                    dp[i] = sub_res + costs[idx]
    # print(dp)
    return dp[days[-1]]

print(mincostticket(
[1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,24,25,27,28,29,30,31,34,37,38,39,41,43,44,45,47,48,49,54,57,60,62,63,66,69,70,72,74,76,78,80,81,82,83,84,85,88,89,91,93,94,97,99],[134,38,6]))