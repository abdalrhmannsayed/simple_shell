#include "shell.h"

/**
 * _atoi - return an integer found in the string.
 *
 * @string: string to search.
 *
 * Return: converted integer from string.
 */

int _atoi(char *string)
{
	unsigned int i = 0, lenght = 0, init = 0, finish = 0;
	unsigned int num = 1, d = 0, sign = 0, sum = 0;

	lenght = _strlen(string);
	if (lenght == 0)
		return (0);
	for (i = 0; i < lenght; i++)
	{
		if (string[i] == '-')
			sign++;
		if (string[i] >= 48 && string[i] <= 57)
		{
			init = i;
			break;
		}
	}
	for (; i < lenght; i++)
		if (string[i] < 48 || string[i] > 57)
			break;
	finish = i - 1;
	for (; init <= finish; init++)
	{
		d = string[init] - '0';
		num = 1;
		for (i = 0; i < finish - init; i++)
			num = num * 10;
		num = num * d;
		sum = num + sum;
	}
	if (sign % 2 == 1)
		sum = sum * -1;
	return (sum);
}
/**
  * _itoa - Convert Integer To Char
  *
  * @n: Int To Convert
  *
  * Return: Char Pointer
*/

char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}

/**
  * array_rev - Reverse Array
  *
  * @arr:Array To Reverse
  *
  * @len:Length Of Array
  *
  * Return: Void(Reverse Array)
*/

void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
  * intlen - Determine Length Of Int
  *
  * @num: Given Int
  *
  * Return: Length Of Int
*/

int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
