'''
https://www.hackerrank.com/challenges/alphabet-rangoli/problem

Alphabet Rangoli

Sample Input/Output:

#size 10

------------------j------------------
----------------j-i-j----------------
--------------j-i-h-i-j--------------
------------j-i-h-g-h-i-j------------
----------j-i-h-g-f-g-h-i-j----------
--------j-i-h-g-f-e-f-g-h-i-j--------
------j-i-h-g-f-e-d-e-f-g-h-i-j------
----j-i-h-g-f-e-d-c-d-e-f-g-h-i-j----
--j-i-h-g-f-e-d-c-b-c-d-e-f-g-h-i-j--
j-i-h-g-f-e-d-c-b-a-b-c-d-e-f-g-h-i-j
--j-i-h-g-f-e-d-c-b-c-d-e-f-g-h-i-j--
----j-i-h-g-f-e-d-c-d-e-f-g-h-i-j----
------j-i-h-g-f-e-d-e-f-g-h-i-j------
--------j-i-h-g-f-e-f-g-h-i-j--------
----------j-i-h-g-f-g-h-i-j----------
------------j-i-h-g-h-i-j------------
--------------j-i-h-i-j--------------
----------------j-i-j----------------
------------------j------------------

'''

def print_rangoli(size):
    asciistring = 'abcdefghijklmnopqrstuvwxyz'
    string = asciistring[:size]
    width = 2*n - 1 + 2*(n-1)
    for i in range(n-1,-1,-1):
        s = string[i]
        for j in range(i+1,n):
            s = '-'.join([string[j],s,string[j]])
        print(s.center(width,'-'))
    for i in range(1,n):
        s = string[i]
        for j in range(i+1,n):
            s = '-'.join([string[j],s,string[j]])
        print(s.center(width,'-'))


if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)
