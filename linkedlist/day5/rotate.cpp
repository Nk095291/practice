/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
      int getsize(ListNode* head)
    {
        int size =0;
        while(head)
        {
            size++;
            head=head->next;
        }
        return size;
    }
    ListNode* gettail(ListNode* head)
    {
        while(head->next)
        {
            head=head->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        int size = getsize(head);
        k=k%size;
        if(k==0)
            return head;
        ListNode* first =head;
        ListNode* second = head;
        for(int i=0;i<k+1;i++)
        {
            second=second->next;
        }
        while(second)
        {
            first = first->next;
            second = second->next;
        }
        ListNode* newhead = first->next;
        first->next=NULL;
        gettail(newhead)->next=head;
        return newhead;
    }
};

// good solution

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};