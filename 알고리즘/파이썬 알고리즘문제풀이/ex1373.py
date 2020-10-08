import sys
word=sys.stdin.readline().rstrip()
print(oct(int(word,2))[2:]) # word, 2->진법