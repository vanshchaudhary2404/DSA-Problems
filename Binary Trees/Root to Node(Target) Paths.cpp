/* Author : Vansh Kumar
  Date : 2025-23-03
  Description: Root to Node(Target) Paths
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to find path
bool findPath(Node* root, vector<int>& path, int target) {

    if (root == NULL)
        return false;

    // Add current node
    path.push_back(root->data);

    // If target found
    if (root->data == target)
        return true;

    // Check left or right
    if (findPath(root->left, path, target) ||
        findPath(root->right, path, target))
        return true;

    // Backtrack
    path.pop_back();
    return false;
}

int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> path;
    int target = 5;

    if (findPath(root, path, target)) {
        cout << "Path: ";
        for (int x : path) cout << x << " ";
    } else {
        cout << "Target not found";
    }

    return 0;
}
