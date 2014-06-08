def findKth(a,m,b,n,k):

	#always assume that m is equal or smaller than n
	if (m > n):
		return findKth(b, n, a, m, k)
	if (m == 0):
		return b[k - 1]
	if (k == 1):
		return min(a[0], b[0])
	#divide k into two parts
	pa = min(k / 2, m)
	pb = k - pa
	if (a[pa - 1] < b[pb - 1]):
		return findKth(a[pa:], m - pa, b, n, k - pa)
	elif (a[pa - 1] > b[pb - 1]):
		return findKth(a, m, b[pb:], n - pb, k - pb)
	else:
		return a[pa - 1]



def findMedianSortedArrays(A,B):
	  m = len(A)
	  n = len(B)
		total = m + n
		if (total%2==1):
			return findKth(A, m, B, n, total / 2 + 1)
		else:
			return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) / 2

