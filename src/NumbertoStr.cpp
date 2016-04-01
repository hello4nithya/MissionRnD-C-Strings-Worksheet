/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

void reverse(char *str, int i)
{
	int j = 0, k = i - 1;
	char temp;
	while (j<k)
	{
		temp = str[j];
		str[j] = str[k];
		str[k] = temp;
		j++;
		k--;
	}
}
int ToString(int num, char *str, int d)
{
	int i = 0;
	while (num)
	{
		str[i++] = (num % 10) + '0'; /*converts the single digit remainder to character */
		num = num / 10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return i;
}
void number_to_str(float number, char *str,int afterdecimal){
	int len = 0, a = 0;
	float temp = 0;

	if (number < 0)
	{
		temp = number;
		number = -number;

	}
	int Ipart = (int)number; /* integer part of the number */

	float Fpart = number - (float)Ipart; /* float part of the number */

	int i = ToString(Ipart, str, 0);  /* converting integer part to string */
	if (afterdecimal != 0)
	{
		str[i] = '.';
		while (afterdecimal != 0){
			Fpart = Fpart * 10;
			afterdecimal--;
		}
		ToString((int)Fpart, str + i + 1, afterdecimal);
	}
	if (temp < 0){
		while (str[a] != '\0')
			a++;
		while (a != 0){
			str[a] = str[a - 1];
			a--;
		}
		str[0] = '-';
	}
}
