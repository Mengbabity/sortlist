/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode* p=new ListNode(0);
        ListNode* r=p;
        while(l1 && l2)
        {
            if(l1->val>l2->val)
            {
                p->next=l2;
                l2=l2->next;
            }  
            else
            {
                p->next=l1;
                l1=l1->next;
            }
            
            p=p->next;
        }
        
        if(l1)
            p->next=l1;
        
        if(l2)
            p->next=l2;
        
        return r->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* pre=NULL;
        ListNode* slow=head,*fast=head;
        
        while(fast && fast->next)
        {
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        pre->next=NULL;
        
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);
        
        return merge(l1,l2);
    }
};
