'''
https://www.hackerrank.com/challenges/capitalize/problem

Capitalize

'''

def capitalize(string):
    return ' '.join([s[0].upper()+s[1:] if len(s) else '' for s in string.split(' ')])
    
    
if __name__ == '__main__':
    string = input()
    capitalized_string = capitalize(string)
    print(capitalized_string)