#include "main.h"
#include <stdlib.h>

/**
 * create_file - creates file
 *
 * @filename: file to be created;
 * @text_content: content of text
 * Return: int
 */

int create_file(const char *filename, char *text_content)
{
        int file_p, file_wr, curr;

        curr = 0;

        if (filename == NULL || text_content == NULL)
                return (-1);

        if (text_content == NULL)
                return (1);
        while (text_content[curr] != '\0')
                curr++;

        file_p = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

        if (file_p == -1)
                return (-1);
        file_wr = write(file_p, text_content, curr);

        if (file_wr == -1)
                return (-1);

        close(file_p);

        return (1);
}
