/*

standard application of BFS:

Assume a node is root and apply bfs search,
where we recode the:

dist[v] is the distance from root u=q.front() to node v

If two points not met up yet (means not visited dist[i]=-1), it means they are father-son
so we update it's distance like node 3 to node 6 or 3 to 4

If two points met up and they are not father-son relation,
they met in a cycle. like node 6 to 5 as 5 distance from root 3 is already stored in dist ( along node 4) 

The distance of circly is smaller or equal than dis[u] + dis[v] + 1. ( left + right +1)



*/

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            vector<int> dist(n, -1);
            queue<int> q;
            dist[i] = 0;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    } else if (dist[v] >= dist[u]) {
                        ans = min(ans, dist[v] + dist[u] + 1);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
