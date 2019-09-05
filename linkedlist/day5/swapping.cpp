/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* swap(ListNode* a, ListNode* b)
    {
        a->next = b->next;
        b->next = a;
        return b;
        
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)
            return head;
        
            
        ListNode* first =head;
        ListNode* second = head->next;
        ListNode* dummy = new ListNode(-1);
        ListNode* t=dummy;
        while(first&&second)
        {
            t->next = swap(first,second);
            t=first;
            first=first->next;
            if(first)
            second = first->next;
        }
        return dummy->next;
    }
};