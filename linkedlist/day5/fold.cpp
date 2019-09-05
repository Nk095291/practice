/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// recursive
class Solution {
    
    ListNode* getmid(ListNode* head)
    {
        ListNode* f = head;
        ListNode* s = head->next;
        while(s&&s->next)
        {
            f=f->next;
            s=s->next->next;
        }
        
        return f;
    }
    
    ListNode* merge(ListNode* one ,ListNode* two) 
    {
        ListNode* d = new ListNode(-1);
        ListNode* t = d;
        while(one&&two)
        {
            if(one->val<two->val)
            {
                t->next = one;
                one=one->next;
            }
            else{
                t->next =two;
                two=two->next;
            }
            t=t->next;
        }
        if(one)
        {
            t->next = one;
        }
        if(two)
            t->next  = two;
        return d->next;
        
    }
    
    ListNode* mergesort(ListNode* head)
    {
        if(!head||!head->next)
            return head;
        ListNode* mid = getmid(head);
        ListNode* start2=mid->next;
        mid->next = NULL;
        ListNode* l = mergesort(head);
        ListNode* r = mergesort(start2);
        
        ListNode* res =merge(l,r);
        return res;
    }
public:
    ListNode* sortList(ListNode* head) {
        
        return mergesort(head);
        
    }
};


//iterative
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

      ListNode* getmid(ListNode* head)
    {
          
        ListNode* f = head;
        ListNode* s = head->next;
        while(s&&s->next)
        {
            f=f->next;
            s=s->next->next;
        }
        
        return f;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* next = cur->next ;
            cur->next = pre;
            pre = cur;
            cur=next;
        }
        return pre;
    }
    
    
    ListNode* merge(ListNode* one,ListNode* two)
    {
        ListNode* head = one;
        while(one&&two){
        ListNode* t1 = one->next ;
        ListNode* t2=two->next;
        one->next =two;
        two->next = t1;
        one =t1;
        two = t2;
        }
        return head;
    }
public:
    void reorderList(ListNode* head) {
        if(!head||!head->next)
            return ;
      ListNode* mid = getmid(head);
        ListNode* head2 = mid->next;
        cout<<mid->val<<endl;
        mid->next = NULL;
        head2=reverse(head2);
        
        
        head= merge(head,head2);
    }
};