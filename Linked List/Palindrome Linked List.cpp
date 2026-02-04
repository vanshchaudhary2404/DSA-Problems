/* Author : Vansh Kumar
  Date : 2025-05-02
  Description: Leetcode problem-234
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
    ListNode* reverse(ListNode* head){
            if(head == NULL || head->next == NULL) return head;
            ListNode* newHead = reverse(head->next);
            ListNode* front = head->next;
            front->next = head;
            head->next = NULL;
            return newHead;
    }

    bool isPalindrome(ListNode* head) {
        //uing stack
        /*stack<int> s;
        ListNode* temp = head;
        while(temp != NULL){
            s.push(temp->val);
            temp= temp->next;
        }
        temp = head;
        while(temp != NULL){
            if(temp->val != s.top()) return false;
            temp = temp->next;
            s.pop();
        }
        return true;
        */


        //Changing link using slow & fast;
        if(head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        //go to mid but mid left node
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverse(slow->next);
        ListNode* first = head;
        ListNode* sec = newHead;
        while( sec != NULL){
            if(first->val != sec->val){
                reverse(newHead);
                return false;
            }
            first = first->next;
            sec = sec->next;
        }
        return newHead;

    }
};
