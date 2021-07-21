 int mp[501][501];
    int n,m;
    int dx[8]={-1,0,1,0,-1,1,-1,1};
    int dy[8]={0,1,0,-1,-1,1,1,-1};
    bool isvalid(int x,int y){
        if(x<0 || x>n-1 || y<0 || y>m-1)
             return false;
        
        return true;         
    }
    void dfs(int x,int y,vector<vector<char>>& grid){
        mp[x][y]=1;
        for(int i=0;i<8;i++){
            if(isvalid(x+dx[i],y+dy[i]) && grid[x+dx[i]][y+dy[i]]=='1' && mp[x+dx[i]][y+dy[i]]==0){
                dfs(x+dx[i],y+dy[i],grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int c=0;
        n=grid.size();
        m=grid[0].size();
        memset(mp,0,sizeof(mp));
        for(int i=0;i<n;i++){
            //cout<<i<<endl;
            for(int j=0;j<m;j++){
            if(mp[i][j]==0 && grid[i][j]=='1'){
                dfs(i,j,grid);
                c++;
               // cout<<i<<" "<<j<<endl;
               //cout<<mp[grid[3][0]]<<endl;
            }
            }
        }
        //cout<<mp[grid[3][0]]<<endl;
        return c;
    }