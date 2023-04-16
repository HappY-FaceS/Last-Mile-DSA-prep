/*
# This is a standard Problem of Binary Search and prefix sum

#intution :

If there are j numbers in nums that are smaller than query[i], you need to find query[i] * j - sum(j numbers smaller than query[i]) to find increments required in nums

If there are k numbers in nums that are greater than query[i], you need to find sum(k numbers larger than query[i]) - query[i] * k to find decrements required in nums

Sum of above two values is our answer ans[i]

*/

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<long long> ans, prefix(n + 1);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + (long long) nums[i];

        for (int x : queries) 
        {
            // binary search to find the index  of element >= x
            int i = lower_bound(nums.begin(), nums.end(), x) - nums.begin();

            ans.push_back(1LL * x * (2 * i - n) + prefix[n] - 2 * prefix[i]);

        }
        return ans;
    }
};