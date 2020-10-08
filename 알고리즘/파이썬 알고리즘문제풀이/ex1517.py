import sys
sys.setrecursionlimit(10**9)
n=int(sys.stdin.readline().rstrip())
arr=list(map(int,sys.stdin.readline().split()))
swap=0

#merge_sort를 몇 번 했느냐가 답이다


def merge_sort(start,end):
    global swap, arr
    siz=end-start
    mid=(start+end)//2
    if siz<=1:
        return
    merge_sort(start,mid)
    merge_sort(mid,end)
    cnt=0
    idx1,idx2=start,mid
    new_arr=[]
    while idx1<mid and idx2<end:
        if arr[idx1]>arr[idx2]:
            new_arr.append(arr[idx2])
            idx2+=1
            cnt+=1
        else:
            new_arr.append(arr[idx1])
            idx1+=1
            swap+=cnt
    while idx1<mid:
        new_arr.append(arr[idx1])
        idx1+=1
        swap+=cnt
    while idx2<end:
        new_arr.append(arr[idx2])
        idx2+=1
    for k in range(len(new_arr)):
        arr[start+k]=new_arr[k]
merge_sort(0,n)
print(swap)

