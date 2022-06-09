class Solution {
public:
    // Function to find length of the linked lists
int length(ListNode* head){
    int l =0;
    ListNode* temp = head;
    while(temp!=NULL){
        temp= temp->next;
        l++;
    }
    return l;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int l1 = length(headA);
    int l2 = length(headB);
    
    ListNode* ptr1;
    ListNode* ptr2;
    int d = 0;
    
    // we will put ptr1 at the head of the longer linked list 
    //and later move it to the differece of the length of the lined lists
    if(l1>l2){
        d = l1-l2;
        ptr1 = headA;
        ptr2 = headB;
    }
    else{
        d = l2-l1;
        ptr1 = headB;
        ptr2 = headA;
    }
    // putting ptr1 at the difference of l1 and l2
    while(d){
        ptr1 = ptr1->next;
        if(ptr1 == NULL){
            return NULL;
        }
        d--;
    }
    
    while(ptr1!=NULL && ptr2 !=NULL){
        // if ptr1 becomes equal to ptr2, we will get our intersection point
        if(ptr1 == ptr2){
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
    }
};
