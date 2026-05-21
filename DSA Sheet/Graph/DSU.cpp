#include <bits/stdc++.h>
using namespace std;

vector<int>parent;
vector<int>rank;
int find(int x){
    if(x==parent[x]) return x;
    return parent[x]=find(parent[x]);
}
void Union(int x,int y){
    int x_p=find(x);
    int y_p=find(y);
    if(x_p==y_p) return;
    if(rank[x_p]<rank[y_p]) parent[x_p]=y_p;
    else if(rank[x_p]>rank[y_p])parent[y_p]=x_p;
    else{
        parent[x_p]=y_p;
        rank[y_p]++;
    }
}
bool detectCycle(int V, vector<int> adj[]) {
    parent.resize(V);
    rank.resize(V,0);
    for(int i=0;i<V;i++){
        parent[i]=i;
    }
    for(int u=0;u<V;u++){
        for(int &v:adj[u]){
            if(u<v){
                int u_p=find(u);
                int v_p=find(v);
                if(u_p==v_p) return true;
                Union(u,v);
            }
        }
    }
    return false;
}
/*Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.*/
bool equationsPossible(vector<string>& equations) {
    parent.resize(26);
    rank.resize(26,0);
    for(int i=0;i<26;i++){
        parent[i]=i;
    }
    for(auto eq:equations){
        int x=eq[0]-'a';
        int y=eq[3]-'a';
        if(eq[1]=='='){
            Union(x,y);
        }
    }
    for(auto eq:equations){
        int x=eq[0]-'a';
        int y=eq[3]-'a';
        if(eq[1]=='!'){
            if(find(x)==find(y)) return false;
        }
    }
    return true;
}

/*Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
*/
int makeConnected(int n, vector<vector<int>>& connections) {
    int edges=connections.size();
    if(edges+1<n) return -1;
    parent.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    rank.resize(n,0);
    int components=n;
    for(auto c:connections){
        if(find(c[0])==find(c[1])) continue;
        Union(c[0],c[1]);
        components--;
    }
    return components-1;
}

/*Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.

FORMULA-> size*(remaining-size)
*/
long long countPairs(int n, vector<vector<int>>& edges) {
    parent.resize(n);
    rank.resize(n,0);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    for(auto e:edges){
        Union(e[0],e[1]);
    }
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[find(i)]++;
    }
    long long result=0;
    long long remain=n;
    for(auto &it:mp){
        long long size=it.second;
        result+=size*(remain-size);
        remain-=size;
    }
    return result;
}
int main(){
    return 0;
}