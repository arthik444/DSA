int t[201][201];
    int solve(int n,int f){
        if(f==0 || f==1 || n==1) return f;
        if(t[n][f]!=-1) return t[n][f];
        int mn=INT_MAX;
        for(int k=1;k<=f;k++){
            int temp=1+max(solve(n-1,k-1),solve(n,f-k));
            mn=min(temp,mn);
        }
        return t[n][f]=mn;
    }
    int eggDrop(int n, int k) 
    {
      memset(t,-1,sizeof(t));
      return solve(n,k);
    }