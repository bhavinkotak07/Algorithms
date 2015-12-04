def max(a, b):
    if a  > b:
        return a
    return b
def knapSack(W, val, w, n):
    if w == 0 or n == 0:
        return 0
    if wt[n - 1] > W:
        return knapSack(W, val, w, n-1)
    else:
        return max(val[n-1] + knapSack(W - w[n-1], val, w, n-1), knapSack(W, val, w, n-1))
    
#515514300143
