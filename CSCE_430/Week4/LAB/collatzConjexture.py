from collections import defaultdict
inputLines=[]
while True:
    res = input().split()
    res = list(map(int, res))
    v1,v2 = res[0],res[1]
    if v1 == 0 and v2 == 0:
        break
    steps = defaultdict(int)
    set1 = set()
    set2 = set()
    set1.add(v1)
    set2.add(v2)
    path1 = defaultdict(int)
    path2 = defaultdict(int)
    path1[v1] = 0
    path1[v2] = 0
    cur1,cur2 = v1,v2
    prev1,prev2 = v1,v2
    intersection_val = -1
    while True:
        if cur1 != 1:
            cur1 = cur1 // 2 if cur1 % 2 == 0 else 3 * cur1 + 1
            set1.add(cur1)
            path1[cur1]  = path1[prev1] + 1 
            prev1 = cur1
            if cur1 in set2:
                intersection_val = cur1
                break
            
        if cur2 != 1:
            cur2 = cur2 // 2 if cur2 % 2 == 0 else 3 * cur2 + 1
            set2.add(cur2)
            path2[cur2]  = path2[prev2] + 1 
            prev2 = cur2
            if cur2 in set1:
                intersection_val = cur2
                break
    print(f"{v1} needs {path1[intersection_val]} steps, {v2} needs {path2[intersection_val]} steps, they meet at {intersection_val}")
    