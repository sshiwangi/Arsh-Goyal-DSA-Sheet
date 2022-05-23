class Solution {
public:
    // inorder to solve this problem, think of this array as linked list, you will see that it will form a cycle at the 
  //duplicate number so we just have to return the starting position of the cycle
    int findDuplicate(vector<int>& nums) {
        // maintain two variables slow and fast 
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            // move slow 1 step and fast 2 step until they become equal
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        // put fast at the first position
        fast = nums[0];
        // and move both one step until they become equal
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        // return slow
        return slow;
    }
};
