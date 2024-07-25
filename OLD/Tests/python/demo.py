def sls(ls, n):
    if n == 0:
        return 0
    else:
        return ls[n-1] + sls(ls, n-1)


def main():
    s = input().split()
    print(s)
    ls = []
    for i in s:
        ls.append(int(i))
    print(ls)
    n = len(ls)
    print(sls(ls, n))


main()
