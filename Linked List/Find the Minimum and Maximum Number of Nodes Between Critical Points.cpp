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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int last = -1;
        int minDis = INT_MAX;
        int pos = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;

        while( curr != nullptr && curr->next != nullptr  ){
            bool isCritical = (curr->val > prev->val && curr->val > curr->next->val) ||(curr->val < prev->val && curr->val < curr->next->val);

            if(isCritical){
                if(first == -1){
                    first = pos;
                }else{
                    minDis = min(minDis , pos-last);
                }

                last = pos;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        if(first == -1 || first == last){
            return {-1 ,-1};
        }
        int maxDis = last - first;

        return {minDis , maxDis};
    }
};
