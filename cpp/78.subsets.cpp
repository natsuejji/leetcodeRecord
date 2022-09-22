/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (73.43%)
 * Likes:    12071
 * Dislikes: 173
 * Total Accepted:    1.2M
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {

public:
    
    void dfs(const vector<int>& nums, int n, int s, 
            vector<int> cur, vector<vector<int>>& ans){
        if(n == cur.size()){
            ans.push_back(cur);
            return;
        }
        for(int i=s; i<nums.size(); ++i){
            cur.push_back(nums[i]);
            dfs(nums, n, i+1, cur, ans);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> cur;

        for(int i=0; i<=nums.size(); ++i){
            
            dfs(nums ,i, 0, cur, results);
        }
        return results;
    }
};
// @lc code=end

