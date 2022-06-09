class Solution {
public:
    // Function to find the length of linked list
    int length(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            temp = temp -> next;
            count++;
        }
        return count;
    }
    // Function to reverse linked list
    ListNode* reverse(ListNode* head){
        ListNode* prevptr = NULL;
        ListNode* currptr = head;
        ListNode* nextptr;
        while(currptr!=NULL){
            nextptr = currptr -> next;
            currptr -> next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        return prevptr;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        int n1 = length(l1);
        int n2 = length(l2);
        // swaping first and second
        if(n1 < n2){
            ListNode* temp = l1;
            l1 = l2;
            l2 = temp;
        }
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
       // This while loop will break when we traverse along the linked list of smaller length
        while(temp2!=NULL){
            temp1->val += temp2->val + carry;
            
            if(temp1->val > 9){
                temp1->val -= 10;
                carry = 1;
            }else{
                carry = 0;
            }
            
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        // This while loop runs after we are done traversing the smaller length linked list and
        // there is still nodes left in the linked list of larger length
        while(temp1!=NULL){
            // since there is only one linked list left add only carry to the data each time
            temp1->val += carry;
            
            if(temp1->val > 9){
                temp1->val -= 10;
                carry = 1;
            }else{
                carry = 0;
            }
            
            temp1 = temp1 -> next;
        }
        //re reverse the first to give the answer
        l1 = reverse(l1);
        // if carry is 1 then make a new node and make its next point to the first node
        if(carry == 1){
            ListNode* n = new ListNode(1);
            n->next = l1;
            // now our head will be n so store n in the first
            l1 = n;
        }
        // and return the answer
        return l1;
    }
};
