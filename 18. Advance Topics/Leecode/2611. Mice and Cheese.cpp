/*
This is a problem related to heap ( priority_queue)

Assume take all from the second array.
Check the difference sequence:
A[0] - B[0], A[1] - B[1], ...

Take k largest from the sequence and sum up.

Return the res = sum(B) + sum(k largest A[i]-B[i])
*/

class Solution {
public:
    int miceAndCheese(vector<int>&r1, vector<int>& r2, int k) {
       priority_queue<int>pq;
        long long int ans=0;
        for(int i=0;i<r1.size();i++){
           pq.push(r1[i]-r2[i]);
            ans+=r2[i];
        }
        while(k!=0){
          ans+=pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};