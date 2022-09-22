/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition
 *
 * https://leetcode.com/problems/array-partition/description/
 *
 * algorithms
 * Easy (76.40%)
 * Likes:    1135
 * Dislikes: 172
 * Total Accepted:    356.2K
 * Total Submissions: 466.3K
 * Testcase Example:  '[1,4,3,2]'
 *
 * Given an integer array nums of 2n integers, group these integers into n
 * pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for
 * all i is maximized. Return the maximized sum.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,4,3,2]
 * Output: 4
 * Explanation: All possible pairings (ignoring the ordering of elements) are:
 * 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
 * 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
 * 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
 * So the maximum possible sum is 4.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [6,2,6,5,1,2]
 * Output: 9
 * Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) +
 * min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * nums.length == 2 * n
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
// @lc code=start
class Solution {

public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        int res = 0;
        for(int i=0;i<size;i+=2){
            res += min(nums[i], nums[i+1]);
        }
        return res;
    }
};
// @lc code=end

