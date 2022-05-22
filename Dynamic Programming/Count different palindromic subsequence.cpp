class Solution {
public:
    int countPalindromicSubsequences(string s) {
      int n = s.size();
      int dp[n][n];
      memset(dp, 0, sizeof(dp));
      const int mod = 1e9 + 7;
        // declare two vector array storing the previous and next indexes of j and i and initialize it to -1 and n
      vector<int> prev(n, -1), next(n, n);
        // declare a hash map which stores character and its prev or next index
      unordered_map<char, int> mp;
        // traverse in the string
      for (int i = 0; i < n; i++)
      {
          // if the map contains the character
         if (mp.count(s[i]))
             // store the value corresponding to the character in the map
            prev[i] = mp[s[i]];
          // otherwise leave it as it is
         mp[s[i]] = i;
      }
      mp.clear();
        // do the same for storing next indexes of the character
      for (int i = n - 1; i >= 0; i--)
      {
         if (mp.count(s[i]))
            next[i] = mp[s[i]];
         mp[s[i]] = i;
      }

      // gap strategy
        // g goes from 0 to length of the string clear from the table
      for (int g = 0; g < n; g++)
      {
         for (int i = 0, j = g; j < n; i++, j++)
         {
             // if gap == 0 then store 1 in the dp
            if (g == 0)
            {
               dp[i][j] = 1;
            }
            else if (g == 1)
            {
                // if gap == 1 then store 2
               dp[i][j] = 2;
            }
             // otherwise check
            else
            {
                  int n = next[i];
                  int p = prev[j];
                // if the character at i and j position are  not equal
                  if (s[i] != s[j])
                  {
                      
                      dp[i][j] = ((dp[i][j - 1] + dp[i + 1][j]) % mod - dp[i + 1][j - 1]) % mod;
                  }
                // if the characters are equal
                  else {
                      if (n > p)
                      {
                          dp[i][j] = ((2 * dp[i + 1][j - 1]) + 2) % mod;
                      }
                      else if (n == p)
                     {
                          dp[i][j] = ((2 * dp[i + 1][j - 1]) + 1) % mod;
                      }
                      else
                      {
                          dp[i][j] = ((2 * dp[i + 1][j - 1]) % mod - dp[n + 1][p - 1]) % mod;
                      }
                  }
                  
               }
               
            }
         }
      if (dp[0][n - 1] < 0)
         dp[0][n - 1] += mod;
      return dp[0][n - 1];
   }
};
