#include "simple_shell.h"
#include "string_utils.h"

/**
 * get_environment_variable - Get the value of an environment variable by name.
 * @name: Environment Variable Name
 * Return: The Value of the Environment Variable or NULL.
 */
char *get_environment_variable(char *name)
{
	size_t name_len, value_len;
	char *value;
	int i, j, k;

	name_len = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], name_len) == 0)
		{
			value_len = _strlen(environ[i]) - name_len;
			value = malloc(sizeof(char) * value_len);

			if (!value)
			{
				free(value);
				perror("unable to allocate memory");
				return (NULL);
			}

			j = 0;
			for (k = name_len + 1; environ[i][k]; k++, j++)
			{
				value[j] = environ[i][k];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
