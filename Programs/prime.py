#python program to show all prime numbers with some interval

low = int(input ("Input lower number: "))
high = int(input ("Input Upper number: "))

for prime in range (low,high +1):
    if prime > 1:
        for i in range(2, prime):
            if (prime % i) == 0:
                break
        else:
            print(prime)