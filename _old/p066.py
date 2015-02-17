# For "https://projecteuler.net/problem=66"
# x**2 - D * y**2 = 1
# find D for D <= 1000 when x is largest
from math import sqrt, floor, ceil

def continuedFraction(S):
	# From "http://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion"
	m, d, a = [0], [1], [int(floor(sqrt(S)))]
	while a[-1] != a[0] * 2:
		m += [d[-1]*a[-1] - m[-1]]
		d += [int((S - m[-1]**2) / d[-1])]
		a += [int(floor((a[0] + m[-1]) / d[-1]))]
	return a

def pell(D):
	# From "http://mathworld.wolfram.com/PellEquation.html"
	if sqrt(D) % 1 == 0: return False 		# Skip perfect squares; they will divide by zero
	a = continuedFraction(D)
	n = 2
	r = len(a)-2							# `r' is the second to last
	r = 2*r+1 if r % 2 == 0 else r
	a += a[1:]*int(r/(len(a)))
	p, q = [a[0], a[0]*a[1]+1], [1, a[1]] 	# convergents `p' and `q' will be the solution for x and y at `r'
	while n <= r:
		p += [a[n]*p[n-1]+p[n-2]]
		q += [a[n]*q[n-1]+q[n-2]]
		n += 1
	return [(p[i], q[i]) for i in range(len(p))]

def problem():
	lV, lD = 0, 0
	for i in range(2, 1000+1):
		s = pell(i)
		if not s: continue
		if s[-1][0] > lV: lV, lD = s[-1][0], i
	return lD


"""This is a long string"""
"This is a normal string"
@decorator
True
function()
def functionName(var1, va2):
class className(inheritedClass):
for x in range(loop):

# A demonstration of reaching the answer
D = problem()
print("pell(", D, ") = ", continuedFraction(D), sep='')
p = pell(D)
for a, b in p:
	print(a, "^2 - ", D, "*", b, "^2 = ", (a**2 - D*b**2), sep='')
