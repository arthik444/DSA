 int editDistance(string s, string t) {
        int n=s.size(),m=t.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0) dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
                else if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
                                  //insert    //remove   //replace
                }
            }
        }
        dp[n][m];
    }


int editDistance(string s, string t) {
         int m=s.size();
         int n=t.size();
       int dp[m+1][n+1];
    
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
            dp[0][j]=j;
            
            else if(j==0)
            dp[i][0]=i;
            
            else if(s[i-1]==t[j-1])
            {
               dp[i][j]=dp[i-1][j-1]; 
            }
            
            else
            {
                dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
            }
        }
    }
    return dp[m][n];
    }