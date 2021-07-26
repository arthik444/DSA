int n;
    int subsetsum(int a[],int s){
        int t[n+1][s+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<s+1;j++){
                if(i==0) t[i][j]=false;
                if(j==0) t[i][j]=true;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<s+1;j++){
                if(a[i-1]<=j){
                    t[i][j]=(t[i-1][j-a[i-1]] || t[i-1][j]);
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][s];
    }
    int equalPartition(int N, int arr[])
    {
        n=N;
        int sum =0;
        for(int i=0;i<N;i++) sum+=arr[i];
        if(sum%2){
            return 0;
        }else{
            return subsetsum(arr,sum/2);
        }
    }