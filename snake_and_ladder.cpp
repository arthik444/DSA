    pair<int, int> coordinates(int x, int n) 
    {
        int r = n - (x-1)/n -1;
        int c = (x-1)%n;
        if(r%2==n%2)
            return {r,n-c-1};
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size(),steps=0;
        int vis[n][n];
        memset(vis,0,sizeof(vis));
        vis[n-1][0]=1;
        queue<int>q;
        q.push(1);
        while(!q.empty()){
            int z=q.size();
            for(int i=0;i<z;i++){
                int d=q.front();
                if(d==n*n) return steps;
                q.pop();
                for(int j=1;j<=6;j++){
                    if(j+d>n*n) break;
                    pair<int,int>p = coordinates(j+d,n);
                    if(vis[p.first][p.second]) continue;
                    vis[p.first][p.second]=1;
                    if(board[p.first][p.second]!=-1){
                        q.push(board[p.first][p.second]);
                    }else{
                        q.push(j+d);
                    }
                }
            }
            steps++;
        }
        return -1;
    }