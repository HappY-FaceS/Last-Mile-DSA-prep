// Sieve of Eratosthenes


class Solution {
public:
    bool prime[4000002];
    int N=4000002;
    void inPrime()
    {
        memset(prime, true, sizeof(prime));
        prime[0]=prime[1]=false;
        for(int i=2;i*i<N;i++)
        {
            if(prime[i])
            {
                for(int j=i*i;j<N;j+=i)
                {
                    prime[j]=false;
                }
            }
        }
        return ;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size(),m=nums[0].size();
        int res=0;
        inPrime();
        for (int i = 0; i < n; i++) {        
        // Check left diagonal
        if (prime[nums[i][i]]) 
          res = max(res, nums[i][i]);
        
        // Check right diagonal
        if (prime[nums[i][n-i-1]]) 
          res = max(res, nums[i][n-i-1]);
      }


      return res;

        
    }
};