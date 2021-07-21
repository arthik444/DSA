 int vis[50][50];
    int n,m,z,r;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool isvalid(int x,int y){
        if(x<0 || x>m-1 || y<0 || y>z-1)
            return false;
        if(vis[x][y])
            return false;
        
        return true;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc){
        vis[sr][sc]=1;
        image[sr][sc]=n;
        for(int i=0;i<4;i++){
            if(isvalid(sr+dx[i],sc+dy[i]) && image[sr+dx[i]][sc+dy[i]]==r)
                dfs(image,sr+dx[i],sc+dy[i]);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n=newColor;
        r=image[sr][sc];
        m=image.size();
        z=image[0].size();
        dfs(image,sr,sc);
        return image;
    }