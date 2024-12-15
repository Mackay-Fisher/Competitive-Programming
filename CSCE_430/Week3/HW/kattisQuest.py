import queue
numInputs = int(input())
pq = queue.PriorityQueue()
output = []
indxs = set()
for j in range(numInputs):
    command = input().split()
    if len(command) ==2:
        queryval = int(command[1])
        goldv = 0
        idx = 0
        print(pq.queue)
        # for i in range(pq.qsize()):
        #     (energy,gold) = pq.queue[i]
        #     if j in indxs:
        #         continue
        #     gold = -gold
        #     energy = -energy
        #     if queryval >= energy:
        #         goldv += gold
        #         queryval -= energy
        #         indxs.add(i)
        #     else:
        #         idx+=1
        
        output.append(goldv)
        
    if len(command)==3:
        energy,gold = int(command[1]), int(command[2])
        pq.put(-energy,-gold)

for v in output:
    print(v)
    
    

