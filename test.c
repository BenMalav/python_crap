#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void
read_file(const char *filename, long* buffer)
{
    FILE *fp = NULL;
    long off;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("failed to fopen %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int num = 0;
    while (!feof(fp))
    {
        int tmp;
        fscanf(fp, "%d", &tmp);
        num++;
    }

    if (fseek(fp, 0, SEEK_SET) == -1)
    {
        printf("failed to fseek %s\n", filename);
        exit(EXIT_FAILURE);
    }

    buffer = NULL;
    buffer = malloc(sizeof(long) * num);
    if (buffer == NULL)
    {
        printf("failed to allocate memory\n");
    }

    num = 0;
    while (!feof(fp))
    {
        int tmp;
        fscanf(fp, "%d", &buffer[num]);
        num++;
    }

    if (fclose(fp) != 0)
    {
        printf("failed to fclose %s\n", filename);
        exit(EXIT_FAILURE);
    }
}


void
heap_sort(int* arr)
{

}


int
main(int argc, const char *argv[])
{
    long* input_buffer = NULL;
    char* file_name = "input.txt";

    read_file(file_name, input_buffer);

    free(input_buffer);

    return 0;
}
