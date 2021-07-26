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
btbuysellstockII([7,1,5,3,6,4])
