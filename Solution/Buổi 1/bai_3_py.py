# Time: O(n)
# Space: O(n)

n = int(input())
a = [int(s) for s in input().split(' ')]

X = a
res = -0x3f3f3f3f
for i in range(n - 1):
    X[i + 1] = max(X[i + 1], X[i] + a[i + 1])
    if (res < X[i + 1]):
        res = X[i + 1]

print(res)
