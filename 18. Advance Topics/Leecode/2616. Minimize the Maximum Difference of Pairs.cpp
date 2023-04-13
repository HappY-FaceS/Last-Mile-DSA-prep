// Binary search on the answer
// think of Binary search when there is given (minimum maximum or maximum minimum)


class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end()); // merge sort
        int lAns=0,hAns=1e9+1; // maximumm and minimum possible answers 
        int n=nums.size();
        if(n==1) return 0;
        int minMax=hAns;

        while(lAns<=hAns)
        {
            int cnt=0;
            int midAns=lAns+(hAns-lAns)/2; // mid

            for(int i=0;i<n-1;i++)
            {
                if(nums[i+1]-nums[i]<=midAns){
                    cnt++,i++; // increase pairs count and move to next index for next pair
                }
                
            }

            if(cnt>=p) // if pairs count is greater than P means we need to take less pairs in account so that we minimize our answer
            {
                hAns=midAns-1;
                minMax=midAns;
            }
            else
            {
                lAns=midAns+1;
            }
        }
        return minMax;
    }
};