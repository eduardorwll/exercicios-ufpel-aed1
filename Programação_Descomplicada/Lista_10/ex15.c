#include <stdio.h>
#include <stdlib.h>

void printGreaters(int **mtx, int r, int c)
{
    int greaters[3] = {0};
    int i, j, k;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (mtx[i][j] > greaters[0])
            {
                greaters[2] = greaters[1];
                greaters[1] = greaters[0];
                greaters[0] = mtx[i][j];
            }
            else if (mtx[i][j] > greaters[1])
            {
                greaters[2] = greaters[1];
                greaters[1] = mtx[i][j];
            }
            else if (mtx[i][j] > greaters[2])
            {
                greaters[2] = mtx[i][j];
            }
        }
    }

    printf("\n\nMaiores numeros: %d, %d e %d \n\n", greaters[0], greaters[1], greaters[2]);
}

int main(void)
{
    int rows, cols;
    int i, j, c;
    int count;

    printf("\nInsira o numero de colunas: ");
    scanf("%d", &cols);

    printf("\nInsira o numero de linhas: ");
    scanf("%d", &rows);

    int **mtx = (int **)malloc(sizeof(int *) * rows);

    if (!mtx)
    {
        return -1;
    }

    for (c = 0; c < rows; c++)
    {
        mtx[c] = (int *)malloc(sizeof(int) * cols);
        if (!mtx[c])
        {
            return -1;
        }
    }

    count = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            mtx[i][j] = ++count;
            printf("%d ", mtx[i][j]);
        }
        printf("\n");
    }

    printGreaters(mtx, rows, cols);

    for (c = 0; c < rows; c++)
    {
        free(mtx[c]);
    }

    free(mtx);
}