'''
https://www.hackerrank.com/challenges/string-validators/problem

String Validators

'''

if __name__ == '__main__':
    s = input()

    flags = {'alpha':False, 'digit':False, 'upper':False, 'lower':False}
    for x in s:
        if not flags['alpha']:
            flags['alpha'] = x.isalpha()
        if not flags['digit']:
            flags['digit'] = x.isdigit()
        if not flags['lower']:
            flags['lower'] = x.islower()
        if not flags['upper']:
            flags['upper'] = x.isupper()
        if flags['alpha'] and flags['digit'] and flags['lower'] and flags['upper']:
            break

    print(flags['alpha'] or flags['digit'])
    print(flags['alpha'])
    print(flags['digit'])
    print(flags['lower'])
    print(flags['upper'])

    # solution 2: using built-in any() function and list comprehensions
    #print any([char.isalnum() for char in s])
    #print any([char.isalpha() for char in s])
    #print any([char.isdigit() for char in s])
    #print any([char.islower() for char in s])
    #print any([char.isupper() for char in s])

