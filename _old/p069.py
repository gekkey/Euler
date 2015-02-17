#!/usr/bin/python
# -*- coding: UTF-8 -*-
from shared_functions import sieve
from math import sqrt, ceil
from time import time as t
from itertools import combinations as comb
from numpy import product as prod
N = 1000000
P = [i for i, e in enumerate(sieve(N)) if e]

def trialFactor(n, p=P):
	return [i for i in p[:999] if (n % i == 0)]

def phi(n):
	p = n - 1
	f = trialFactor(n)
	for i in range(1, len(f)+1):
		for a in comb(f, i):
			if i % 2 == 0:
				p += int((n-1)/prod(a))
			else:
				p -= int((n-1)/prod(a))
	return p

t1 = t()
lp = ln = 0
for n in range(2, N+1):
	cp = n/phi(n)
	if cp > lp: lp, ln = cp, n
print("largest n:",ln, "- n/phi(n) ratio:", lp)
print("time taken: ", int((t()-t1)), "s", sep='')
