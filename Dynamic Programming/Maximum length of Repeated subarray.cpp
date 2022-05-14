class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int t[n + 1][m + 1];
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<m+1; j++){
                //if both of the arrays are empty store 0 in t[i][j]
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                //if the elememts are equal, add 1 and check for remaining ones
                if(nums1[i-1] == nums2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                // if the elements are unequal, t[i][j] = 0 because we need to find the subarray and order is important
                else{
                    t[i][j] = 0;
                }
            }
        }
        int mx=INT_MIN;
        // loop over the dp
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<m+1; j++)
            {
                // and take maximum of mx and t[i][j]
                mx=max(mx,t[i][j]);
            }
        }
        return mx;
    }
};
