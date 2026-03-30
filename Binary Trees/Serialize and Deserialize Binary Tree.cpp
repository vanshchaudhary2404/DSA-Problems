/* Author : Vansh Kumar
  Date : 2025-30-03
  Description: Leetcode problem-297. Serialize and Deserialize Binary Tree
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s ="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();
            if( currNode == NULL){
                s.append("NULL,");
            }else{
                s.append(to_string(currNode->val)+ ',');
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if( data.size() == 0) return NULL;

        stringstream ss(data);
        string token;
        getline(ss, token ,',');//(string stream , token , delimiter);
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if (!getline(ss, token, ',')) break;
            if( token != "NULL"){
                TreeNode* leftNode = new TreeNode(stoi(token));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            if (!getline(ss, token, ',')) break;
            if( token != "NULL"){
                TreeNode* rightNode = new TreeNode(stoi(token));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
