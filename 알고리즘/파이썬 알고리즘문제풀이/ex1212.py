import sys
word=sys.stdin.readline().rstrip()
print(bin(int(word,8))[2:]) # word, 2->진법