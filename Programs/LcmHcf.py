x=int(input("Enter the first number: "))
y=int(input("Enter the second number: "))
a=x
b=y
while(y):
    x,y=y,x%y
hcf=x
lcm=int((a*b)/hcf)
print("The HCF of two numbers are: ", hcf)
print("The LCM of two number are: ", lcm)