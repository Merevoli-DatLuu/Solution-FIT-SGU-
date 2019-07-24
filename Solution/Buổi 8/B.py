// Time: O(log10(P))
// Space: O(1)

t = int(input())

for i in range(1, t+1):
    n = int(input())
    P = int(input())
    print(P%n)
