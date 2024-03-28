#include "slide_line.h"

/**
 * slide_line - Slide and merge an array of integers
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, j, k;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
        {
            if (line[i] == 0)
            {
                for (j = i + 1; j < size; j++)
                {
                    if (line[j] != 0)
                    {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }

            for (k = i + 1; k < size; k++)
            {
                if (line[k] != 0)
                {
                    if (line[i] == line[k])
                    {
                        line[i] *= 2;
                        line[k] = 0;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    else if (direction == SLIDE_RIGHT)
    {
        for (i = size - 1; i < size; i--)
        {
            if (line[i] == 0)
            {
                for (j = i - 1; j < size; j--)
                {
                    if (line[j] != 0)
                    {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }

            for (k = i - 1; k < size; k--)
            {
                if (line[k] != 0)
                {
                    if (line[i] == line[k])
                    {
                        line[i] *= 2;
                        line[k] = 0;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    return (1);
}