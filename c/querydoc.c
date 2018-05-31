//
// https://www.hackerrank.com/challenges/querying-the-document/problem
// Querying the Document
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
	return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
	return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
	return document[k-1];
}

char**** get_document(char* text) {
	char *s_ptr = text;
	char *e_ptr = text;
	char *word = NULL;
	char** sentence = NULL;
	char*** paragraph = NULL;
	char**** document = NULL;
	int nword = 0, nsentence = 0, nparagraph = 0;
	
	while (1) {
		if (*e_ptr==' ') {
			// extract a word from document
			int wlen = e_ptr - s_ptr;
			word = malloc((wlen+1)*sizeof(char));
			memcpy(word,s_ptr,wlen);
			word[wlen] = '\0';
			nword++;
			// append new word to sentence
			sentence = (char**)realloc(sentence, nword*sizeof(char*));
			sentence[nword-1] = word;
			// to next word
			e_ptr++;
			s_ptr = e_ptr;
		} else if (*e_ptr=='.') {
			// End of sentence
			// Extract word and append it to sentence
			int wlen = e_ptr - s_ptr;
			word = malloc((wlen+1)*sizeof(char));
			memcpy(word,s_ptr,wlen);
			word[wlen] = '\0';
			nword++;
			// append new word to sentence
			sentence = (char**)realloc(sentence, nword*sizeof(char*));
			sentence[nword-1] = word;
			nsentence++;
			// Append new sentence to paragraph
			paragraph = (char***)realloc(paragraph, nsentence*sizeof(char**));
			paragraph[nsentence-1] = sentence;
			// to next sentence
			nword = 0;
			sentence = NULL;
			e_ptr++;
			s_ptr = e_ptr;
		} else if (*e_ptr=='\n' || *e_ptr=='\0') {
			// End of paragraph or document
			// Append new paragraph to document
			nparagraph++;
			document = (char****)realloc(document, nparagraph*sizeof(char***));
			document[nparagraph-1] = paragraph;
			// to next paragraph
			paragraph = NULL;
			nsentence = 0;
			nword = 0;
			if (*e_ptr) {
				e_ptr++;
				s_ptr = e_ptr;
			} else {
				break;
			}
		} else {
			e_ptr++; // alpha character
		}
	}
	return document;
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);
	
    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}
