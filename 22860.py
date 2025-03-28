import sys
sys.setrecursionlimit(10**6)
class Node:
    # cur : node name
    # flag : 0 is file, 1 is folder
    # children : children list
    def __init__(self, cur, flag, parent= None, next = None):
        self.cur = cur
        self.flag = flag
        self.parent = parent
        
        self.children = []
        if next is not None:
            self.children.append(next)
    def addchild(self, child):
        self.children.append(child)

def count(start, s):
    # count files(total num, set)
    cnt = 0
    for child in start.children:
        if child.flag == 0:
            s.add(child.cur)
            cnt += 1
            
        else:
            ret, s = count(child, s)
            cnt += ret
    return cnt, s


n, m = map(int, input().split())
head = Node("head", 1)
main = Node("main", 1, "head")
head.addchild(main)

# nodes = saving all nodes
nodes = [head, main]

for _ in range(n+m):
    up, cur, flag = input().split()
    flag = int(flag)
    node = Node(cur, flag, up)
    nodes.append(node)
    for elem in nodes:
        if elem.cur == up:
            elem.addchild(node)
        if elem.parent == cur:
            node.addchild(elem)
    

# start query
q = int(input())

for _ in range(q):
    path = list(input().split('/'))
    start = head
    for name in path:
        for elem in start.children:
            if elem.cur == name:
                start = elem
                break
    # set : remove all duplicating elements
    s = set()
    ans, s = count(start, s)
    print(len(s), ans)
