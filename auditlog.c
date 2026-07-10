#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define FILE_NAME "audit.log"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int fd;

    if (argc < 2)
    {
        write(1, "Usage: ./auditlog --add \"message\" | --view\n", 43);
        return 1;
    }

    if (strcmp(argv[1], "--add") == 0)
    {
        if (argc < 3)
        {
            write(1, "Please provide a message.\n", 26);
            return 1;
        }

        fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_APPEND, 0644);

        if (fd < 0)
            return 1;

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        close(fd);
    }
    else if (strcmp(argv[1], "--view") == 0)
    {
        fd = open(FILE_NAME, O_RDONLY);

        if (fd < 0)
        {
            write(1, "No log file found.\n", 19);
            return 1;
        }

        char buffer[BUFFER_SIZE];
        int bytesRead;
        int line = 1;

        write(1, "1: ", 3);

        while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0)
        {
            for (int i = 0; i < bytesRead; i++)
            {
                write(1, &buffer[i], 1);

                if (buffer[i] == '\n')
                {
                    line++;

                    char num[20];
                    int len = sprintf(num, "%d: ", line);

                    write(1, num, len);
                }
            }
        }

        close(fd);
    }
    else
    {
        write(1, "Invalid option.\n", 16);
    }

    return 0;
}
