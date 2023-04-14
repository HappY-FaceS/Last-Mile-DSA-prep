// tc : O(n)
// using two pointer approach


class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ones=0,zeros=0;
        int ans=0;
        int n=s.length();
        int j=0;
        for(int i=0;i<n;i++)
        {
            while(s[j]=='0')
            {
                zeros++;
                j++;
            }
            while(s[j]=='1')
            {
                ones++;
                j++;
            }
            ans=max(ans,min(ones,zeros)*2);
            zeros=0;
            ones=0;
            i=j;

        }
        return ans;
        
    }
};