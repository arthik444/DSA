int in[301];
    vector<int> res;
    void topo(int k,vector<vector<int> > &v){
        queue<int>q;
        for(int i=0;i<k;i++){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int c=q.front();
            res.push_back(c);
            q.pop();
            for(auto node:v[c]){
                in[node]--;
                if(in[node]==0) q.push(node);
            }
        }
    }
    string findOrder(string dict[], int N, int K) {
        vector<vector<int> >v(K);
        memset(in,0,sizeof(in));
        for(int i=0;i<N-1;i++){
            string a=dict[i];
            string b=dict[i+1];
            for(int j=0;j<min(a.size(),b.size());j++){
                if(a[j]!=b[j]){
                    v[a[j]-'a'].push_back(b[j]-'a');
                    in[b[j]-'a']++;
                    break;
                }
            }
        }
        topo(K,v);
        string s;
        for(int i=0;i<res.size();i++){
            s.push_back('a'+res[i]);
        }
        return s;
    }