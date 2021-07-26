 int nCr(int n, int r){
        long long c[r+1];
        long long m=1000000007;
        memset(c,0,sizeof(c));
        c[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=min(i,r);j>0;j--)
               c[j]=(c[j]%m+c[j-1]%m)%m;
        }
        return c[r];
    }

//done using pascals traingle principle
//similarly for npr npr=(n-1)pr+(r*(n-1)p(r-1))