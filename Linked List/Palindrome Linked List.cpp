class Solution {
public:
    ListNode* reverseList(ListNode *head){
        ListNode* cur=head;
        ListNode* prv=NULL;
        ListNode* nextptr;
        while(cur!=NULL){
            nextptr=cur->next;
            cur->next=prv;
            prv=cur;
            cur=nextptr;
        }
        return prv;
    }
    //Function to find the middle of the linked list
    ListNode* middle(ListNode *head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
           slow=slow->next;
           fast=fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return true;
        }
        ListNode* mid=middle(head);
        ListNode* last=reverseList(mid); // 5->4->3 , last = 5
        ListNode* curr=head; // 1->2->3->4->5  , curr = 1
        // Move till the middle of the linked list from the last
        while(last!=NULL){
            if(last->val!=curr->val){
                return false;
            }
            last=last->next;
            curr=curr->next;
        }
        return true;
    }
};
