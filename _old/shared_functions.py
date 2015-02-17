from math import sqrt

def sieve(n):
	P = [True]*(n+1)
	P[0] = P[1] = False
	for i in range(2, int(sqrt(n))+1):
		if P[i]:
			for j in range(i**2, n, i):
				P[j] = False
	return P