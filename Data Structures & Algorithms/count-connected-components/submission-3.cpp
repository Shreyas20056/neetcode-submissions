class Solution {
public:
    void bfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &ans)
    {
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                count++;
                vis[i]=1;
                bfs(i,adj,vis,ans);
            }
        }
        return count;
    }
};
