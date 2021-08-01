def btbuysellstockI(price):
    n = len(price)
    minprice = 999999
    maxprofit = 0
    for i in range(n):
        if (price[i] < minprice):
            minprice = price[i]
        elif (price[i] - minprice > maxprofit):
            maxprofit = price[i] - minprice
    return maxprofit

btbuysellstockI([7,1,5,3,6,7])

def btbuysellstockII(price):
    n = len(price)
    maxprofit = 0
    i = 0
    valley = price[0]
    peak = price[0]
    while i < n-1:
        # print(i)
        while i < n-1 and price[i] >= price[i+1]:
            i += 1
        valley = price[i]
        # print("Valley: ",i) 
        # print(price[i])  
        while i < n-1 and price[i] <= price[i+1]:
            i += 1
        peak = price[i]
        # print("Peak: ",i)   
        maxprofit += peak-valley
    # print(maxprofit)
    return maxprofit

def btbuysellstockIII(price):
    one_buy_profit = -99999
    one_buy_one_sell_profit = 0
    two_buy_profit = -999999
    two_buy_two_sell_profit = 0
    a,b,c,d = [[],[],[],[]]
    for i in price:
        current_price = i
        one_buy_profit = max(one_buy_profit,0 - current_price)
        one_buy_one_sell_profit = max(one_buy_one_sell_profit,current_price + one_buy_profit)
        two_buy_profit = max(two_buy_profit,one_buy_one_sell_profit - current_price)
        two_buy_two_sell_profit = max(two_buy_two_sell_profit,two_buy_profit + current_price)
        a.append(one_buy_profit)
        b.append(one_buy_one_sell_profit)
        c.append(two_buy_profit)
        d.append(two_buy_two_sell_profit)
    for i in [a,b,c,d]:
        print(i)
    return max(one_buy_one_sell_profit,two_buy_two_sell_profit)

def btbuysellstockIV(price,k):
    sell = [0]*(k+1)
    buy = [-99999]*(k+1)
    for pr in price:
        for i in range(1,k+1):
            buy[i] = max(buy[i],sell[i-1] - pr)
            sell[i] = max(sell[i],buy[i] + pr)
    return sell[k]
print(btbuysellstockIII([1,2,4,2,5,7,2,4,9,0]))
