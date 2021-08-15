# Remove All Adjacent Duplicates in String II	
def remove_adjacent_dup(s,k):
    stack = []
    count = 1
    stack.append(s[0])
    print(stack)
    for i in range(1,len(s)):
        if len(stack) > 0 and s[i] == stack[-1]:
            count = count + 1
        else:
            count = 1
        
        stack.append(s[i])

        if count == k:
            for _ in range(k):
                stack.pop()
            count = 1
    print(len(stack))
    newstr = "".join(stack)

    return newstr if newstr == s else remove_adjacent_dup(newstr,k)

remove_adjacent_dup("aaaa",2)

def remove_adjacent_dup_2(s,k):
	stack = []
	for ch in s:
		if not stack or stack[-1][0] != ch:
			stack.append([ch, 1])
		else:
			stack[-1][1] += 1
			if stack[-1][1] == k: stack.pop()
	return ''.join(ch * cnt for ch, cnt in stack)