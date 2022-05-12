class Solution {
public:
   
    int climbStairs(int n) {
        //initialize dp
        int dp[n+2];
        dp[1] = 1; // if n = 1 then there is only one possible way
        dp[2] = 2; // if n = 2 then there are two possible ways to reach 2nd stair, either 1 step each time or 2 steps at once
        for(int i = 3; i < n+1; ++i)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];    
    }
};
