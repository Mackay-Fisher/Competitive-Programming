"""
All you need to know is how many teams are above team 1 
you dont need to keep track of relative ranks of teams 

for every team keep # solved and the penalty 

if not team 1 solving:
    did it move from below team 1 to above 
    if yes then add to:
        list (unsorted list) of teams above team 1 
This is an order 1 operation

Team 1 solves:
    - update its info 
    - go through the list and see whether to remove each 
    O(k) operation 

"""

n, m = map(int, input().split())

lines = []
for i in range(m):
    t, p = map(int, input().split())
    lines.append((t, p))

team_stats = [[0, 0] for i in range(n)]
teams_above = set()

for t, p in lines:
    team_stats[t-1][0] += 1
    team_stats[t-1][1] += p
    if t == 1:
        to_remove = []
        # find indexes to remove since we cannot remove while iterating
        for t_idx in teams_above:
            if team_stats[t_idx][0] < team_stats[0][0] or (team_stats[t_idx][0] == team_stats[0][0] and team_stats[t_idx][1] >= team_stats[0][1]):
                to_remove.append(t_idx)
        for i in to_remove:
            teams_above.remove(i)
    else:
        if team_stats[t-1][0] > team_stats[0][0] or (team_stats[t-1][0] == team_stats[0][0] and team_stats[t-1][1] < team_stats[0][1]):
            teams_above.add(t-1)
    print(len(teams_above)+1)