class Solution {
public:
    int numofOnes(int n){
        int count = 0;
        // when n becomes 0, the value of count will be equal to no. of ones
        while(n!=0){
            count ++;
            n = n & (n-1);
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 0; i<n+1; i++){
            ans[i] = numofOnes(i);
        }
        return ans;
    }
};
