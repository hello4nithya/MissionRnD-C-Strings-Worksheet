/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>
#include<string.h>

#define SIZE 31

int hasallspaces(char *str){
	int spaces = 0, i = 0;
	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == 32)
			spaces++;
	if ((spaces - i) == 0) return 1;
	else return 0;
}


char **commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;

	if (hasallspaces(str1))
		return NULL;
	if (hasallspaces(str2))
		return NULL;

	char tok_str1[100][100];
	int words_count_1, words_count_2;
	int i = 0;
	char **output = (char**)malloc(100 * sizeof(char *));;
	int k = 0;
	char tok_str2[100][100];
	for (int j = 0; str1[j] != '\0'; j++){
		if (str1[j] != ' ')
			tok_str1[i][k++] = str1[j];
		else
		{
			tok_str1[i][k++] = '\0';
			i++;
			k = 0;
		}
	}
	tok_str1[i][k++] = '\0';
	words_count_1 = i > 0 ? i + 1 : i;
	i = 0; k = 0;

	for (int j = 0; str2[j] != '\0'; j++){
		if (str2[j] != ' ')
			tok_str2[i][k++] = str2[j];
		else
		{
			tok_str2[i][k++] = '\0';
			i++;
			k = 0;
		}
	}
	tok_str2[i][k++] = '\0';
	words_count_2 = i > 0 ? i + 1 : i;

	int t = 0;
	for (i = 0; i <= words_count_1; i++){

		for (int j = 0; j <= words_count_2; j++){
			//cout << tok_str1[i] << "   " << tok_str2[j];
			if (strcmp(tok_str1[i], tok_str2[j]) == 0){
				//cout << tok_str1[i];

				output[t] = (char*)malloc(100 * sizeof(char));
				output[t++] = tok_str1[i];
			}
		}

	}
	output[t] = '\0';

	if (t == 0)
		return NULL;
	else
		return output;

}