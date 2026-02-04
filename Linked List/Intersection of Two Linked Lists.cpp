/* Author : Vansh Kumar
  Date : 2025-05-02
  Description: Leetcode problem-160
*/
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
    int getLength(ListNode* head){
        int len = 0;
        while( head){
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Using map
        /*map<ListNode* , int> mp;
        ListNode* temp = headA;
        while( temp != NULL){
            mp[temp] = 1 ;
            temp = temp->next;
        }
        temp = headB;
        while( temp != NULL){
            if( mp.find(temp) != mp.end() ){
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
        */


        //Length Difference
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        while(lenA > lenB){
            headA = headA->next;
            lenA--;
        }
        while(lenB > lenA){
            headB = headB->next;
            lenB--;
        }
        while( headA && headB){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;//travel lenA+lenB
            headB = headB->next;//travel lenA+lenB
        }
        return NULL;
    }
};
