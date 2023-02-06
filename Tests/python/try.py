import itertools

ls = [1, 1, 3]
x = list(tuple())
s = itertools.permutations(ls)

for el in s:
    x.append(tuple(el))

st = set(tuple(x))
print(st)
ans = list(list())
for el in st:
    ans.append(list(el))

print(ans)

"""
{(1, 1, 3), (1, 3, 1), (3, 1, 1)}
[[1, 1, 3], [1, 3, 1], [3, 1, 1]]
"""
