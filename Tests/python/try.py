import re

s = 'hello'
match = re.search(r'[a-z0-9]+(.[a-z0-9]+)*@[a-z]+(.[a-z]+)*', s)
print(match)

s = 'hello'
match = re.search('hell*', s)
print(match)
