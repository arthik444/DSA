 unordered_map<string,vector<string> >v;
    unordered_map<string,int>vis,dis;
    bool isvalid(string a,string b){
        int c=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) c++;
        }
        if(c==1) return true;
        else return false;
    }
    void buildgraph(vector<string>& w){
        for(int i=0;i<w.size();i++){
            for(int j=i+1;j<w.size();j++){
                string a=w[i];
                string b=w[j];
                if(isvalid(a,b)){
                    v[a].push_back(b);
                    v[b].push_back(a);
                }
            }
        }
    }
    void bfs(string s){
        queue<string>q;
        q.push(s);
        vis[s]=1;
        dis[s]=1;
        while(!q.empty()){
            string x=q.front();
            q.pop();
            for(auto child:v[x]){
                if(vis.find(child)==vis.end()){
                    q.push(child);
                    dis[child]=dis[x]+1;
                    vis[child]=1;
                }
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool flag=true;
        for(int i=0;i<wordList.size();i++){
            if(beginWord==wordList[i])
                flag=false;
        }
        if(flag)
            wordList.push_back(beginWord);
        buildgraph(wordList);
        bfs(beginWord);
        return dis[endWord];
    }