L = int(input())

def com(n,k):
  res = 1
  k = min(k,n-k)
  for i in range(0,k):
    res *= (n-i)
    res //= (i+1)
  return res

l = L -12
print(com(l+11,l))

