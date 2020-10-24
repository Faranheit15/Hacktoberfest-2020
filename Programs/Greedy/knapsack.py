
def FractionalKnapSack(ratio, capacity):
    ratio = sorted(ratio, key=lambda x: x[0]/x[1], reverse=True)
    maxvalue = 0
    for i in ratio:
        if capacity-i[1] >= 0:
            capacity = capacity-i[1]
            maxvalue = maxvalue + i[0]
        else:
            fraction = capacity / i[1]
            maxvalue += int(i[0] * fraction)
            capacity = int(capacity - (i[1] * fraction))
            break
    return maxvalue


def zerooneKnapsack(ratio, capacity):
    ratio = sorted(ratio, key=lambda x: x[0]/x[1], reverse=True)
    maxvalue = 0
    for i in ratio:
        if capacity-i[1] >= 0:
            capacity = capacity-i[1]
            maxvalue = maxvalue + i[0]
        else:
            break
    return maxvalue


wt = [10, 40, 20, 30]
val = [60, 40, 100, 120]
ratio = []
for i in range(len(wt)):
    ratio.append([val[i], wt[i]])
capacity = 50
maxValue = FractionalKnapSack(ratio, capacity)
print("Maximum value in Fractional Knapsack =", maxValue)
val = [60, 100, 120]
wt = [10, 20, 30]
ratio = []
for i in range(len(wt)):
    ratio.append([val[i], wt[i]])
capacity = 50
print("RATIO", ratio)
maxValue = zerooneKnapsack(ratio, capacity)
print("Maximum value in 0-1 Knapsack =", maxValue)
