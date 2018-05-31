//
// https://www.hackerrank.com/challenges/structuring-the-document/problem
// Structuring the Document
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

#define TRUE 1
#define FALSE 0

// Create new document
struct document new_document() {
    struct document doc;
    doc.paragraph_count = 0;
    doc.data = NULL;
    return doc;
}

// Allocate memory for new paragraph to hold sentences
void new_paragraph(struct document *doc) {
    doc->data = (struct paragraph*)realloc(doc->data, ++doc->paragraph_count*sizeof(struct paragraph));
    struct paragraph* para = &doc->data[doc->paragraph_count-1];
    para->sentence_count = 0;
    para->data = NULL;
}

// Allocate memory for new sentence to hold words
void new_sentence(struct document *doc) {
    struct paragraph* para = &doc->data[doc->paragraph_count-1];
    para->data = (struct sentence*)realloc(para->data, ++para->sentence_count*sizeof(struct sentence));
    struct sentence* sen = &para->data[para->sentence_count-1];
    sen->word_count = 0;
    sen->data = NULL;
}

// Append new word to document
void append_word(struct document *doc, char *start, char *end, int *create_new_paragraph, int *create_new_sentence) {
    if (*create_new_paragraph) {
        new_paragraph(doc);
        *create_new_paragraph = FALSE;
    }
    if (*create_new_sentence) {
        new_sentence(doc);
        *create_new_sentence = FALSE;
    }
    struct paragraph *para = &doc->data[doc->paragraph_count-1];
    struct sentence *sen = &para->data[para->sentence_count-1];
    sen->data = (struct word*)realloc(sen->data, ++sen->word_count*sizeof(struct word));
    struct word *w = &sen->data[sen->word_count-1];
    int wlen = end - start;
    w->data = malloc((wlen+1)*sizeof(char));
    memcpy(w->data,start,wlen);
    w->data[wlen] = '\0';
}

struct document get_document(char* text) {
	struct document doc = new_document();
    // Parse the document
    int create_new_paragraph = TRUE;
    int create_new_sentence = TRUE;
	char *s_ptr = text;
	char *e_ptr = text;
	while (*e_ptr) {
		if (*e_ptr==' ') {
			// Extract word and append it to document
            append_word(&doc, s_ptr, e_ptr, &create_new_paragraph, &create_new_sentence);
			// Parse next word
			e_ptr++;
			s_ptr = e_ptr;
		} else if (*e_ptr=='.') {
			// End of sentence
			// Extract word and append it to sentence
            append_word(&doc, s_ptr, e_ptr, &create_new_paragraph, &create_new_sentence);
			// Parse next word of next sentence
            create_new_sentence = TRUE;
			e_ptr++;
			s_ptr = e_ptr;
		} else if (*e_ptr=='\n') {
			// End of paragraph or document
            create_new_paragraph = TRUE;
			e_ptr++;
			s_ptr = e_ptr;
		} else {
			e_ptr++; // alpha character
		}
	}
	return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
}

// Locked stub

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
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

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
