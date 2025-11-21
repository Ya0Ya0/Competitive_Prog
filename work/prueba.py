# def func():
#     dic = [(0,"asd")]
#     with open("coding_qual_input.txt") as file:
#         for line in file:        
#             number, word = line.split()
#             dic.append((int(number),word))
#     words = len(dic)
#     step = 2
#     cur = 1
#     ans = ""
#     dic = sorted(dic)
#     while(cur <= words):
#         ans += dic[cur][1] + " "
#         cur += step
#         step += 1
#     ans = ans[:-1]
#     return ans

# print(func())
def func():
    dic = {}
    with open("coding_qual_input.txt") as file:
        for line in file:        
            number, word = line.split()
            dic[int(number)] = word 
    words = len(dic)
    step = 2
    cur = 1
    ans = ""
    while(cur <= words):
        ans += dic[cur] + " "
        cur += step
        step += 1
    ans = ans[:-1]
    return ans

print(func())