/* CSCI 2113 - Program 1
 * Adnan Shilleh */

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "WordPhraseList.h"

WordListNode* addToList(WordListNode *phraseList, const char *phrase)
{    
    // pointer to head node of list
    WordListNode* curr = phraseList;
    // pointer to store previous node while we traverse the list
    WordListNode* prev = NULL;
    
    // traverse the list to find the node with matching word
    while (curr != NULL && strcmp(curr->phrase, phrase)<0) {
        prev = curr;
        curr = curr->next;
    }
    
    // if node found with word - update its count - else insert a new node
    if (curr != NULL) {
        if (strcmp(phrase, curr->phrase)==0) {
            curr->count++;
        }
        else {
            curr = createNode(phrase);
            if (prev == NULL) {
                curr->next = phraseList;
                phraseList = curr;
            }
            else {
                curr->next = prev->next;
                prev->next = curr;
            }
        }
    }
    // if word not found it the list create a new node and place it at the head of list
    else if (phraseList == NULL)
        phraseList = createNode(phrase);
    else
        prev->next = createNode(phrase);
    
    // return the pointer to new head node of list
    return phraseList;
}

WordListNode* createNode(const char *phrase)
{
    WordListNode* node = (WordListNode*)malloc(sizeof(WordListNode));
    
    int i=-1;
    do {
        i++;
        node->phrase[i] = phrase[i];
    } while (phrase[i] != '\0');
    
    node->count = 1;
    node->next = NULL;
    
    return node;
}

int compareStr(const char* str1, const char* str2) {
    int check = 1;
    
    int i = -1;
    do {
        i++;
        if (str1[i] != str2[i]) {
            check = 0;
            break;
        }
    } while (str1[i] != '\0' && str2[i] != '\0');
    
    return check;
}

void printList(WordListNode *phraseList) {
    WordListNode* curr = phraseList;
    
    while (curr != NULL) {
        printf("%5u %s\n", curr->count, curr->phrase);
        curr = curr->next;
    }
}

void printTop3Phrase(WordListNode *phraseList) {
    WordListNode* curr = phraseList;
    unsigned int max_counts[3] = {0, 0, 0};
    
    // find the top 3 counts and store it in max_counts
    while (curr != NULL) {
        for(int i=0; i<3; i++) {
            if (curr->count >= max_counts[i]) {
                if (i==0) {
                    max_counts[2] = max_counts[1];
                    max_counts[1] = max_counts[0];
                }
                else if (i==1)
                    max_counts[2] = max_counts[1];
                max_counts[i] = curr->count;
                break;
            }
        }
        curr = curr->next;
    }
    
    // print all phrases that has count same as any three of the max counts
    for(int i=0; i<3; i++) {
        curr = phraseList;
        while (curr != NULL) {
            if (curr->count == max_counts[i])
                printf("%u\t%s\n", curr->count, curr->phrase);
            curr = curr->next;
        }        
    }
}
