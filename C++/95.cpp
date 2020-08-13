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
    void helper(int begin, int end, vector<TreeNode*>& output){
        if(begin>end){
            output.push_back(nullptr);
        }
        /*if(begin==end){
            TreeNode* root=new TreeNode(begin);
            output.push_back(root);
            return;
        }
        if(end-begin==1){
            TreeNode* left=new TreeNode(begin);
            TreeNode* root=new TreeNode(end,left,nullptr);
            output.push_back(root);
            TreeNode* right=new TreeNode(end);
            root=new TreeNode(begin,nullptr,right);
            output.push_back(root);
            return;
        }*/
        
        for(int i=begin;i<=end;++i){
            vector<TreeNode*> left;
            vector<TreeNode*> right;
            helper(begin,i-1,left);
            helper(i+1,end,right);
            int ll,rl;
            /*if(left.size()==0 && right.size()==0){
                TreeNode* root=new TreeNode(i);
                output.push_back(root);
            }else if(left.size()==0){
                for(rl=0;rl<right.size();++rl){
                    TreeNode* root=new TreeNode(i,nullptr,right[rl]);
                    output.push_back(root);
                }
            }else if(right.size()==0){
                for(ll=0;ll<left.size();++ll){
                    TreeNode* root=new TreeNode(i,left[ll],nullptr);
                    output.push_back(root);
                }
            }*/
            for(ll=0;ll<left.size();++ll){
                for(rl=0;rl<right.size();++rl){
                    TreeNode* root=new TreeNode(i,left[ll],right[rl]);
                    output.push_back(root);
                }
            }
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> output;
        if(n!=0)
            helper(1,n,output);
        return output;
    }
};