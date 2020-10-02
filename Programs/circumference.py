class Circle():
    pi = 3.14

    def __init__(self, radius):
        self.radius = radius

    def circumference(self):
        return self.radius*self.pi*2


myCircle = Circle(5)
print(myCircle.circumference())

