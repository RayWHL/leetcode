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
class Solution {
private:
    TreeNode *first;
    TreeNode *last;
    TreeNode *pre;
    void helper(TreeNode *root){
        if(root->left!=nullptr){
            helper(root->left);
        }
        if(pre!=nullptr){
            if(root->val<pre->val){
                if(first==nullptr) first=pre;
                last=root;
            }
        }
        pre=root;
        if(root->right!=nullptr){
            helper(root->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        first=nullptr;
        last=nullptr;
        pre=nullptr;
        if(root!=nullptr){
            helper(root);
            int temp=first->val;
            first->val=last->val;
            last->val=temp;
        }
    }
};