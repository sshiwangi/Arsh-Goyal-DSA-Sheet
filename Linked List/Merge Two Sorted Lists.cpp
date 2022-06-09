class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL){
    return list2;
    }
    
    if(list2 == NULL){
        return list1;
    }
    // create a result node
    ListNode* result;
    
    if(list1->val < list2->val){
        // store head1 in the result and pass its next and head2 to the function and store it in the next of result
        result = list1;
        result -> next = mergeTwoLists(list1->next, list2);
    }
    else{
        result = list2;
        result -> next = mergeTwoLists(list1, list2->next);
    }
    // lastly return the result
    return result;
    }
};
