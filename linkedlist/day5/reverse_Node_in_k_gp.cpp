/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* kreverse(ListNode* head , int k)
    {
        ListNode* pre = NULL;
        ListNode* cur = head;
        for(int i=0;i<k;i++)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = cur;
        return pre;
    }
    
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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = getsize(head); 
        cout<<size<<endl;
        if(size<k)
            return head;
        
        ListNode* res = kreverse(head,k);
       
        int count = k;
        while(count+k<=size)
        {
         
            cout<<head->val<<endl;
            ListNode* temp = head->next;
            head->next = kreverse(head->next,k);
            head = temp;
            cout<<head->val<<endl;
        
            
            count+=k;
        }
        
        return res;
        
    }
};


public ListNode reverseKGroup(ListNode head, int k) {
    ListNode curr = head;
    int count = 0;
    while (curr != null && count != k) { // find the k+1 node
        curr = curr.next;
        count++;
    }
    if (count == k) { // if k+1 node is found
        curr = reverseKGroup(curr, k); // reverse list with k+1 node as head
        // head - head-pointer to direct part, 
        // curr - head-pointer to reversed part;
        while (count-- > 0) { // reverse current k-group: 
            ListNode tmp = head.next; // tmp - next head in direct part
            head.next = curr; // preappending "direct" head to the reversed list 
            curr = head; // move head of reversed part to a new node
            head = tmp; // move "direct" head to the next node in direct part
        }
        head = curr;
    }
    return head;
}