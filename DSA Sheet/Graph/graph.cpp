#include <bits/stdc++.h>
using namespace std;

void dfsGraph(int node,vector<vector<int>>& adj,vector<int>&visited,vector<int>&ans){
    visited[node]=1;
    ans.push_back(node);
    for(int n:adj[node]){
        if(!visited[n]){
            dfsGraph(n,adj,visited,ans); 
        }
    }
}
vector<int> dfs(vector<vector<int>>& adj) {
    int V=adj.size();
    vector<int>visited(V,0);
    vector<int>ans;
    dfsGraph(0,adj,visited, ans);
    return ans;
}

vector<int> bfs(vector<vector<int>> &adj) {
    int V=adj.size();
    queue<int>q;
    vector<int>visited(V,0);
    vector<int>ans;
    q.push(0);
    visited[0]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int n:adj[node]){
            if(!visited[n]){
                visited[n]=1;
                q.push(n);
            }
        }
    }
    return ans;
}

//Detect Undirected graph using DFS
bool dfs(int node,int parent, vector<int>adj[], vector<int>&visited){
    visited[node]=1;
    for(int n:adj[node]){
        if(!visited[n]){
            if(dfs(n,node,adj,visited)) return true;
        }else if(n!=parent){
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges) {
    vector<int>adj[V];
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>visited(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(dfs(i,-1,adj,visited)) return true;
        }
    }
    return false;
}
//Detect Undirected graph using BFS
bool isCycle(int V, vector<vector<int>>& edges) {
    vector<int>adj[V];
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>visited(V,0);
    vector<int>parent(V,-1);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            queue<int>q;
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int n:adj[node]){
                    if(!visited[n]){
                        visited[n]=1;
                        parent[n]=node;
                        q.push(n);
                    }else if( n!=parent[node]) return true;
                }
            }
        }
    }
    return false;
}
//Detect Directed graph using DFS
bool dfs(int node, vector<int>adj[], vector<int>&visited,vector<int>&pathVisited){
    visited[node]=1;
    pathVisited[node]=1;
    for(int n:adj[node]){
        if(!visited[n]){
            if(dfs(n,adj,visited, pathVisited))return true;
        }else if(pathVisited[n]){
            return true;
        }
    }
    pathVisited[node]=0;
    return false;
}
bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<int>adj[V];
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        adj[u].push_back(v);
    }
    vector<int>visited(V,0);
    vector<int>pathVisited(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(dfs(i,adj,visited,pathVisited)) return true;
        }
    }
    return false;
}
//Detect Directed graph using BFS(topological sort)
bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<int>adj[V];
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        adj[u].push_back(v);
    }
    vector<int>result=topoSort(V,adj);
    return result.size()!=V;
}

//Topological sort using DFS
void dfs(int node, vector<int>adj[], vector<int>&visited, stack<int>&s){
    visited[node]=1;
    for(int n:adj[node]){
        if(!visited[n]){
            dfs(n,adj,visited,s);
        }
    }
    s.push(node);
}
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<int>adj[V];
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        adj[u].push_back(v);
    }
    vector<int>visited(V,0);
    stack<int>s;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,adj,visited, s);
        }
    }
    vector<int>result;
    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }
    return result;
}

//Topological sort(BFS)-> Kahn's Algorithm
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<int>adj[V];
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        adj[u].push_back(v);
    }
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto v:adj[i]){
            indegree[v]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>result;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        result.push_back(node);
        for(int n:adj[node]){
            indegree[n]--;
            if(indegree[n]==0){
                q.push(n);
            }
        }
    }
    return result;
}
//Check Bipartite using BFS
bool isBipartite(vector<vector<int>>& graph) {
    int V=graph.size();
    vector<int>color(V,-1);
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            queue<int>q;
            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int n:graph[node]){
                    if(color[n]==-1){
                        color[n]=1-color[node];
                        q.push(n);
                    }else if(color[n]==color[node]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
//Check Bipartite using DFS
bool dfs(int node, vector<vector<int>>& graph, vector<int>&color, int currColor){
    color[node]=currColor;
    for(int n:graph[node]){
        if(color[n]==-1){
            if(!dfs(n,graph,color,1-currColor)) return false;
        }else if(color[n]==color[node]) return false;
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int V=graph.size();
    vector<int>color(V,-1);
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(!dfs(i,graph,color,0)) return false;
        }
    }
    return true;
}
int main(){
    return 0;
}