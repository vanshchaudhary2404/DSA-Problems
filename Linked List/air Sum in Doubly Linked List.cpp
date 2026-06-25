/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int , int>> res;
        
        if( head == NULL || head->next == NULL){
            return res;
        }
        
        Node* left = head;
        Node* right = head;
        while( right->next != NULL){
            right = right->next;
        }
        
        while( left != right && left->prev != right){
            int currSum = left->data + right->data;
            
            if( currSum == target){
                res.push_back({left->data , right->data});
                left = left->next;
                right = right->prev;
            }
            else if( currSum < target){
                left = left->next;
            }else{
                right = right->prev;
            }
        }
        
        return res;
    }
};
