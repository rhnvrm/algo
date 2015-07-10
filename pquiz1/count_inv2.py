def merge(left, right):
	i = 0
	j = 0
	res = []
	inversion = 0

	while i < len(left) and j < len(right):
		if left[i] <= right[j]:
			res.append(left[i])
        	i += 1
        else:
        	res.append(right[j])
        	j += 1
        	inversion += len(left[i:])


	res.extend(right[j:])
	res.extend(left[i:])

	return res, inversion


def count_inversions(l):
	if len(l) <= 1:
		return l,0

	else:
		middle = len(l)//2

		left, left_inversions = count_inversions(list(l[:middle]))
		right, right_inversions = count_inversions(list(l[middle:]))
		res, split_inversions = merge(left,right)

		return res, left_inversions + right_inversions + split_inversions

a = [6,5,4,3,2,1]
print(count_inversions(a))