import sys
while True:
    word=sys.stdin.readline().rstrip('\n')
    if not word:
        break
    small=0
    big=0
    split_cnt=0
    digits=0
    for item in word:
        if 97<=ord(item)<=122:
            small+=1
        elif 65<=ord(item)<=90:
            big+=1
        elif item==' ':
            split_cnt+=1
        elif item.isdigit():
            digits+=1
    print(small, big, digits, split_cnt)