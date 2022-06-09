// Function to merge two linked list
Node* merge(Node* head1,Node* head2){
       if(head1==NULL)
           return head2;
       if(head2==NULL)
           return head1;
       Node* res;
       if(head1->data<head2->data){
           res=head1;
           res->bottom=merge(head1->bottom,head2);
       }
       else{
           res=head2;
           res->bottom=merge(head1,head2->bottom);
       }
       res->next=NULL;
       return res;
   }
/*  Function which returns the  root of 
    the flattened linked list. */

Node *flatten(Node *root)
{
   // Your code here
    if(root==NULL || root->next==NULL)
        return root;
    return merge(root,flatten(root->next));
}
