#include "shell.h"
/**
 * _getline - read a line of input
 * @lineptr: address of the pointer containing the character
 * Return: -1 on failure and the charactera read on success
 */

int get_Line(char **lineptr)
{
        char *buffer;
        int n_size;
        static int i;
        char c = 'x';
        int r;

        fflush(STDIN_FILENO);

        n_size = BUF_SIZE;
        buffer = malloc(sizeof(char) * n_size + 1);
        if (buffer == NULL)
                return (-1);
	i = 0;
        while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
                /*if (c == EOF || c == '\n')*/
		/*if (c == '\n')
			buffer[i] = '\0';*/
		if (r < 0)
		{
			free(buffer);
			return(-1);
		}
		if (r == 0)
                {
                        /*if (i == 0)
                        {
                                free(buffer);
                                return (-1);
                        }*/
			i++;
                        /*buffer[i] = '\0';*/
                        /*free(buffer);*/
                        break;
                }
                /*if (c == EOF || c == '\n')*/
                /*{*/
                        /**printf("endoffile");**/
                        /*buffer[i] = '\0';*/
                        /*break;*/
                /*}*/
                else
                        buffer[i] = c;
		i++;
                /*i++;*/

                if (i == n_size - 1)
                {
                        n_size += BUF_SIZE;
                        buffer = _realloc(buffer, n_size, n_size + 1);
                        if (buffer == NULL)
                        {
                                perror("Error: Cannot Reallocate");
                                return (-1);
                        }
                }
        }
        buffer[i] = '\0';
        *lineptr = malloc(sizeof(char) * (i + 1));
        _strcpy(*lineptr, buffer);
        free(buffer);
        return (i);
}
