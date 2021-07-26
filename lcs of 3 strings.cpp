int LCSof3 (string X, string Y, string Z, int n1, int n2, int n3)
{
      int L[n1+1][n2+1][n3+1];
    for (int i=0; i<=n1; i++)
    {
        for (int j=0; j<=n2; j++)
        {
            for (int k=0; k<=n3; k++)
            {
                if (i == 0 || j == 0||k==0)
                    L[i][j][k] = 0;
 
                else if (X[i-1] == Y[j-1] && X[i-1]==Z[k-1])
                    L[i][j][k] = L[i-1][j-1][k-1] + 1;
 
                else
                    L[i][j][k] = max(max(L[i-1][j][k],
                                         L[i][j-1][k]),
                                     L[i][j][k-1]);
            }
        }
    }
    return L[n1][n2][n3];
}