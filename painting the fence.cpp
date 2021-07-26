 long long countWays(int n, int k){
      long long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    long long mod = 1000000007;
 
    dp[1] = k;
    dp[2] = k * k;
 
    for (int i = 3; i <= n; i++) {
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
    }
 
    return dp[n];
    }