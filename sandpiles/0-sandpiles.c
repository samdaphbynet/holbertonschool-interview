#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * topple - Topple a cell in the sandpile if it has more than 3 grains
 * @grid: 3x3 grid
 * @i: row index
 * @j: column index
 */
static void topple(int grid[3][3], int i, int j)
{
    grid[i][j] -= 4;
    if (i - 1 >= 0)
        grid[i - 1][j]++;
    if (i + 1 < 3)
        grid[i + 1][j]++;
    if (j - 1 >= 0)
        grid[i][j - 1]++;
    if (j + 1 < 3)
        grid[i][j + 1]++;
}

/**
 * is_stable - Check if the sandpile is stable
 * @grid: 3x3 grid
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return 0;
        }
    }
    return 1;
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: First 3x3 grid
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int sum[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum[i][j] = grid1[i][j] + grid2[i][j];
        }
    }

    while (!is_stable(sum))
    {
        printf("=\n");
        print_grid(sum);

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (sum[i][j] > 3)
                    topple(sum, i, j);
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] = sum[i][j];
        }
    }
}
