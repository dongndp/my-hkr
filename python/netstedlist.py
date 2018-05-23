'''

https://www.hackerrank.com/challenges/nested-list/problem

Nested List

'''

if __name__ == '__main__':
    students = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        students.append([name, score])
    
    # sort by grade
    students.sort(key=lambda a: a[1])
    
    #print(students)
    
    i = 1
    while i<len(students) and students[i][1] == students[0][1]:
        i += 1
    
    names = []
    
    if i<len(students):
        # we found at least 1 student whose score matches the conditions
        names.append(students[i][0])
        second_lowest_score = students[i][1]
        i += 1
        while i<len(students) and students[i][1]==second_lowest_score:
            names.append(students[i][0])
            i += 1
    
    print(*(sorted(names)), sep="\n")
