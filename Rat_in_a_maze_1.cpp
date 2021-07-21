    int N;
    int vis[5][5];
    vector<string>v;
    string s;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    char c[4]={'U','R','D','L'};
    bool isvalid(int x,int y){
        if(x<0 || x>N-1 || y<0 || y>N-1)
           return false;
        if(vis[x][y]==1)
          return false;
          
      return true;      
    }
    void dfs(int x,int y,vector<vector<int>> &m){
        vis[x][y]=1;
        if(x==N-1 && y==N-1){
            v.push_back(s);
           // return;
        }
        for(int i=0;i<4;i++){
            if(isvalid(x+dx[i],y+dy[i]) && m[x+dx[i]][y+dy[i]]){
                s.push_back(c[i]);
                dfs(x+dx[i],y+dy[i],m);
                s.pop_back();
            }
        }
        vis[x][y]=0;
       // return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        //int vis[n][n];
        N=n;
        memset(vis,0,sizeof(vis));
        if(m[0][0]) dfs(0,0,m);
        sort(v.begin(),v.end());
        return v;
    }