'''
https://www.hackerrank.com/challenges/the-minion-game/problem

The Minion Game

'''

def minion_game(string):
    scores = {'Kevin':0, 'Stuart':0}
    size = len(string)
    for i in range(size):
        if string[i] in 'AEIOU':
            scores['Kevin'] += size - i
        else:
            scores['Stuart'] += size - i
    if scores['Kevin'] > scores['Stuart']:
        print('Kevin {}'.format(scores['Kevin']))
    elif scores['Kevin'] == scores['Stuart']:
        print("Draw")
    else:
        print('Stuart {}'.format(scores['Stuart']))


if __name__ == '__main__':
    s = input()
    minion_game(s)
