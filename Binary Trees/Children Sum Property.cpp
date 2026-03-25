/* Author : Vansh Kumar
  Date : 2025-25-03
  Description: Striver DSA Sheet problem-Children Sum Property
*/

/*Summary of Problem Statement:

You are given a binary tree and need to modify node values so that it satisfies the Children Sum Property:

For every node:
node value = (left child value + right child value)
If a child is missing, treat its value as 0
You are only allowed to increase node values (no decreases allowed)
The tree structure must remain unchanged*/

#include <iostream>
using namespace std;

// Definition of Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    void changeTree(Node* root) {
        if (root == NULL) return;

        int child = 0;

        // Step 1: Calculate children sum
        if (root->left) child += root->left->data;
        if (root->right) child += root->right->data;

        // Step 2: Adjust values
        if (child >= root->data) {
            root->data = child;
        } else {
            if (root->left) root->left->data = root->data;
            if (root->right) root->right->data = root->data;
        }

        // Step 3: Recur
        changeTree(root->left);
        changeTree(root->right);

        // Step 4: Fix node after recursion
        int tot = 0;
        if (root->left) tot += root->left->data;
        if (root->right) tot += root->right->data;

        if (root->left || root->right)
            root->data = tot;
    }
};

// Inorder traversal (to check result)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    /*
            50
           /  \
         7     2
        / \   / \
       3   5 1   30
    */

    Node* root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);

    Solution obj;
    obj.changeTree(root);

    cout << "Inorder after enforcing Children Sum Property:\n";
    inorder(root);

    return 0;
}
