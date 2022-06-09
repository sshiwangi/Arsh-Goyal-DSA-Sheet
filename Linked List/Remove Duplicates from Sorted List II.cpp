/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5] */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // solving using hash map
        //1. declare a hash map and traverse in the linked list and keep inserting the count of each nodes
        //2. Declare a vector that will store unique elements from the hash map.
        //3. Traverse in the vector and make the elements nodes of the linked list and return the new head
        vector<int> v;
        
        ListNode* temp = head;
        if(!head)return head;
        map<int,int> mp;
        while(temp!=NULL){
            mp[temp->val]++;
            temp = temp->next;
        }
        for(auto it:mp){
            if(it.second == 1){
                v.push_back(it.first);
            }
        }
        
        ListNode* new_head = NULL;
        ListNode* ptr;
        
        for(int i = 0; i<v.size(); i++){
            if(new_head==NULL){
                new_head = new ListNode(v[i]);
                ptr = new_head;
            }
            else{
                ptr->next = new ListNode(v[i]);
                ptr = ptr->next;
            }
        }
        return new_head;
    }
};
