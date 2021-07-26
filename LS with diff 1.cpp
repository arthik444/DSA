 int longestSubsequence(int N, int A[])
    { 
        int ans=1;
        int dp[N];
        for(int i=0;i<N;i++) dp[i]=1;
       for(int i=1;i<N;i++){
           for(int j=0;j<i;j++){
               if(abs(A[i]-A[j])==1) dp[i]=max(dp[i],dp[j]+1);
           }
           ans=max(ans,dp[i]);
       }
       return ans;
    }