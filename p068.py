# Magic n-gon ring
SIDES = 5
DIGITS = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
# correct_ring = [[3, 2, 1], [4, 6, 5]]  

from itertools import permutations as perm, combinations as comb

ring = [[0]*SIDES, [0]*SIDES] # ring[inner ring, outer ring] starting top moving clockwise
digits = [sorted(DIGITS + x) for x in [x for x in comb(DIGITS, 5)]]
perms = [x for x in perm(digits[0])]
print(len(perms))