n, k = (int(s) for s in input().split(' '))
# Первая строчка была пропущена в письменном докладе! Это ввод чисел n и k, но это не влияет на идею алгоритма.

x = 1
for i in range(n+2, 2*n+1):
	x *= i
for i in range(1, n+1):
	x //= i
	x *= k
print(x)
