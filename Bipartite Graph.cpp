//These are graphs that can be coloured using 2 colours , such that no two adjecent nodes have same colour
//1) If it has odd length cycle its not a bipartite graph
//2) If it doesnt have od length cycle its a bipartite graph
//BFS
class Solution {
public:
    bool isBipartiteHelper(int source,vector<vector<int>>& graph,vector<int>& visited){
        queue<int> q;
        q.push(source);
        visited[source]=1;
        while(!q.empty()){
            source=q.front();
            q.pop();
            for(int i=0;i<graph[source].size();i++){
                if(visited[graph[source][i]]==-1){
                    q.push(graph[source][i]);
                    visited[graph[source][i]]=1-visited[source];
                }
                else if(visited[graph[source][i]]==visited[source]){
                    return false;
                }
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(!isBipartiteHelper(i,graph,visited)){
                    for(int it=0;it<visited.size();it++){
                    cout<<visited[it]<<" ";
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
};

//DFS


