#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#include<queue>

class Solution 
{
    public:
	//BFS
    bool checkForCycle(int s, int V,vector<int>adj[],vector<bool>& visited){
        queue<pair<int,int>> q;
        q.push({s,-1});
        visited[s]=true;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(!visited[it]){
                    q.push({it,node});
                    visited[it]=true;
                }
                else if(it!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    //DFS https://www.youtube.com/watch?v=Y9NFqI6Pzd4&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=9
    bool checkForCycle(int node,int parent,vector<int>adj[],vector<bool>& visited){
     visited[node]=true;
     for(auto it:adj[node]){
	     if(visited[it]==false){
		     if(checkForCycle(it,node,adj,visited)) return true;
	     }
	     else if(it!=parent){return true;}
     } 		    
    }	
    //Function to detect cycle in an undirected graph.
	
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<bool> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(checkForCycle(i,V,adj,vis)){
	                return true;
	            }
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
