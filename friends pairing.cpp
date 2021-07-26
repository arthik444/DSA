  int countFriendsPairings(int n) 
    { 
        long long t[n+1];
        t[0]=0;
        t[1]=1;
        t[2]=2;
        for(int i = 3;i<=n;i++)
        {
            t[i]=(t[i-1]+(i-1)*t[i-2])%(int)(pow(10,9)+7);
        }
    }