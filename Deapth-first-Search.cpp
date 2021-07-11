// Weighted Graph in c++
#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[],vector<int>&storeDFS){
    storeDFS.push_back(node);
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,storeDFS);
        }
    }
}
vector<int> dfsOfGraph(int v,vector<int> adj[]){
    vector<int> storeDFS;
    vector<int>vis(v+1,0);
    for(int i=1;i<=v;i++){
        if(!vis[i]){
            dfs(i,vis,adj,storeDFS);
        }
    }
    return storeDFS;
}
int main() {
    int n,m;
    //n is nodes and m is edges
    cin>>n>>m;
    //Incase of weight vector<pait<int,int>> adj[n+1]
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>dfs=dfsOfGraph(n,adj);
    for(auto it:dfs){
        cout<<it<<" ";
    }
    return 0;
}
