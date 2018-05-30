//
// https://www.hackerrank.com/challenges/permutations-of-strings/problem
// Permutations of Strings
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_pointer(void** p1, void** p2) {
    void* tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    /**
    * Extract from source:
    * https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
    *
    * The following algorithm generates the next permutation lexicographically 
    * after a given permutation. It changes the given permutation in-place.
    *
    * 1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, 
    * the permutation is the last permutation.
    * 2. Find the largest index l greater than k such that a[k] < a[l].
    * 3. Swap the value of a[k] with that of a[l].
    * 4. Reverse the sequence from a[k + 1] up to and including the final element a[n].
    */
    if (n<2) {
        return 0;
    }
    // Step 1: Find the largest index k such that a[k] < a[k + 1]
    int k;
    for (k=n-2; k>=0; k--) {
        if (strcmp(s[k],s[k+1])<0) {
            break;
        }
    }
    if (k>=0) { // Found
        // Step 2: Find the largest index l greater than k such that a[k] < a[l]
        int l;
        for (l=n-1; l>k; l--) {
            if (strcmp(s[k],s[l])<0) {
                break;
            }
        }
        // Step 3: Swap the value of a[k] with that of a[l]
        swap_pointer((void**)&s[k], (void**)&s[l]);
        // Step 4: Reverse the sequence from a[k + 1] up to and including the final element
        for (int i=k+1, j=n-1; i<j; i++, j--) {
            swap_pointer((void**)&s[i], (void**)&s[j]);
        }
        return 1;
    }

    return 0;
}

// The locked stub code

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
