def rev(s):
    wordList = s.split()

    # x = []
    # for word in wordList:
    #     x.append(word[::-1])

    x = [word[::-1] for word in wordList]

    newSen = " ".join(x)
    print(newSen)


s = input("enter string: ")

rev(s)
