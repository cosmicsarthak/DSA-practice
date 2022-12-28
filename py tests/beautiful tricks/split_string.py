s = input("enter string: ")

x = []

wordList = s.split(" ")
for word in wordList:
    x.append(word[::-1])

newSen = " ".join(x)
print(newSen)
