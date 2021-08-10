def sortSentence(sentence):
    words = sentence.split(" ")
    res = [0]*len(words)
    idx = [word[-1] for word in words]
    # print(words)
    # print(res)
    # print(idx)
    for i in range(len(idx)):
        res[int(idx[i])-1] = words[i][:-1]
    return " ".join(res)
sortSentence("is2 sentence4 This1 a3")

import re
def lengthLastWord(sentence):
    sentence = sentence.strip()
    words = re.split("\s+", sentence)
    print(words)
    return len(words[-1])

lengthLastWord("   fly me   to   the moon  ")