/* CSCI 2113 - Program 1
 * Adnan Shilleh */

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define ROWS 400
#define COLUMNS 60

#ifndef _WordPhraseList_H
#define _WordPhraseList_H

#include <stdbool.h>

typedef struct WordListNode
{
	char phrase[99];
	unsigned int count;
	struct WordListNode *next;
} WordListNode;

WordListNode* createNode(const char *);
WordListNode* addToList(WordListNode *, const char *);
int compareStr(const char *, const char *);
void printList(WordListNode *);
void printTop3Phrase(WordListNode *);

#endif
