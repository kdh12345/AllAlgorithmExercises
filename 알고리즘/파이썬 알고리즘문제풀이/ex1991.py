import sys
class node:
    def __init__(self,item,left,right):
        self.item=item
        self.left=left
        self.right=right

arr= {}

def preOrder(node):
    print(node.item,end='')
    if node.left!='.':
        preOrder(arr[node.left])
    if node.right!='.':
        preOrder(arr[node.right])

def inOrder(node):
    if node.left!='.':
        inOrder(arr[node.left])
    print(node.item,end='')
    if node.right!='.':
        inOrder(arr[node.right])


def lastOrder(node):
    if node.left!='.':
        lastOrder(arr[node.left])
    if node.right!='.':
        lastOrder(arr[node.right])
    print(node.item,end='')

n=int(sys.stdin.readline().rstrip())
for i in range(n):
    a,b,c=map(str,sys.stdin.readline().split())
    arr[a]=node(item=a,left=b,right=c)
preOrder(arr['A'])
print()
inOrder(arr['A'])
print()
lastOrder(arr['A'])