def brute_multiply(a,b,n):
	
	c = [[0 for j in range(len(a[0]))] for i in range(len(a))]

	for i in range(0,n):
		for j in range(0,n):
			c_ij = 0
			for k in range(0,n):
				c[i][j] = c[i][j] + a[i][k] * b[k][j]

	return c

a = [[1,2],
	 [2,3]]
b = [[1,0],
	 [0,1]]

print brute_multiply(a,b,len(a))