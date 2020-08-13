/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 //递归

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        if(root!=nullptr)
            travel(root,output);
        return output;
    }

    void travel(TreeNode* root, vector<int>& output){
        if(root->left!=nullptr)
            travel(root->left,output);
        output.push_back(root->val);
        if(root->right!=nullptr)
            travel(root->right,output);
    }
};

//迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        stack<TreeNode*> temp;
        //if(root==nullptr) return output;
        while(true){
            if(root!=nullptr){
                temp.push(root);
                root=root->left;
            }else{
                if(temp.empty()){
                    break;
                }else{
                    root=temp.top();
                    temp.pop();
                    output.push_back(root->val);
                    root=root->right;
                }
            }
        }
        return output;
    }
};