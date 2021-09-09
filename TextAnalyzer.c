/* CSCI 2113 - Program 1
 * Adnan Shilleh */

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "WordPhraseList.h"

void makePhrase(char *phrase, const char *word1, const char *word2, const char *word3)
{
    // add all three words to make a 3-word-phrase
    int i=0;
    int j=0;
    while (word1[j] != '\0') { phrase[i++] = word1[j++]; }
    phrase[i++] = ' ';
    j=0;
    while (word2[j] != '\0') { phrase[i++] = word2[j++]; }
    phrase[i++] = ' ';
    j=0;
    while (word3[j] != '\0') { phrase[i++] = word3[j++]; }
    phrase[i] = '\0';
}

int main()
{
    // temp array to store 3-word-phrase found in buffer
    char words[3][33];
    char phrase[99];
    // character variable to read one characer at a time from input buffer
    char ch;
    // index position in word array
    int i = 0;
    int k = 0;
    
    WordListNode *phraseList = NULL;
    
    char inFile[33];
    FILE* fin;
    
    printf("Enter name of input file: ");
    scanf("%s", inFile);
    
    fin = fopen(inFile, "r");
    // while the character read from input array is not '\0'
    while((ch = fgetc(fin)) != EOF) {
        // if the character is an uppercase letter add it to word array converting to lowercase first
        if ((ch >= 'A' && ch <= 'Z')) {
            words[k%3][i++] = ch - 'A' + 'a';
        }
        // else if the character is an lowercase letter add it to word array
        else if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '\'') {
            words[k%3][i++] = ch;
        }
        // else if character is a whitespace or any special character and word index is not zero
        // then it means that there is a word has ended
        else if (i != 0) {
            // set last position in word as null charcter
            words[k%3][i] = '\0';
            // reset index position in word
            i = 0; k++;
            if (k >= 3) {
                // make a phrase by joining three words
                makePhrase(phrase, words[k%3], words[(k+1)%3], words[(k+2)%3]);
                // add the phrase to phrase linked list
                phraseList = addToList(phraseList, phrase);
            }
        }
    }
    // print top 3 phrases
    printTop3Phrase(phraseList);
}
