#include "shell.h"

/**
 * update_errno - updates the errno and returns NULL
 *
 * Return: returns NULL to the calling process
 */
char *update_errno(void)
{
	errno = ENOENT;
	return (NULL);
}

/**
 *_strncmp - compares the value of two strings
 *@s1: main string in the comparison
 *@s2: string that is compared to the main string
 *@n: number of bytes to compare
 *
 *Return: 0 if equal, positive value if greater than s2 and negative otherwise
 */
int _strncmp(char *s1, char *s2, int n)
{
	int value = 0, index;
	char *p1 = s1;
	char *p2 = s2;

	for (index = 0; index < n; index++)
	{
		if (*p1 == *p2)
		{
			p1++;
			p2++;
			continue;
		}
		else
		{
			value = *p1 - *p2;
			break;
		}
	}
	return (value);
}

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	int len = 0;
	int x = 0;
	char *concat;
	char *p1 = s1;
	char *p2 = s2;

	while (p1 && *p1)
	{
		len++;
		p1++;
	}
	while (p2 && *p2)
	{
		len++;
		p2++;
	}
	concat = malloc(len + 1);
	p1 = s1;
	p2 = s2;
	while (concat != NULL)
	{
		if (p1 && *p1)
		{
			concat[x] = *p1;
			p1++;
		}
		else if (p2 && *p2)
		{
			concat[x] = *p2;
			p2++;
		}
		else
		{
			concat[x] = '\0';
			break;
		}
		x++;
	}
	return (concat);
}

/**
 * path - returns the valid  path for a given filename if present in PATH
 * @filename: name to be checked if present in PATH folders
 *
 * Return: returns the absolute path where the filename is
 */
char *path(char *filename)
{
	char *path = NULL, buf[TOK_BUFSIZE], *valid_path = NULL, *tk = "PATH=";
	unsigned int index = 5, x, count;
	struct stat st;

	for (count = 0; (environ && environ[index] != NULL); count++)
	{
		if ((_strncmp(environ[count], tk, 5) == 0))
		{
			path = environ[count];
			break;
		}
	}
	if (path == NULL)
		return (update_errno());
	while (path[index] != '\0')
	{
		x = 0;
		while (1)
		{
			if (path[index] == ':' || path[index] == '\0')
			{
				buf[x] = '/';
				buf[x + 1] = '\0';
				if (path[index] == ':')
					index++;
				break;
			}
			buf[x] = path[index];
			index++;
			x++;
		}
		valid_path = str_concat(buf, filename);
		if ((stat(valid_path, &st)) == 0)
			break;
		free(valid_path);
		valid_path = NULL;
	}
	if (valid_path == NULL)
		errno = ENOENT;
	return (valid_path);
}

