   int maxGold(int n, int m, vector<vector<int>> M)
    {   
        int t[n+2][m+2];
        int ans=0;
        memset(t,0,sizeof(t));
        for(int j=m;j>0;j--){
            for(int i=1;i<=n;i++){
                t[i][j]=M[i-1][j-1]+max(t[i][j+1],max(t[i+1][j+1],t[i-1][j+1]));
                if(j==1){
                    ans=max(ans,t[i][j]);
                }
            }
        }
        return ans;
    }