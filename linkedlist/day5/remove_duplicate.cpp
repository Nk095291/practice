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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* t =head;
        while(head!=NULL){
            while(head->next!=NULL && head->val==head->next->val){
                ListNode* temp= head->next;
                head->next=temp->next;
                delete temp;
            }
            head=head->next;
        }
        return t;
    }
};