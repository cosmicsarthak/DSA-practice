import random
import math

x = float(input("Enter x"))
y = float(input("Enter y"))

d = math.sqrt(math.pow(x, 2) + math.pow(y, 2))

if d > 10:
    print("not in circle")
else:
    print("in circle")
