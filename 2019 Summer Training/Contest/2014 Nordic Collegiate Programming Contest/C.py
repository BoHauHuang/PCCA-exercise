n = int(input())

ans = 0
val = 1
pre = 1

# 1 1 2 5 14 42 132

num = [1, 1]

for i in range(2, n+1):
    val = (pre*(2*(2*(i-1)+1))//(i+1))
    pre = val
    num.append(val)

    
for e in range(n+1):
    ans += (num[e]*num[n-e])

print(ans)
