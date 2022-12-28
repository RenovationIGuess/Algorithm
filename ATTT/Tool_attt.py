import sys
#Giới hạn limit đệ quy
sys.setrecursionlimit(1500)

#xor
def string_to_10(s):
	D = []
	for i in s:
		D.append(ord(i))
	return(D)

def _16_to_10(s):
	d = []
	for i in range(len(s)//2):
		d.append(int(s[i*2:i*2+2],16))
	return(d)

def _10_to_bits(d):
	x = ""
	for i in d:
		x += '{0:08b}'.format(i)
	return(x)

def _2_to_10(s):
	d = []
	for i in range(len(s)//8):
		d.append(int(s[i*8:i*8+8],2))
	return(d)

class A_F:
    def ki_tu(self,x):
        tra_ve=x
        return getattr(self, 'KT_' + str(x),lambda:tra_ve)()
    def KT_10(self):
        return "A"
    def KT_11(self):
        return "B"
    def KT_12(self):
        return "C"
    def KT_13(self):
        return "D"
    def KT_14(self):
        return "E"
    def KT_15(self):
        return "F"
def _10_to_16(n):
    kq=''
    while n!=0:
        du=n%16
        kq=str(A_F().ki_tu(du))+kq
        n=n//16
    return kq


# return (d,x,y) --- x*a + y*b = 1
def Extended_Euclid(a,b):
	if b == 0:
		return(a, 1, 0)
	else:
		d, x, y = Extended_Euclid(b,a%b)
		return(d, y, x - (a//b)*y)

# return = a^-1 mod b
def Mod_Inv(a, n):
	d, x, y = Extended_Euclid(a, n)
	b = x % n
	return(b)

# return = a^b mod n
def Mod_Exponentiation(a,b,n):
	if b == 0:
		return 1
	if b == 1:
		return a
	r = Mod_Exponentiation(a, b//2, n)
	r = (r*r)%n
	if b % 2 == 1:
		r = (r*a)%n
	return r%n

def Dang1(a,b,z):
	if b == -1:
		return(Mod_Inv(a, z))
	else:
		return(Mod_Exponentiation(a,b,z))

def Dang2(n,e,m,o):
	if Mod_Exponentiation(o,e,n) == m:
		return("Hợp lệ")
	else:
		return("Không hợp lệ")

def Dang3(s1,pad,s2):
	x1 = string_to_10(s1)
	p1 = _16_to_10(pad)
	x2 = string_to_10(s2)
	k = []
	for i in range(len(x1)):
		k.append(_10_to_16(x1[i]^p1[i]^x2[i]))
	s = ""
	for i in range(len(k)):
		if len(str(k[i])) == 2:
			s = s + str(k[i])
		else:
			s = s + '0' + str(k[i])
	return(s)

def Dang4(z):
	# Z* 
	for i in range(1,z):
		print(str(i) + ": ", end='')
		for x in range(16):
			k = i**x-17*int((i**x)/17)
			print(k, end=',')
		print()
		
def Dang5(a,b,z):
	#Dloga(b) Z*
	for x in range(100):
		k = a**x-z*int((a**x)/z)
		if k == b:
			return(x)

def Dang6(a,b,c,z):
	#DHa(b,c) Z*
	d = []
	for x in range(100):
		k = a**x-z*int((a**x)/z)
		if k == b or k == c:
			d.append(x)
		if len(d) >= 2:
			break
	return(Mod_Exponentiation(a,d[0]*d[1],z))


def Dang7(p,q,e,y):
	d = Mod_Inv(e,(p-1)*(q-1))
	return(Mod_Exponentiation(y,d,q*p))

def Dang8(d,p,g,m,kE):
	r = Mod_Exponentiation(g,kE,p)
	s = ((m-d*r)*Mod_Inv(kE,p-1))%(p-1)
	return("(" + str(r) + "," + str(s) + ")")

def main():
    choose = 100
    while choose != 0:
    	print("\n\nChọn dạng: ", end="")
    	choose = int(input())
    	if choose == 1:
    		a = int(input("a = "))
    		b = int(input("b = "))
    		z = int(input("z = "))
    		print("anwser: ")
    		print(Dang1(a,b,z))
    	if choose == 2:
    		n = int(input("n = "))
    		e = int(input("e = "))
    		m = int(input("m = "))
    		o = int(input("o = "))
    		print("anwser: ")
    		print(Dang2(n,e,m,o))
    	if choose == 3:
    		s1 = input("s1 = ")
    		pad = input("pad = ")
    		s2 = input("s2 = ")
    		print("anwser: ")
    		print(Dang3(s1,pad,s2))
    	if choose == 4:
    		z = int(input("z = "))
    		Dang4(z)
    	if choose == 5:
    		a = int(input("a = "))
    		b = int(input("b = "))
    		z = int(input("z = "))
    		print("anwser: ")
    		print(Dang5(a,b,z))
    	if choose == 6:   
    		a = int(input("a = "))
    		b = int(input("b = "))
    		c = int(input("c = "))
    		z = int(input("z = "))
    		print("anwser: ")
    		print(Dang6(a,b,c,z))
    	if choose == 7:   
    		p = int(input("p = "))
    		q = int(input("q = "))
    		e = int(input("e = "))
    		y = int(input("y = "))
    		print("anwser: ")
    		print(Dang7(p,q,e,y))
    	if choose == 8:
    		d = int(input("d = "))
    		p = int(input("p = "))
    		g = int(input("g = "))
    		m = int(input("m = "))
    		kE = int(input("kE = "))
    		print("anwser: ")
    		print(Dang8(d,p,g,m,kE))
if __name__ == "__main__":
    main()