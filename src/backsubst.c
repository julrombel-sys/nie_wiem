#include "backsubst.h"
#include <stdio.h>

int backsubst(double A[][100], double b[], double x[], int k)
{
  int i,j;
  
  for(i = k - 1; i >= 0; i--)
  {
    /*sprawdzanie na przekatnej*/
    if(A[i][i] == 0.0)
    {
      return 1; /*blad*/
    }
    x[i] = b[i];
    for(j = i + 1; j < k; j++)
      {
      x[i] -= A[i][j] * x[j];
      }
    x[i] /= A[i][i];
  }

  return 0; /*sukces*/
}


