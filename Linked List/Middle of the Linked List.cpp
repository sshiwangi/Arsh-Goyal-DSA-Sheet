class Solution {
public:
  //Function to find the length of the linked list
    int length(ListNode* head){
        int l = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            l++;
        }
        return l;
    }
    ListNode* middleNode(ListNode* head) {
        int l = length(head);
        int pos = l/2;
        
        if(head->next == NULL){
	        return head;
	    }
        
        ListNode* temp = head;
        int count = 1;
        while(temp!=NULL){
            if(count == pos){
                break;
            }
            temp = temp->next;
            count++;
        }
        return temp->next;
    }
};
