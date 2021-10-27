#include "sandpiles.h"

/**
 * check - check for stability
 * @grid: Left 3x3 grid
 * Return: int
 *
 */
int check(int grid[3][3])
{
 int i = 0, j = 0;
 for (i = 0; i < 3; i++)
 {
  for (j = 0; j < 3; j++)
  {
   if (grid[i][j] > 3)
    return (1);
  }
 }
 return (0);
}

/**
 * print - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print(int grid[3][3])
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
 * sandpiles_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
 int i = 0, j = 0, x = 0, y = 0, var = 0;
 int tmp[3][3];

 for (i = 0; i < 3; i++)
 {
  for (j = 0; j < 3; j++)
  {
   grid1[i][j] = grid1[i][j] + grid2[i][j];
  }
 }
 var = check(grid1);
 while (var == 1)
 {
  printf("=\n");
  print(grid1);
  for (i = 0; i < 3; i++)
  {
   for (j = 0; j < 3; j++)
    tmp[i][j] = grid1[i][j];
  }
  for (x = 0; x < 3; x++)
  {
   for (y = 0; y < 3; y++)
   {
    if (tmp[x][y] >= 4)
    {
     grid1[x][y] -= 4;
     if (x >= 1)
      grid1[x - 1][y] += 1;
     if (x <= 1)
      grid1[x + 1][y] += 1;
     if (y >= 1)
      grid1[x][y - 1] += 1;
     if (y <= 1)
      grid1[x][y + 1] += 1;
    }
   }
  }
  var = check(grid1);
 }
}