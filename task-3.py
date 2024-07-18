x = 1
for i in range(n+2, 2*n+1):
	x *= i
for i in range(1, n+1):
	x //= i
	x *= k
print(x)
