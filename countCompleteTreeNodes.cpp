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
    // int count=0;
    // void helper(TreeNode*root)
    // {
    //     if(root==NULL)
    //         return;
    //     count++;
    //     helper(root->left);
    //     helper(root->right);
    // }
    // int countNodes(TreeNode* root) {
    //     if(root==NULL) return 0;
    //      helper(root);
    //     return count;
    // }
    int countNodes(TreeNode*root)
    {
        if(root==NULL) return 0;
        int lh=findleftHeight(root);
        int rh=findrightHeight(root);
        if(lh==rh)
        {
            return (1<<lh)-1; //2 ki power koi bhi height of comp sub tree
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    
    int findleftHeight(TreeNode*root)
    {
        int h=0;
        while(  root)
        {
            h++;
            root=root->left;
        }
        return h;
    }
    int findrightHeight(TreeNode*root)
    {
        int h=0;
        while(  root)
        {
            h++;
            root=root->right;
        }
        return h;
    }
};