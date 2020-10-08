import sys
word=sys.stdin.readline().rstrip()
arr=[]
for i in word:
    if i.islower():
        tmp=ord(i)+13
        if tmp>122:
            tmp-=26
        tmp=chr(tmp)
        arr.append(tmp)
    if i.isupper():
        tmp=ord(i)+13
        if tmp>90:
            tmp-=26
        tmp=chr(tmp)
        arr.append(tmp)
    if i.isspace():
        arr.append(i)
    if i.isdigit():
        arr.append(i)
ans=''.join(arr)
print(ans)
