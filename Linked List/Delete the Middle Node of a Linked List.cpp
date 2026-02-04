/* Author : Vansh Kumar
  Date : 2025-05-02
  Description: Leetcode problem-2095
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head->next->next;;

        while(fast != NULL && fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;
        }
        //now slow is on left side of mid val
        ListNode* mid = slow->next;
        slow->next = slow->next->next;
        delete mid;
        return head;
    }
};
