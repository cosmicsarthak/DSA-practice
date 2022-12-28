s = input("enter string: ")

x = []

wordList = s.split(" ")
for word in wordList:
    x.append(word[::-1])

# newSen = " ".join(x)
newSen = ", ".join(x)   # 7, 34, 3, 34, 3, 4

print(newSen)
