/**
 * fifteen.c
 *
 * CS50 AP
 * Name: ________________
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 * 
 * Note: Comments have been intentionally removed from 
 * main function in this distro file
 */
 
#include "fifteen.h"

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    greet();

    init();

    while (true)
    {
        clear();

        draw();

        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        if (won())
        {
            printf("ftw!\n");
            break;
        }

        printf("Tile to move: ");
        int tile = GetInt();
        
        if (tile == 0)
        {
            break;
        }

        fprintf(file, "%i\n", tile);
        fflush(file);

        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        usleep(500000);
    }

    fclose(file);

    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    return false;
}