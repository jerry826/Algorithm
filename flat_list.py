
# 铺平list
x = [1,2,7,34,[2,3,[1,2,3,[23],4,[22,33,1123,43],5]],5]
s = list(lists(x))
print(s)


def lists(x):
	i = 0
	while len(x)>i:
		if isinstance(x[i],int):
			yield x[i]
		else:
			x += x[i]
		i+=1




def s(a): 
	return sum((s(x) if type(x) is list else [x] for x in a), [])
print(s(x))