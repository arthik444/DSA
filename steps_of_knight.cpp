 int vis[1001][1001];
    int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    int n;
    bool isvalid(int x,int y){
        if(x<1 || x>n || y<1 || y>n)
          return false;
        if(vis[x][y])
          return false;
          
        return true;  
    }
	int minStepToReachTarget(vector<int>&K,vector<int>&T,int N)
	{  
	    n=N;
	    memset(vis,0,sizeof(vis));
	    int dis[N+1][N+1];
	    dis[K[0]][K[1]]=0;
	    vis[K[0]][K[1]]=1;
	    queue<pair<int,int> >q;
	    q.push({K[0],K[1]});
	    while(!q.empty()){
	        int cx=q.front().first;
	        int cy=q.front().second;
	        q.pop();
	        if(cx==T[0] && cy==T[1]){
	            return dis[cx][cy];
	        }
	        for(int i=0;i<8;i++){
	            if(isvalid(cx+dx[i],cy+dy[i])){
	                int nx=cx+dx[i];
	                int ny=cy+dy[i];
	                dis[nx][ny]=dis[cx][cy]+1;
	                vis[nx][ny]=1;
	                q.push({nx,ny});
	            }
	        }
	    }
	}