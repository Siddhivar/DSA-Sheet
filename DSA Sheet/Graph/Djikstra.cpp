#include <bits/stdc++.h>
using namespace std;

//Djikstra Algo using Priority Queue
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    vector<pair<int,int>>adj[V];
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>result(V,INT_MAX);
    result[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int dist=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(dist>result[node])continue;
        for(auto &n:adj[node]){
            int adjDist=n.second;
            int adjNode=n.first;
            if(dist+adjDist<result[adjNode]){
                result[adjNode]=dist+adjDist;
                pq.push({dist+adjDist, adjNode});
            }
        }
    }
    return result;
}

/*Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
Output: 5
Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. */
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<pair<int,int>>adj[n+1];
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>distance(n+1,INT_MAX);
    vector<int>parent(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    distance[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(d>distance[node])continue;
        for(auto &neigh:adj[node]){
            int adjD=neigh.second;
            int adjN=neigh.first;
            if(d+adjD<distance[adjN]){
                distance[adjN]=d+adjD;
                parent[adjN]=node;
                pq.push({distance[adjN], adjN});
            }
        }
    }
    if(distance[n]==INT_MAX){
        return {-1};
    }
    int node=n;
    vector<int>path;
    while(parent[node]!=node){
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    path.insert(path.begin(),distance[n]);
    return path;
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int,int>>adj[n+1];
    for(auto t:times){
        int u=t[0];
        int v=t[1];
        int w=t[2];
        adj[u].push_back({v,w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>dist(n+1, INT_MAX);
    dist[k]=0;
    pq.push({0,k});
    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(d>dist[node]) continue;
        for(auto& it:adj[node]){
            int adjD=it.second;
            int adjN=it.first;
            if(d+adjD<dist[adjN]){
                dist[adjN]=d+adjD;
                pq.push({dist[adjN], adjN});
            }
        }
    }
    int minTime=INT_MIN;
    for(int i=1;i<dist.size();i++){
        if(dist[i]==INT_MAX) return -1;
        if(dist[i]>minTime){
            minTime=dist[i];
        }
    }
    return minTime;
}
//Djikstra on 2-D 
typedef pair<int,pair<int,int>>p;
bool isSafe(int x,int y, int rows, int cols){
    return (x>=0 && x<rows && y>=0 && y<cols);
}
vector<vector<int>>directions{{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int rows=grid.size();
    int cols=grid[0].size();
    if(rows==0||cols==0||grid[0][0]==1) return -1;
    priority_queue<p,vector<p>, greater<p>>pq;
    vector<vector<int>>result(rows,vector<int>(cols,INT_MAX));
    pq.push({0,{0,0}});
    result[0][0]=0;
    grid[0][0]=1;
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        int d=curr.first;
        int x=curr.second.first;
        int y=curr.second.second;
        if(d>result[x][y])continue;
        for(auto dir:directions){
            int x_=x+dir[0];
            int y_=y+dir[1];
            int dist=1;
            if(isSafe(x_,y_,rows,cols)&&grid[x_][y_]==0 && d+dist<result[x_][y_]){
                result[x_][y_]=d+dist;
                pq.push({d+dist,{x_,y_}});
            }
        }
    }
    if(result[rows-1][cols-1]==INT_MAX) return -1;
    return result[rows-1][cols-1]+1;
}

/*Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.*/
typedef pair<int,pair<int,int>>p;
vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
bool isSafe(int x, int y, int rows, int cols){
    return (x>=0 && x<rows && y>=0 && y<cols);
}
int minimumEffortPath(vector<vector<int>>& heights) {
    int rows=heights.size();
    int cols=heights[0].size();
    priority_queue<p,vector<p>, greater<p>>pq;
    vector<vector<int>>result(rows,vector<int>(cols,INT_MAX));
    pq.push({0,{0,0}});
    result[0][0]=0;
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        int d=curr.first;
        int x=curr.second.first;
        int y=curr.second.second;
        if(d>result[x][y]) continue;
        for(auto dir:directions){
            int x_=x+dir[0];
            int y_=y+dir[1];
            if(isSafe(x_,y_,rows,cols)){
                int absDiff=abs(heights[x_][y_]-heights[x][y]);
                int maxDiff=max(d,absDiff);
                if(maxDiff<result[x_][y_]){
                    result[x_][y_]=maxDiff;
                    pq.push({maxDiff,{x_,y_}});
                }
            }
        }
    }
    return result[rows-1][cols-1];
}
//Bellman Ford can detect negative cycle and works only on directed graph
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int>dist(V,1e8);
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(dist[u]!=1e8 && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        if(dist[u]!=1e8 && dist[u]+w<dist[v]){
            return {-1};
        }
    }
    return dist;
}

//Minimum Spanning Tree --> Prim's Algorithm
typedef pair<int,int>P;
int spanningTree(int V, vector<vector<int>>& edges) {
    vector<pair<int,int>>adj[V];
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<P, vector<P>, greater<P>>pq;
    vector<bool>inMST(V,false);
    pq.push({0,0});
    int sum=0;
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        int wt=curr.first;
        int node=curr.second;
        if(inMST[node]==true) continue;
        inMST[node]=true;
        sum+=wt;
        for(auto &it:adj[node]){
            int neighbor=it.first;
            int weight=it.second;
            if(inMST[neighbor]==false){
                pq.push({weight,neighbor});
            }
        }
    }
    return sum;
}
int main(){
    return 0;
}