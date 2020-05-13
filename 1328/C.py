# your code goes here
for _ in range(int(input())):
	n=int(input())
	x=input()
	a=""
	b=""
	flag=0
	for c in x:
		if flag==0:
			if c=='2':
				a+="1"
				b+="1"
			elif c=='1':
				a+="1"
				b+="0"
				flag=1
			else:
				a+="0"
				b+="0"
		else:
			if c=='2':
				a+="0"
				b+="2"
			elif c=='1':
				a+="0"
				b+="1"
			else:
				a+="0"
				b+="0"
	print(a)
	print(b)