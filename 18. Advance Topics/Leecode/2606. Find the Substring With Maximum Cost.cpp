/*
Approach: It is a standard problem of Kadane's algorithm

You need to make a new vector vt which is corresponding to the string s. It contains the respective value of corresponding alphabets in string s.
Now, run a for loop and take two variables ans and temp.
After every iteration assign ans with max(ans, temp) and continuously add the element in temp.
If temp becomes negative then reset it to zero as we wants the maximum possible sum.

Complexity:

Time complexity: O(n)
Space complexity: O(n)

*/


class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        // vector v containing values of all the alphabets.
        vector<int> v(26);
        for(int i=0; i<26; i++) v[i]=i+1;

        for(int i=0; i<chars.size(); i++){
            v[chars[i]-'a'] = vals[i];
        }
        
        int n = s.size();
        // vector corresponding to string s
        vector<int> vt(n);
        for(int i=0; i<s.size(); i++){
            vt[i] = v[s[i]-'a'];
        }
        int ans=0, temp=0;
        for(int i=0; i<n; i++){
            temp += vt[i];
            if(temp<0) temp=0;
            // assign maximum value to ans
            ans = max(ans, temp);
        }
        return ans;
    }
};