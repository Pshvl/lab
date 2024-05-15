x = 36**7 + 6**19 - 18
s = ''
while x != 0:
    s += str(x % 6)
    x //= 6
print (s)
#s = s[::-1]#переворот не обяз
print (s)
print(s.count("5"))