def rev(s):
    wordList = s.split()

    x = [word[::-1] for word in wordList]

    newString = " ".join(x)
    print(newString)


s = input("enter string: ")

rev(s)
