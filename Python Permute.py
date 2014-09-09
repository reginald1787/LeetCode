def permute(num):
	n = len(num)
	if n<1:
		return []
	if n==1:
		return [num]
	res = []
	for i in range(n):
		back =  permute(num[:i]+num[i+1:])
		if back:
			for l in back:
				l.insert(0,num[i])
				if l not in res:
					res.append(l)

	return res
