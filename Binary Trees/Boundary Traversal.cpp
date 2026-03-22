/* Author : Vansh Kumar
  Date : 2025-22-03
  Description: Leetcode problem- Boundary Traversal
*/
#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert (Level Order)
Node* buildTree(vector<int>& arr) {
    if (arr.size() == 0 || arr[0] == -1) return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        Node* cur = q.front();
        q.pop();

        // left child
        if (arr[i] != -1) {
            cur->left = new Node(arr[i]);
            q.push(cur->left);
        }
        i++;

        // right child
        if (i < arr.size() && arr[i] != -1) {
            cur->right = new Node(arr[i]);
            q.push(cur->right);
        }
        i++;
    }

    return root;
}

// check leaf
bool isLeaf(Node* node) {
    return (!node->left && !node->right);
}

// left boundary
void addLeft(Node* root, vector<int>& res) {
    Node* cur = root->left;
    while (cur) {
        if (!isLeaf(cur)) res.push_back(cur->data);
        if (cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

// leaf Nodes
void addLeaves(Node* root, vector<int>& res) {
    if (!root) return;

    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }

    addLeaves(root->left, res);
    addLeaves(root->right, res);
}

// right Boundary node
void addRight(Node* root, vector<int>& res) {
    Node* cur = root->right;
    vector<int> temp;

    while (cur) {
        if (!isLeaf(cur)) temp.push_back(cur->data);
        if (cur->right) cur = cur->right;
        else cur = cur->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

// Boundary Traversal
vector<int> boundaryTraversal(Node* root) {
    vector<int> res;
    if (!root) return res;

    if (!isLeaf(root)) res.push_back(root->data);

    addLeft(root, res);
    addLeaves(root, res);
    addRight(root, res);

    return res;
}

int main() {
    Node* root = NULL;

    // Building tree 
    vector<int> nodes = {1,2,7,3,-1,-1,8,-1,4,9,-1,5,6,10,11};
    root = buildTree(nodes);

    vector<int> ans = boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int x : ans) cout << x << " ";

    return 0;
}
