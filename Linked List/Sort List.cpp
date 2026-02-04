/* Author : Vansh Kumar
  Date : 2025-05-02
  Description: Leetcode problem-148
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
    ListNode* middleFind(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while( fast != NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge( ListNode* l1 , ListNode* l2){
        ListNode* dummyNode = new ListNode(0);
        ListNode* tail = dummyNode;

        while( l1 && l2 ){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            } else{
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        return dummyNode->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* mid = middleFind(head);
        ListNode* rightHead = mid->next;
        mid->next = NULL; //split

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return merge(left , right);
    }
};
