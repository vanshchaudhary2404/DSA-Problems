/* Author : Vansh Kumar
  Date : 2025-05-02
  Description: Leetcode problem-19
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        ListNode* slow = dummy;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

       ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;

        return dummy->next; 
    }
};
