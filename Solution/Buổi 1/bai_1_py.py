# Time: O(n)
# Space: O(n)

n = int(input())
a = [int(s) for s in input().split(' ')]
a.insert(0, -0x3f3f3f3f)
L = []
L.append(0)

res = 0

for i in range(n):
    max_L = 0;
    for j in range(i+1):
        if (a[i + 1] >= a[i - j] and max_L < L[i - j]):
            max_L = L[i - j]
    L.append(max_L + 1)
    if (res < L[i + 1]):
        res = L[i + 1]

print(res)

