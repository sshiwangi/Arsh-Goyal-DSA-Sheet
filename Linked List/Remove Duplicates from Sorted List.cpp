class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // one pointer
        // if(head == NULL || head->next == NULL)
        //     return head;
        // ListNode *curr = head;
        // while(curr!=NULL && curr->next!=NULL)
        // {
        //     if(curr->next->val == curr->val)
        //         curr->next = curr->next->next;
        //     else
        //         curr = curr->next;
        // }
        // return head;
        
        // Two pointer
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* nextp = curr->next;
        
        while(curr!=NULL && nextp!=NULL){
     // if the curr and next are equal, change the linkes that is make the next of curr point 
     // to the next of nextp
           if(nextp->val == curr->val) {
               
               curr->next = nextp->next;
               nextp = nextp->next;
           }
    // else do curr = next and move next pointer one step ahead too 
           else{
               curr = nextp;
               nextp = nextp->next;
           }
    
        }
 // lastly return head;
        return head;
    }
};
