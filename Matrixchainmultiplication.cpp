//recurcive
long int MCM(int a[],int i,int j)
{  int k=0;
   
  if(i==j)
      m[i][j]=0;
    if(m[i][j]!=-1) return m[i][j];
    long int cost=INT_MAX;
    
     for(k=i;k<j;k++)
     {
       long int min_cost=MCM(a,i,k)+MCM(a,k+1,j)+a[i-1]*a[k]*a[j];
       if(min_cost<cost)
       cost=min_cost;
     }
     m[i][j]=cost;
    
   return cost;
}

//Top down

{
	    int n;
	    cin >> n;
	    int m= n-1;
	    int A[n];
	   int M[n][n];
	    for(int i = 0;i<n;i++)
	        cin >> A[i];
	    for(int i = 1;i<=m;i++)
	        M[i][i] = 0;
	    for(int l = 2;l<=m;l++)
	    {
	        for(int i = 1;i<=m-l+1;i++)
	        {
	            int j = i+l-1;
	            M[i][j]=INT_MAX;
	            for(int k = i;k<=j-1;k++)
	            {
	                int q = A[i-1]*A[k]*A[j]+M[i][k]+M[k+1][j];
	                if(q<M[i][j])
	                    M[i][j] = q;
	            }
	            //cout << M[i][j] << " ";
	        }
	    }
	    cout<< M[1][n-1] << endl;
	}