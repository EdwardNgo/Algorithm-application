letterMap = {'a':1, 'b':2, 'c':3,'d':1,'e':2, 'f':3,'g':1, 'h':2, 'i':3,'j':1,'k':2,'l':3,'m':1,'n':2,'o':3,'p':1,'q':2,'r':3,'s':4,'t':1,'u':2,'v':3,'w':1,'x':2,'y':3,'z':'4',' ':1}
def getPressNum(msg):
    # letters = list(msg)
    total = 0
    for letter in msg:
        try:
            total += letterMap[letter]
        except:
            continue
    return total

example = input()
arr = []
for i in range(1,int(example) + 1):
    msg = input()
    res = getPressNum(msg)
    print(f'Case #{i}: {res}')
# for i in range(0,int(example)):
#     print('Case #{i}: {res}'.format(i = i+1,res = arr[i]))