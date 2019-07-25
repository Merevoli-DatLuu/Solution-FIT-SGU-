# Time: O(n*log(n))
# Space: O(n)

n = int(input())
a = [int(s) for s in input().split(' ')]

a.sort()
res = 0x3f3f3f3f
for i in range(n - 1):
    if (a[i + 1] - a[i] < res):
        res = a[i + 1] - a[i]
        
print(res)
