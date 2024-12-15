import re

values = input()
re.split(', ')
print(values)
# stackFront = 0
# stackBack =0
# print(values)
# for v in values:
#     if v[0]=='{':
#         stackFront +=1
#         print(v[0])
#         v = v[1::]
#         for _ in range(stackFront):
#             print("  ",end="")
#         print(f"{v},")
#     if v[len(v)-1] =='}':
#         x = v[:len(v)-1]
#         for _ in range(stackFront):
#             print("  ",end="")
#         print(f"{x}")
#         print(v[len(v)-1])
#         stackFront -= 1
#     for _ in range(stackFront):
#         print("  ",end="")
#     print(f"{v},")
    
        
