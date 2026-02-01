/* Author : Vansh Kumar
  Date : 2025-01-02
  Description: Leetcode problem-21
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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        //Recursive approach 
        /*if( head1 == NULL || head2 == NULL){
            return head1 == NULL ? head2 : head1;
        }

        //case1
        if( head1->val <= head2->val){
            head1->next = mergeTwoLists(head1->next , head2);
            return head1;
        } else{ //case2
            head2->next = mergeTwoLists(head1 , head2->next);
            return head2;
        }*/

        //Iterative approach
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (head1 != NULL && head2 != NULL) {
            if (head1->val <= head2->val) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }

        if (head1 != NULL) tail->next = head1;
        else tail->next = head2;

        return dummy->next;
    }
};
