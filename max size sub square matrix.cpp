  int maxSquare(int n, int m, vector<vector<int>> mat){
        int s[n][m],ans=0;
        for(int i=0;i<n;i++) s[i][0]=mat[i][0],ans=max(ans,mat[i][0]);
        for(int i=0;i<m;i++) s[0][i]=mat[0][i],ans=max(ans,mat[0][i]);
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]==1) s[i][j]=min(min(s[i-1][j],s[i][j-1]),s[i-1][j-1])+1;
                else s[i][j]=0;
                
                ans=max(ans,s[i][j]);
            }
        }
        return ans;
    }