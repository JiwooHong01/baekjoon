import sys
def input(): return sys.stdin.readline().rstrip()

class Node():
    def __init__(self, data, prev = None, next = None):
        self.data = data
        self.prev = prev
        self.next = next

class DLL:
    def __init__(self):
        self.head = Node(None)
        self.tail = Node(None)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.curNode = self.tail
    def InsertNode(self, value):
        tmp = Node(value)
        self.curNode.prev.next = tmp
        tmp.prev = self.curNode.prev
        tmp.next = self.curNode
        self.curNode.prev = tmp
    def L(self):
        if self.curNode is not self.head.next:
            self.curNode = self.curNode.prev
    def D(self):
        if self.curNode is not self.tail:
            self.curNode = self.curNode.next
    def DeleteNode(self):
        if self.curNode is not self.head.next:
            self.curNode.prev = self.curNode.prev.prev
            self.curNode.prev.next = self.curNode
    
    def print(self):
        tmpnode = self.head.next
        while tmpnode != self.tail:
            print(tmpnode.data, end="")
            tmpnode = tmpnode.next


LL = DLL()

arr = input()
for a in arr:
    LL.InsertNode(a)
M = int(input())
for _ in range(M):
    arr1 = input()
    if arr1[0] == 'L':
        LL.L()
    elif arr1[0] == 'D':
        LL.D()
    elif arr1[0] == 'B':
        LL.DeleteNode()
    else:
        LL.InsertNode(arr1[2])

LL.print()