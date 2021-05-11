def findSum(str1, str2): 
	
	if (len(str1) > len(str2)): 
		t = str1; 
		str1 = str2; 
		str2 = t; 

	str = ""; 

	n1 = len(str1); 
	n2 = len(str2); 

	str1 = str1[::-1]; 
	str2 = str2[::-1]; 

	carry = 0; 
	for i in range(n1): 
		
		sum = ((ord(str1[i]) - 48) +
			((ord(str2[i]) - 48) + carry)); 
		str += chr(sum % 10 + 48); 

		carry = int(sum / 10); 

	for i in range(n1, n2): 
		sum = ((ord(str2[i]) - 48) + carry); 
		str += chr(sum % 10 + 48); 
		carry = (int)(sum / 10); 

	if (carry): 
		str += chr(carry + 48); 

	str = str[::-1]; 

	return str; 

# str1 = input()
# str2 = input()
# print(findSum(str1, str2)); 

def addmod(a,b):
    return (a+b) % (10^9+7)

# a = input()
# b = input()
# print(addmod(a, b))

def setBitMap(arr1,arr2):
    res1 = 1
    res2 = 1
    for i in arr1:
        print(res1 << i)
        res1 = res1 or res1 << i
    for i in arr2:
        res2 = res2 or res2 << i
    print(res1,res2)

setBitMap([0,1,2],[3,4,5])

letterMap = {'a':1, 'b':2, 'c':3,'d':1,'e':2, 'f':3,'g':1, 'h':2, 'i':3,'j':1,'k':2,'l':3,'m':1,'n':2,'o':3,'p':1,'q':2,'r':3,'s':4,'t':1,'u':2,'v':3,'w':1,'x':2,'y':3,'z':'4',' ':1}
def getPressNum(str):
    words = str.split(' ')
    letters = list(str)
    total = 0
    for letter in letters:
        total += letterMap[letter]
    return total
def wordTooLong(word):
    if (len(word) < 10):
        return word
    else:
        return word[1] + str(len(word) - 2) + word[-1]

# example = int(input())
# arr = []
# for i in range(1,example + 1):
#     word = input()
#     res = getPressNum(str)
#     arr.append(res)
#     # print(f'Case #{i}: {res}')
# for i in range(1,example + 1):
#     # word = input()
#     # res = getPressNum(str)
#     # arr.append(res)
#     print(f'Case #{i}: {res}')

a = int(input())
arr = []
for i in range(a):
    ele = input()
    arr.append(ele)
arr.sort()
for i in arr:
    print(i)