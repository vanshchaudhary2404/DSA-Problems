/* Author : Vansh Kumar
  Date : 2025-01-02
  Description: Leetcode problem-430
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return head;

        Node* curr = head;
        while( curr != NULL){
            //Flatten the valid child node
            if( curr->child != NULL){
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr; //to link doubly LL
                curr->child = NULL;

                //Find tail
                while( curr->next != NULL){
                curr = curr->next; 
                }
                //attach tail with nxt ptr
                if( next != NULL){
                    curr->next = next;
                    next->prev = curr;
                }
            }
            //move curr unitl child of curr occur
            curr = curr->next;
        }

        return head;
    }
};
