#!/usr/bin/python
# -*- coding: UTF-8 -*-
from shared_functions import sieve
from math import sqrt
from time import time as t
from itertools import combinations as comb, permutations as perm
from numpy import product as prod
N = 10000000
t1 = t()
P = [i for i, e in enumerate(sieve(N)) if e]
print( int((t() - t1)*1000), 'ms taken to generate ', len(P), ' primes less than 10,000,000' '.', sep='')

def trialFactor(n, p=P):
	lim = int(sqrt(n))
	for i in P:
		if i >= lim:
			lim = P.index(i)
			break
	return [i for i in p[:lim] if (n % i == 0)]

def φ(n):
	p = n - 1
	f = trialFactor(n)
	for i in range(1, len(f)+1):
		for a in comb(f, i):
			if i % 2 == 0: 
				p += int((n-1)/prod(a))
			else:
				p -= int((n-1)/prod(a))
	return p

print(list(perm('ABCD')))