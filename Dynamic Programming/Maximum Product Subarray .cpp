class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prod = 1, maxprod = INT_MIN;
        for(int i = 0; i<n; i++){
            prod *= nums[i];
            maxprod = max(maxprod, prod);
            // whenever the product becomes 0, make it 1
            if(prod == 0){
                prod = 1;
            }
        }
        prod = 1;
        // traversing from the right direction
        for(int i = n-1; i>0; i--){
            prod *= nums[i];
            maxprod = max(maxprod, prod);
            if(prod == 0){
                prod = 1;
            }
        }
        return maxprod;
    }
};
