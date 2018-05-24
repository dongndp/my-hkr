'''
https://www.hackerrank.com/challenges/swap-case/problem

sWAP cASE

'''

#def swapchar(c):
#    if c.isupper():
#        return c.lower()
#    else:
#        return c.upper()

def swap_case(s):
    # solution 1: using map()
    # return ''.join(map(swapchar,s))
    # soution 2: list comprehension
    # return ''.join(c.lower() if c.isupper() else c.upper() for c in s)
    # solution 3: built-in function swapcase()
    return s.swapcase()
