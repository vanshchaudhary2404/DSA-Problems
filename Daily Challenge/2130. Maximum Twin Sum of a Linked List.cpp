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
//Approach 1 : Brute force 
    int pairSum(ListNode* head) {
        vector<int> arr;

        ListNode* curr = head;
        while(curr != NULL){
            arr.push_back(curr->val);
            curr = curr->next;
        }

        int ans =0;
        int i=0;
        int j = arr.size()-1;
        while(i<j){
            ans = max(ans , arr[i] + arr[j]);
            i++;
            j--;
        }

        return ans;
    }

//Approach 2 : using stack
//1. stack -> push val of linkedlist
//2. find stack size -> n = stack.size()
//3. create n/2 node of linked list by calculating sum of 1st ele of LL and top of stack and push it nto 1st node of LL and so on in second node of LL and find the max of both node simultaneusly
    
    int pairSum(ListNode* head){
        ListNode* curr = head;
        stack<int> s;
        while(curr != NULL){
            s.push(curr->val);
            curr = curr->next;
        }
        int N = s.size();
        curr = head;

        int cnt = 1;
        int ans = 0;
        while(cnt <= N/2){
            ans = max( ans , curr->val + s.top());
            curr = curr->next;
            s.pop();
            cnt++;
        }

        return ans;
    }


//Approach 3: 
//1. find mid node
//2. if we reverse 2nd half
//3. add curr and mid(second half of reverse start node) value
//4. moving curr and mid , adding simultaneously.

    int pairSum(ListNode* head){
        //finding mid
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow;

        //reverse second half of  LL
        ///curr = mid
        ListNode* prev = NULL;

        while( mid != NULL){
            ListNode* nextNode = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextNode;
        }
        //now reversal node head is prev node.

        //adding value of twin to find max result;
        int res =0;
        ListNode* curr = head;
        while(prev!= NULL){
            res = max( res , curr->val + prev->val);
            curr = curr->next;
            prev = prev->next;
        }
        return res;
    }
};
