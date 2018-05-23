'''
https://www.hackerrank.com/challenges/python-tuples/problem

Tuple

'''

if __name__ == '__main__':
    n = int(input())
    print(hash(tuple(map(int, input().split()))))
