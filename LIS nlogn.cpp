int longestSubsequence(int n, int a[])
    {
       vector<int>res;
       for(int i=0;i<n;i++){
           auto it=lower_bound(res.begin(),res.end(),a[i]);
           if(it==res.end()) res.push_back(a[i]);
           else *it=a[i];
       }
       return res.size();
    }