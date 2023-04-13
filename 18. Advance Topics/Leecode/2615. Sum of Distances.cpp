// hashmap + Prefix sum
// Time complexity: O(nlogn)
// Space complexity: O(n)
/**
 Intuition -:)
 
We form buckets of sorted indices of same numbers.
So lets say we have array [0,1,1,4,2,3,4,1]

Our bucket map would look like:
0 -> {0}
1 -> {1,2,7}
2- > {4}
3 -> {5}
4 -> {3,6}

Now consider a particular bucket:
it would generally look like: {a0,a1,a2,....an-1} such that a0<a1<a2...<an-1

(Remember that these are indices).

Then the answer for ai would be:
ans[ai] = (ai - a0 + ai - a1 + ai-a2 + .... + ai - ai ) + ( ai - ai + ai+1 - ai + ai+2 - ai +.....+ an-1 - ai)


 
 */

class Solution {
public:
    vector<long long> distance(vector<int>& nums) 
    {
        int n = nums.size();
        vector<long long>ans(n);
        unordered_map<int, vector<int>>mp;
        for (int i = 0; i < n; i++) mp[nums[i]].push_back(i);
        for (auto it : mp)
        {
            int num = it.first;
            vector<int>& indexes = it.second;
            //======================================================
            long long totalSum = 0;
            for (int index : indexes) totalSum += (long long)index;
            
            long long preSum = 0;
            for (int i = 0; i < indexes.size(); i++)
            {
                int index = indexes[i];
                long long postSum = totalSum - preSum - index;
                
                ans[index] += (index * (long long)i);
                ans[index] -= (preSum);
                ans[index] -= (index * (long long)(indexes.size() - i - 1));
                ans[index] += (postSum);
                
                preSum += index;
            }
            //======================================================
        }
        return ans;
        
        
    }
};