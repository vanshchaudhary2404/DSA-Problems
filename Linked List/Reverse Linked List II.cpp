/* Author : Vansh Kumar
  Date : 2025-01-02
  Description: Leetcode problem-92
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        for(int i=1; i<left; i++){
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        ListNode* prevSub = NULL;
        ListNode* nextNode = NULL;

        for(int i=0; i<= right -left; i++){
            nextNode = curr->next;
            curr->next = prevSub;
            prevSub = curr;
            curr = nextNode;
        }

        prev->next->next = curr;
        prev->next = prevSub;

        return dummy->next;

    }
};
