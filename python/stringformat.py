'''
https://www.hackerrank.com/challenges/python-string-formatting/problem

String Formatting

'''

def print_formatted(number):
    width = len(format(number,'b'))
    for i in range(1,number+1):
        for base in 'doXb':
            print('{0:{width}{base}}'.format(i, base=base, width=width), end=' ')
        print()
        
if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
