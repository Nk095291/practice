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
    ListNode* reverseList(ListNode* head) 
{
	ListNode* prev = NULL;
	ListNode* follow = NULL;
	while (head)
	{
		follow = head->next;
		head->next = prev;
		prev = head;
		head = follow;
	}
    return prev;
}
 bool hasCycle(ListNode *head)
{
	return head&&head->next&& head==reverseList(head);
}
};