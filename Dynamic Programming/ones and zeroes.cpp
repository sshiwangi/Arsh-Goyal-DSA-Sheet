class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      //declare a 2d matrix
        int dp[m+1][n+1];
      //initialize it with 0
         memset(dp, 0, sizeof(dp));
      //iterate over the individual strings of the array
        for(auto str :strs){
            int ones = 0;
            int zeros = 0;
          // iterate over each character of the string
            for(int i = 0; i<str.length(); i++){
              // if the character is 0, increment the value of zeroes and if its 1, increment the value of ones
                if(str[i] == '0') zeros++;
                else ones++;
            }
    //the number of zeros ranges from m to 0
           for(int j = m; j>=zeros; j--){
              //the number of ones ranges from n to 0
            for(int k = n; k>=ones; k--){
              // store the maximum of both the possibilities that is accepting the string and rejecting the string
                    dp[j][k] = max(dp[j-zeros][k-ones]+1,dp[j][k]);
            }
          } 
        }
        return dp[m][n];
    }
};
