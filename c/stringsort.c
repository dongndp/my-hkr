//
// https://www.hackerrank.com/challenges/sorting-array-of-strings/problem
// Sorting Array of Strings
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a,b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b,a);
}

int count_distinct_characters(const char* a) {
    int arr[26] = {0};
    for (int i=0; a[i]; i++) {
        arr[a[i]-'a']++;
    }
    int dt = 0;
    for (int i=0; i<26; i++) {
        if (arr[i]) {
            dt++;
        }
    }
    return dt;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int dta = count_distinct_characters(a);
    int dtb = count_distinct_characters(b);
    return dta!=dtb ? dta-dtb : strcmp(a,b);
}

int sort_by_length(const char* a, const char* b) {
    int la = strlen(a), lb = strlen(b);
    if (la!=lb) {
        return la - lb;
    } else {
        return strcmp(a,b);
    }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)) {
    /* A simple insertion sort implementation */
    if (len>=2) {
        int i=1;
        while (i<len) {
            char *s = arr[i];
            int j = i;
            while (j>0 && cmp_func(s,arr[j-1])<0) {
                arr[j] = arr[j-1];
                j--;
            }
            if (j<i) {
                arr[j] = s;
            }
            i++;
        }
    }
}

// The locked code-stub 

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
