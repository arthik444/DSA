int LongestRepeatingSubsequence(string str){
		    int x=str.size();
		    int y=x;
       int t[x+1][y+1];
       for(int i=0;i<=x;i++){
           for(int j=0;j<=y;j++){
               if(i==0 || j==0) t[i][j]=0;
           }
       }
       for(int i=1;i<=x;i++){
           for(int j=1;j<=y;j++){
               if(str[i-1]==str[j-1] && i!=j){
                   t[i][j]=1+t[i-1][j-1];
               }else{
                   t[i][j]=max(t[i-1][j],t[i][j-1]);
               }
           }
       }
       return t[x][y];
    }