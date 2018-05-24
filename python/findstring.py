'''
https://www.hackerrank.com/challenges/find-a-string/problem

Find a string

'''

def count_substring(string, sub_string):
    count = 0
    sub_len = len(sub_string)
    for i in range(len(string)-sub_len+1):
        # print(i," ",string[i:i+sub_len])
        if sub_string == string[i:i+sub_len]:
            count += 1
    return count
