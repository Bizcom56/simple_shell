#include "shell.h"

/**
 * _strcpy -  copies the src string to the dest string
 * @dest: string that would be copied to
 * @src: string to be copied
 *
 * Return: a pointer to the dest string
 */
char *_strcpy(char *dest, char *src)
{
	char *p = dest;

	while (1)
	{
		*p = *src;
		if (!*src)
		{
			break;
		}
		src++;
		p++;
	}
	return (dest);
}

/**
 * tok_num - returns the number of token to be extracted
 * @buffer: string to extract token from
 *
 * Return: number of tokens to be extracted
 */
unsigned int tok_num(char *buffer)
{
	unsigned int num = 0, prev = 1;
	char *p = buffer;

	while (1)
	{
	/*count token if space is not a begining or previosly counted*/
		if (*p == ' ')
		{
			if (prev != 1)
				num++;
			prev = 1;
		}
		else if (*p == '\0' || *p == '\n')
		{
			if (prev != 1)
				num++;
			break;
		}
		else
			prev = 0;
		p++;
	}
	return (num);
}

/**
 * token - splits a string into tokens using ' ' as delimiter
 * @buffer: string to be splitted into tokens
 *
 * Return: returns a null terminated array of extracted tokens or NULL;
 */
char **token(char *buffer)
{
	char **argv;
	char *p = buffer, buf[1024];
	unsigned int num, x, len, count;

	num = tok_num(buffer);
	if (num == 0)
		return (NULL);
	argv = (char **) malloc((num + 1) * sizeof(char *));
	if (argv == NULL)
		return (NULL);
	for (x = 0; x < num; x++)
	{
		count = 0;
		while (1)
		{
			if (*p != ' ' && *p != '\0' && *p != '\n')
			{
				buf[count] = *p;
				p++;
				count++;
			}
			else if (count == 0)
				p++; /*incase it starts with a space*/
			else
				break;
		}
		buf[count] = '\0';
		len = count + 1;
		argv[x] = (char *) malloc(len * sizeof(char));
		if (argv[x] == NULL)
		{
			free_arg(argv);
			return (NULL);
		}
		_strcpy(argv[x], buf);
		p++;
	}
	argv[num] = NULL;
	return (argv);
}

/**
 * free_arg - releases the memory allocated for creating the argv[]
 * @argv: argument vector to be freed
 */
void free_arg(char **argv)
{
	unsigned int x = 0;

	while (argv[x] != NULL)
	{
		free(argv[x]);
		x++;
	}
	free(argv);
}

