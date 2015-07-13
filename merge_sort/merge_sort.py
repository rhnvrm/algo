def merge(l, r):
	a = []
	
	while l and r:
		#print l,r
		if(l[0] < r[0]):
			a.append(l[0])
			l.pop(0)
		else:
			a.append(r[0])
			r.pop(0)

	a.extend(l)
	a.extend(r)

	return a

def merge_sort(a):
	n = len(a)
	#print n
	if(n <= 1): return a

	left = merge_sort(a[:n/2])
	right = merge_sort(a[n/2:])

	sol = merge(left,right)
	return sol

a = [6,5,4,3,2,1]
print merge_sort(a)