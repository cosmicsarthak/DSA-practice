# if __name__ = '__main__':
#     main()

# ⭐ Frequency of each character in String

from collections import Counter
import math

a = input()

freq = {}   # dict

for i in a:
    if (i in freq):
        freq[i] += 1
    else:
        freq[i] = 1

# print(freq)
for i in freq:
    print(i, freq[i])


print()
# ------------------------

ans = Counter(a)

for i in ans:
    print(i, ans[i])

# --------------------------
