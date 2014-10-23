# aliases, for brevity
p1,p2 = 'p1','p2'
cond = {
	'high'	:'01',
	'1pair'	:'02',
	'2pair'	:'03',
	'3kind'	:'04',
	'strait':'05',
	'flush'	:'06',
	'house'	:'07',
	'4kind'	:'08',
	'sflush':'09',
	'rflush':'10'
}
rcond = [False, 'high card', '1 pair', '2 pairs', '3 of a kind', 'straight', 'flush', 'full house', '4 of a kind', 'straight flush', 'royal flush']
def anal_cond(hand): # returns analysis of hand
	# returns an int of the value of the hand
	# value is held in 8 pairs of 2 digits
 #### cond, bigpair, smallpair, all cards hi-to-lo

	# find duplicates and suit
	dup = [0] * 15
	h = []
	s = '?'
	for i, e in enumerate(hand):
		c = int(e[:-1])
		if s == '?': s = e[-1:]
		if s != e[-1:]: s = False
		dup[c] += 1
		h += [c]
	# make `h' into 2 digit pairs of unique card values, ordered highest to lowest
	h = ''.join([('0' if x < 10 else '') + str(x) for x in sorted(list(set(h)))[::-1]])
	h += '00' * (5 - len(h)/2)
	# check for straight
	st = False
	for i in range(2, 10):
		if 0 not in dup[i:i+5] and sum(dup[i:i+5]) == 5:
			st = True

	# royal flush
	if sum(dup[-5:]) == 5 and s != False:
		return int(cond['rflush'] + '00'*2 + h)
	# straight flush
	if s != False and st == True:
		return int(cond['sflush'] + '00'*2 + h)
	# four of a kind
	if 4 in dup:
		bp = dup.index(4)
		return int(cond['4kind'] + ('0' if bp < 10 else '') + str(bp) + '00' + h)
	# full house
	if 3 in dup and 2 in dup:
		bp,sp = dup.index(3),dup.index(2)
		return int(cond['house'] + ('0' if bp < 10 else '') + str(bp) + ('0' if sp < 10 else '') + str(sp) + h)
	# flush
	if s != False:
		return int(cond['flush'] + '00'*2 + h)
	# straight
	if st == True:
		return int(cond['strait'] + '00'*2 + h)
	# three of a kind
	if 3 in dup:
		bp = dup.index(3)
		return int(cond['3kind'] + ('0' if bp < 10 else '') + str(bp) + '00' + h)
	if dup.count(2) == 2:
		dup = [i for i in range(15) if dup[i] == 2]
		bp,sp = dup[0], dup[1]
		if sp > bp: bp,sp = sp,bp
		return int(cond['2pair'] + ('0' if bp < 10 else '') + str(bp) + ('0' if sp < 10 else '') + str(sp) + h)
	if 2 in dup:
		bp = dup.index(2)
		return int(cond['1pair'] + ('0' if bp < 10 else '') + str(bp) + '00' + h)
	return int(cond['high'] + '00'*2 + h)

# read cases and split into hands 
cases = [{p1:x.split(' ')[:5], p2:x.split(' ')[5:]} for x in open('poker.txt', 'r').read().split('\n')]
for i, e in enumerate(cases): # convert face cards to values
	for p in [p1, p2]:
		for j, f in enumerate(e[p]):
			# e[p] is the hand; `f' is the card
			# `i' is case num;  `j' is card num
			if   f[:1] == 'T': cases[i][p][j] = f.replace('T', '10')
			elif f[:1] == 'J': cases[i][p][j] = f.replace('J', '11')
			elif f[:1] == 'Q': cases[i][p][j] = f.replace('Q', '12')
			elif f[:1] == 'K': cases[i][p][j] = f.replace('K', '13')
			elif f[:1] == 'A': cases[i][p][j] = f.replace('A', '14')
			else : cases[i][p][j] = '0' + cases[i][p][j]

#print anal_cond(cases[0][p1])
counter = 0
for e in cases:
	h1,h2 = anal_cond(e[p1]),anal_cond(e[p2])
	r1, r2 = rcond[int(str(h1)[:-14])], rcond[int(str(h2)[:-14])]
	#print '\n', e[p1], 'VS', e[p2]
	if h1 > h2:
		#print ' '*((35-8-len(r1))/2) + '*** ' + r1.upper() + ' ***' + ' '*((35-8-len(r1))/2+1) + '  ' + ' '*((35-len(r1))/2) + r2 + ' '*(35-(35-len(r1))/2+1)
		counter += 1
	else:
		pass#print ' '*((35-len(r1))/2) + r1 + ' '*((35-len(r1))/2+1) + '  ' + ' '*((35-8-len(r1))/2) + '*** ' + r2.upper() + ' ***' + ' '*(35-(35-8-len(r1))/2+1)
print counter