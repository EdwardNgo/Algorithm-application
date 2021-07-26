#O(n3)
def longestPalindrome(self, s: str) -> str:
    strlength = len(s)
    maxpalin = 1
    ans = s[0]
    for i in range(0,len(s)+1):
        for j in range(0,i):
            # print(j)
            # print(i)
            # print(s[j:i:] + "---" + s[i-1:j-1:-1])
            if(j - 1 < 0 ):
                if (s[j:i:] ==  s[i-1::-1]):
                # print("hi")
                    if(i-j > maxpalin):
                        maxpalin = i -j
                        ans = s[j:i:]
            else:
                if (s[j:i:] ==  s[i-1:j-1:-1]):
                    # print("hi")
                    if(i-j > maxpalin):
                        maxpalin = i -j
                        ans = s[j:i:]
    return ans 
#dynammic programming O(n2)
def printPretty(dp):
    for i in range(len(dp)):
        print(dp[i])

def longestPalindromeDp(s):
    res = s[0]
    maxlen = 1
    dp = [[False]*len(s) for _ in range(len(s))]
    for i in range(len(s)):
        dp[i][i] = True

    for i in range(len(s)-1):
        if s[i]==s[i+1]:
            dp[i][i+1] = True
    # printPretty(dp)

    for i in range(len(s)-1,-1,-1):
        # print(i)
        for j in range(i+1,len(s)):
            if dp[i][j] == False:
                if i+1 < len(s) and j-1 >= 0:
                    if dp[i+1][j-1] == True and s[i] == s[j]:
                        dp[i][j] = True
                    
    # printPretty(dp)

    for i in range(len(s)):
        for j in range(len(s)):
            if dp[i][j] == True:
                if j - i + 1 > maxlen:
                    res = s[i:j+1]
                    maxlen = j-i+1
    # print(res)
    return res

longestPalindromeDp("ccccccc")

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        # Form a bottom-up dp 2d array
        # dp[i][j] will be 'true' if the string from index i to j is a palindrome. 
        dp = [[False] * n  for _ in range(n)]
        
        ans = ''
        # every string with one character is a palindrome
        for i in range(n):
            dp[i][i] = True
            ans = s[i]
            
        maxLen = 1
        for start in range(n-1, -1, -1):
            for end in range(start+1, n):             
				# palindrome condition
                if s[start] == s[end]:
                    # if it's a two char. string or if the remaining string is a palindrome too
                    if end - start == 1 or dp[start+1][end-1]:
                        dp[start][end] = True
                        if maxLen < end - start + 1:
                            maxLen = end - start + 1
                            ans = s[start: end+ 1]
        
        return ans