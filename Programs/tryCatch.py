def add(n1, n2):
    return n1+n2


n1 = int(input("Give a no."))
try:
    result = add(n1, 56)
except:
    print("There is a type error")
else:
    print(result)
