'''

https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/problem

Find the Runner-Up Score!

'''

if __name__ == '__main__':
    n = int(input())
    # given the problem constrain: -100 <= score <= 100
    first = -100
    second = -100
    arr = map(int, input().split())
    for score in arr:
        if score>first:
            second = first
            first = score
        elif score<first and score>second:
            second = score
    print(second)
        