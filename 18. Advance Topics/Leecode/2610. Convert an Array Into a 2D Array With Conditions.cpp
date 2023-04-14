// this is a problem related to hashmap & maximum frequency
// Tc : Time complexity: O(n*max(frequencies))


class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        int rows=0;
        unordered_map<int,int>mp;
        for(auto& it:nums) mp[it]++ , rows=max(rows,mp[it]); // maximum frequency of any element is equals to row in matrix to make every row distinct

        vector<vector<int>> matrix(rows,vector<int>());
        for(auto& it:mp)
        {
            int tempRow=it.second;
            int value=it.first;
            for(int i=0;i<tempRow;i++)
            {
                matrix[i].push_back(value);
            }
        }

        return matrix;
        
    }
};