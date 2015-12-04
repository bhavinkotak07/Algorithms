def anagramSolver(s1, s2):
    l1 = list(s1)
    l2 = list(s2)
    c1 = [0] * 26
    c2 = [0] * 26
    if len(l1) != len(l2):
        return False
    for i in range(len(l1)):
        c1[ord(l1[i]) - ord('a')] += 1
    for i in range(len(l2)):
        c2[ord(l2[i]) - ord('a')] += 1

    for i in range(26):
        if c1[i] != c2[i]:
            return False
    return True
