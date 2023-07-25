struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head->next==NULL&& n==1)
return NULL;
struct ListNode* slow=head;
struct ListNode* fast=head;
struct ListNode* prev=NULL;
while(n>0)
{
fast=fast->next;
n--;
}
if(fast==NULL)
return head->next;
while(fast!=NULL)
{
prev=slow;
slow=slow->next;
fast=fast->next;
}
prev->next=slow->next;
slow->next=NULL;
return head;
}