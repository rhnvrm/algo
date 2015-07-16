def insertionSort(ar):    
    n = len(ar)
    for j in xrange(1,n):
        key = ar[j]
        i = j - 1
        while i >= 0 and ar[i] > key:
            ar[i+1] = ar[i]
            i -= 1
        ar[i+1] = key
        print ' '.join(map(str, ar))
       
    return ""

m = input()
ar = [int(i) for i in raw_input().strip().split()]
insertionSort(ar)