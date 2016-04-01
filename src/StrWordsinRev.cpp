/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void rev(char *input, int start, int end)
{

	char temp;
	while (start <= end)
	{
		temp = input[start];
		input[start] = input[end];
		input[end] = temp;
		start++;
		end--;
	}
}
void str_words_in_rev(char *input, int len){
	int start = 0, end = 0, i = 0;
	rev(input, 0, len - 1);
	while (input[i] != '\0'){
		if (input[i] != 32)
			end++;
		if (input[i] == 32 & input[i - 1] != 32)
			rev(input, start, end - 1);
		if (input[i] == 32)
		{
			start = i + 1;
			end++;
		}
		i++;
	}
	rev(input, start, end - 1);
}