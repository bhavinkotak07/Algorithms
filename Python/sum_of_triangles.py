test = int(raw_input())
def maximum(a , b):
    if a > b:
        return a
    return b
for i in range(0, test):
    n = input()
    list1 = []
    
    for j in range(0, n):
        line = raw_input()
        data = line.split()
        for i in range(0, len(data)):
            data[i] = int(data[i])
        list1.append(data)
    len1 = len(list1)

    for i in range(0,len1):
        len2 = len(list1[i])
        for j in range(0,len2):
            if i == 0:
                list1[i][j] = list1[i][j]
            elif j == 0:
                list1[i][j] += list1[i-1][j]
            elif j == len2 -1 :
                list1[i][j] += list1[i-1][j-1]
            else:
                list1[i][j] += maximum(list1[i-1][j], list1[i-1][j-1])
    max = 0
    for i in range(0, len(list1[len1-1])):
        if list1[len1-1][i] > max:
            max = list1[len1-1][i]
    print max
        
         


