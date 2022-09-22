/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include <stdio.h>
#include <math.h>
using namespace std;
class Solution {
private:
    bool ans;
public:
    int isBalanced_recurrent(TreeNode* root, int length){
        if(!root)
            return 0;
        if(!this->ans){
            return 0;
        }

        int leftVal = isBalanced_recurrent(root->left, length+1);
        int rightVal = isBalanced_recurrent(root->right, length+1);
        if(abs(leftVal - rightVal) > 1){
            this->ans = false;
        }
        return 1+max(leftVal, rightVal);

    }
    bool isBalanced(TreeNode* root) {
        ans = true;
        isBalanced_recurrent (root, 1);
        return ans;
    }
};
// @lc code=end

