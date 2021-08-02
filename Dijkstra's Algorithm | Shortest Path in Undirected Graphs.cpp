// Dijkstra's Algorithm | Shortest Path in Undirected Graphs
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void dijkstra(int V,vector<pair<int,int>> adj[], int source){
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> distTo(V+1,INT_MAX);
        distTo[source]=0;
        pq.push(make_pair(0,source));
        //dist from source
        while(!pq.empty()){
            int dist=pq.top().first;
            int prev=pq.top().second;
            pq.pop();
            vector<pair<int,int>>::iterator it;
            for(it=adj[prev].begin();it<adj[prev].end();it++){
                int next=it->first;
                int next_dist=it->second;
                if(distTo[next]>distTo[prev]+next_dist){
                    distTo[next]=distTo[prev]+next_dist;
                    pq.push(make_pair(distTo[next],next));
                }
            }
        }
        cout << "The distances from source, " << source << ", are : \n";
	    for(int i = 1 ; i<=V ; i++)	cout << distTo[i] << " ";
	    cout << "\n";
    }
};

//Driver code
int main() {
    int tc;
    cin>>tc;
    while(tc--){
        int V,E,source; cin>>V>>E>>source;
        vector<pair<int,int>> adj[V+1];
        for(int i=0;i<E;i++){
            int u,v,wt; cin>>u>>v>>wt;
            adj[u].push_back(make_pair(v,wt));
            adj[v].push_back(make_pair(u,wt));
        }
        Solution obj;
        obj.dijkstra(V,adj,source);
       
        
    }
    return 0;
}
