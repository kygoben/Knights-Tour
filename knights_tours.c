#include <stdio.h>
#define N 5

int locationCheck(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}
void print(int sol[N][N])
{
    int printnum = 1;
    int out = 0;
    while (out < N * N)
    {
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
                if (sol[x][y] == out)
                {
                    int temp = 1;
                    temp += x * N;
                    temp += y;
                    printf("%2d", temp);
                    if (printnum++ < 25)
                        printf(",");
                }
        }
        out++;
    }
    printf("\n");
}

int pathFinder(int x, int y, int numMoves, int sol[N][N],
               int xMove[N], int yMove[N])
{
    int k;
    int next_x;
    int next_y;
    if (numMoves == N * N) //if you have made 25 moves
    {
        print(sol);
        return 0;
    }
    for (k = 0; k < 8; k++)
    {
        next_x = x + xMove[k]; //move to a next space
        next_y = y + yMove[k];
        if (locationCheck(next_x, next_y, sol)) //if it is a valid space
        {
            sol[next_x][next_y] = numMoves;                              //move here next
            pathFinder(next_x, next_y, numMoves + 1, sol, xMove, yMove); //move further and check the next space for possible paths
            sol[next_x][next_y] = -1;                                    // backtracking
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    for (int f = 0; f < N; f++) //loop for all starting spaces
    {
        for (int j = 0; j < N; j++)
        {
            int sol[N][N];
            for (int x = 0; x < N; x++)
                for (int y = 0; y < N; y++)
                    sol[x][y] = -1;

            int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2}; //all next possible moves
            int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

            sol[f][j] = 0;                          //starting space
            pathFinder(f, j, 1, sol, xMove, yMove); //find possible paths
        }
    }
    return 0;
}
