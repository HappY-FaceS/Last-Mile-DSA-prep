// This is a problem of `Min Heap` 

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(int i=0;i<n;i++)
        {
            pq.push(make_pair(nums[i],i)); // store the elements ordered by first element  with their index in nums
            nums[i]=0; // we make use to this nums vector as a marked/unmarked while choosing 
        }

        long long score=0;

        while (!pq.empty()) {

            if(nums[pq.top().second]==0) // means not marked yet
            {
                score+=pq.top().first;
                int idx=pq.top().second;
                nums[min(idx+1,n-1)]=1;
                nums[max(idx-1,0)]=1;
            }
            pq.pop();
        }


         return score;


        
    }
};