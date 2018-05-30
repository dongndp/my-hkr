//
// https://www.hackerrank.com/challenges/printing-pattern-2/problem
// Printing Patterns
//
// Sample Input: 
// 5
// Sample Output:
// 5 5 5 5 5 5 5 5 5 
// 5 4 4 4 4 4 4 4 5 
// 5 4 3 3 3 3 3 4 5 
// 5 4 3 2 2 2 3 4 5 
// 5 4 3 2 1 2 3 4 5 
// 5 4 3 2 2 2 3 4 5 
// 5 4 3 3 3 3 3 4 5 
// 5 4 4 4 4 4 4 4 5 
// 5 5 5 5 5 5 5 5 5

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
  	for (int i=0; i<n; i++) {
        /* print line i */
        for (int j=0; j<n; j++) {
            if (j<=i) {
                printf("%d ", n-j);
            } else {
                printf("%d ", n-i);
            }
        }
        for (int j=n-1; j>0; j--) {
            if (j>i) {
                printf("%d ", n-i);
            } else {
                printf("%d ", n-j+1);
            }
        }
        printf("\n");
    }
  	for (int i=n-2; i>=0; i--) {
        /* print line i */
        for (int j=0; j<n; j++) {
            if (j<=i) {
                printf("%d ", n-j);
            } else {
                printf("%d ", n-i);
            }
        }
        for (int j=n-1; j>0; j--) {
            if (j>i) {
                printf("%d ", n-i);
            } else {
                printf("%d ", n-j+1);
            }
        }
        printf("\n");
    }
    return 0;
}
