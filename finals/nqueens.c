#include <stdio.h>

int count = 0;

int noAttack(char board[100][100], int row, int col, int n)
{
    for (int y = 0; y < n; y++)
    {
        if (board[row][y] == 'Q')
            return 0;
    }

    for (int y = 0; y < n; y++)
    {
        if (board[y][col] == 'Q')
            return 0;
    }

    int x = row, y = col;

    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 'Q')
            return 0;
        x--;
        y--;
    }
    x = row;
    y = col;
    while (x >= 0 && y <= n)
    {
        if (board[x][y] == 'Q')
            return 0;
        x--;
        y++;
    }
    return 1;
}

int solve(char board[100][100], int n, int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%c\t", board[i][j]);
            }
            printf("\n");
        }
    }

    for (int col = 0; col < n; col++)
    {
        if (noAttack(board, row, col, n))
        {
            board[row][col] = 'Q';
            int canPlaceQueen = solve(board, n, row + 1);
            if (canPlaceQueen == 1)
                return 1;
            board[row][col] = '-';
        }
    }
    return 0;
}

void main()
{

    int n;
    char board[100][100];

    printf("Enter number of queens: ");
    scanf("%d", &n);

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            board[x][y] = '-';
        }
    }
    solve(board, n, 0);
}