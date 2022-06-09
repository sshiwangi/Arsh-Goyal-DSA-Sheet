class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        // call recursion for the next of head, it will reverse the node except head
        ListNode* newhead = reverseList(head->next);
        // after that reverse the link of head and its next too
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};
