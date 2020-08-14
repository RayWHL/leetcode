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
public:
    bool helper(TreeNode* root, long long min, long long max){
        if(root==nullptr) return true;
        bool flag=true;
        flag=flag && (root->val > min) && (root->val < max);
        if(root->left!=nullptr)
            flag=(root->val > root->left->val)&&flag;
        if(root->right!=nullptr)
            flag=(root->val < root->right->val) && flag;
        
        return flag && helper(root->left,min,root->val) && helper(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN , LONG_MAX);
    }
};

// 判定二叉搜索树
// 除了判断根与左右的大小，还要判断根是否在指定范围内（比如左子树中的右子树大于次根，不一定小于总根）

// 0xffffffffffffffff = -1 淦！！竟然忘了


//solution2 中序遍历，看是否有序
//实现见GO方式