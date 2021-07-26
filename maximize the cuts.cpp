  int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
       dp[0]=0;
        for(int i=1;i<=n;i++){
            if(x<=i) dp[i]=max(dp[i],(dp[i-x]>=0)?dp[i-x]+1:-1);
            if(y<=i) dp[i]=max(dp[i],(dp[i-y]>=0)?dp[i-y]+1:-1);
            if(z<=i) dp[i]=max(dp[i],(dp[i-z]>=0)?dp[i-z]+1:-1);
            //cout<<dp[i]<<" ";
        }
        if(dp[n]<0) dp[n]=0;
        return dp[n];
    }