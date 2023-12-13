#include "shell.h"

/**
 * exit_shell - cleanly exits the shell with a specific exit status
 *
 * This function takes a data_shell pointer as an argument, which contains
 * information about the shell status and arguments. If the argument to the
 * exit command is valid, it sets the shell status to the remainder of the
 * argument modulo 256. If there is no argument or an error occurs, it sets
 * the shell status to 0 or 2 and prints an error message. Then it exits the
 * shell using the exit function, with the shell status as the argument.
 *
 * @arg: argument pased to the exit call
 * Return: 0 on success, 1 on error
 */
int exit_shell(char *arg)
{
	unsigned int status = 0;
	int i;

	/* convert argument to unsigned int */
	for (i = 0; arg[i] != '\0'; i++)
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (-1);

		/* prevent overflow */
		if (status > (UINT_MAX - (arg[i] - '0')) / 10)
			return (-1);

		status = status * 10 + (arg[i] - '0');
	}
	/* set shell status to remainder of argument modulo 256 */
	status = status % 256;
	return (status);
}

