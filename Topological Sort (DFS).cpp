//https://www.youtube.com/watch?v=Yh6EFazXipA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=13
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void findtopoSort(int node, vector<int> &vis, stack<int> &st,vector<int> adj[]){
	    //before any operation  visit the node
	    vis[node]=1;
	    for(auto it: adj[node]){
	        if(vis[it]==0){
	          findtopoSort(it,vis,st,adj);  
	        }
	    }
	    //After topologocal movement add element in the stack
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> st;
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            findtopoSort(i,vis,st,adj);
	        }
	    }
	    vector<int> topo;
	    while(!st.empty()){
	        topo.push_back(st.top());
	        st.pop();
	        
	    }
	        return topo;
	}
	
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
