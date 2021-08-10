def solution(arr,k):
    transform = []
    while(k > 0):
        for i in arr:
            transform.append(i)
        k = k - 1
    print(transform)
    max_current = transform[0]
    max_so_far = transform[0]
    for i in range(1,len(transform)):
        max_current = max(transform[i],transform[i]+max_current)
        max_so_far = max(max_so_far,max_current)
    return max_so_far

def solution2(arr,k,mod = 10**9+7):
    def Kadane(arr):
        cur = 0
        res = 0
        for num in arr:
            cur = max(num, num + cur)
            res = max(res,  cur)
        return res
    print(Kadane(arr*2))
    return ((k - 2) * max(sum(arr), 0) + Kadane(arr * 2)) % mod if k > 1 else Kadane(arr) % mod
solution2([1,2],3)