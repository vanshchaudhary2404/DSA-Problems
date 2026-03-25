/* Author : Vansh Kumar
  Date : 2025-25-03
  Description: Leetcode problem-863. All Nodes Distance K in Binary Tree
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*void markParent(TreeNode* root , unordered_map<TreeNode*,TreeNode*>& parent_map){
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode* curr = queue.front();
            queue.pop();
            if(curr->left){
                parent_map[curr->left] = curr;
                queue.push(curr->left);
            }
            if(curr->right){
                parent_map[curr->right] = curr;
                queue.push(curr->right);
            }
        }
    }

    TreeNode* findNode(TreeNode* root, int targetVal) {
        if (!root) return NULL;

        if (root->val == targetVal)
            return root;

        TreeNode* left = findNode(root->left, targetVal);
        if (left) return left;

        return findNode(root->right, targetVal);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

    // 🔥 SAFETY: ensure correct target reference
        target = findNode(root, target->val);

        unordered_map<TreeNode*, TreeNode*> parent_map;
        markParent(root, parent_map);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited.insert(target);

        int curr_level = 0;

        while(!q.empty()) {

            int size = q.size();

            if(curr_level == k) break;

            for(int i = 0; i < size; i++) {

                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !visited.count(curr->left)) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }

                if(curr->right && !visited.count(curr->right)) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }

                if(parent_map.count(curr) && !visited.count(parent_map[curr])) {
                    q.push(parent_map[curr]);
                    visited.insert(parent_map[curr]);
                }
            }

            curr_level++;
        }

        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }*/
    


    //Striver approach but not pass all test cases
    void mark_parents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent, TreeNode* target ){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        mark_parents(root, parent, target);
        // Since we are directly given the target node our work is easier 
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        int curr_level = 0;
        q.push(target);
        visited[target] = true;
        while(!q.empty()){
            if(curr_level++ == k){
                break;
            }
            int s = q.size();
            for(int i = 0 ;i<s; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* fr = q.front();
            q.pop();
            ans.push_back(fr->val);
        }
        return ans;
    }
};
