/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (62.96%)
 * Likes:    10854
 * Dislikes: 202
 * Total Accepted:    1.5M
 * Total Submissions: 2.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: [[1]]
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
 *
 *
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <stdio.h>
#include <queue>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.

 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> results;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> curLevel;
            auto qsize = q.size();
            for (int i = 0; i < qsize; i++)
            {
                auto cur = q.front();
                q.pop();
                if (cur)
                {
                    curLevel.push_back(cur->val);
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            if (curLevel.size() > 0)
            {
                results.push_back(move(curLevel));
            }
        }
        return results;
    }
};
// @lc code=end
