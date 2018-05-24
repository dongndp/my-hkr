'''
https://www.hackerrank.com/challenges/text-wrap/problem

Text Wrap

'''

def wrap(string, max_width):
    # Notes: This also can be done using textwrap.fill()
    lines = [string[i*max_width:(i+1)*max_width] for i in range(len(string)//max_width + 1)]
    return '\n'.join(lines)
