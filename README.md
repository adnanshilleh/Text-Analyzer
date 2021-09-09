# Project 1 - 100 points

## Name: Adnan Shilleh

## The George Washington University
## Software Engineering CSCI 2113

## Instructions:

Complete the program in the repository. The project is a text analysis program that will read in a text file that is passed in as an argument.  The project will analyze the text file and determine the top 3 (including ties) most common three-word phrases. The project must fulfill the following requirements

* The top three – three-word phrases or sequences in the file – identify the three word phases that appear the most often in the text file and show the top three phrases and the number of times they appear in the document.
* A word is any alphanumeric set of characters separated by punctuation or whitespace. Please also include apostrophes “ ' “ as put of your word definitions so that words such as **won’t** will be included as a word.  
* Case should not be considered when matching words. For example: “The brown dog” and “the brown dog” are considered the same word.
* Phrases can break across lines (i.e. newline is considered whitespace)
* The program shall ask the user for the name of the file to process and then display the answer.  The program shall then ask the user if they would like to process another file or exit.
  * If they process another file make sure you free the current list before processing the new file.
* For the top three-word phrase, if there is one phase that occurs 6 times, one that occurs 5 times, and 3 that occurs four times, then the program should print out 5 phrases and the number of times they occur.
* The program will use a sorted linked list to store the word phrases read in from the input file.
* The program should be tested with TheRaven.txt and TaleOfTwoCities.txt. We will test it against one additional text file.