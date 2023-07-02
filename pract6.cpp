// Represent a given graph using adjancency matrix / list to perform DFS and using adjacency list to perform DFS and using adjacency list to perform BFS. Use the map of the area around the collegea as the graph. Identify the prominent land marks as nodes and perform DFS and BFS on that.

#include <iostream>
#include<unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <set>
#include <bits/stdc++.h>
using namespace std;
class graph
{
    public:
    unordered_map<int , list<int>>adjlist;
    void addelement(int u , int v , bool direction)
    {
        adjlist[u].push_back(v);
        if(direction == false)
        {
            adjlist[v].push_back(u);
        }
    }
};
void preparedlist(unordered_map<int , list<int>>&adj,vector<pair<int , int>>&edges)
{
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void bfs(unordered_map<int ,list<int>>&adjlist ,unordered_map<int ,bool>&visited , vector<int>&ans , int node)
{
    queue<int>q;
    q.push(node);
    visited[node]=true;

    while(!q.empty())
    {
        int frontNode=q.front();
        q.pop();
        visited[frontNode]=true;
        ans.push_back(frontNode);

        for(auto i:adjlist[frontNode])
        {
            if(visited[i] == false)
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }

}
vector<int>BFS(int vertex,vector<pair<int,int>>edges)
{
    unordered_map<int , bool>visited;
    vector<int>ans;
    unordered_map<int , list<int>>adj;
    preparedlist(adj , edges );
    for(int i=0;i<vertex;i++)
    {
        if(visited[i] == false)
        {
            bfs(adj ,visited ,ans ,i);
        }
    }
    return ans;
}


// Depth first search in graph
void dfs(int node , unordered_map<int , set<int>>&adj ,unordered_map<int , bool>&visited)
{
    if(visited[node]==true)
    {
        return;
    }
    std :: cout<<node<<" ";
    visited[node]=true;
    for(auto i : adj[node])
    {
        dfs(i ,adj ,visited);
    }
}
void DFS(int v , int e , vector<vector<int>>&edges)
{
    // preapred adj list
    unordered_map<int , set<int>>adj;
    unordered_map<int , bool>visited;
    for(int i=0;i<e;i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];

        adj[a].insert(b);
        adj[b].insert(a);
    }

    // check vertex is visited or not
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            dfs(i , adj , visited);
        }
    }

}

int main()
{
    vector<vector<int>>edges;
    vector<int>ans;
    
    std ::cout<<"Enter vertex"<<endl;
    int v;
    std :: cin>>v;
    int e;
    std ::cout<<"Enter number of edges in graph"<<endl;
    std ::cin>>e;
    for(int i=0;i<e;i++)
    {
        vector<int>pair;
        int a,b;
        std ::cin>>a;
        pair.push_back(a);
        std:: cin>>b;
        pair.push_back(b);

        edges.push_back(pair);

    }
    // ans=BFS(v,edges);
    // for(int i=0;i<ans.size();i++)
    // {
    //     cout<<ans[i]<<" ";
    // }

    std ::cout<<endl;
    // ans=DFS(v , e ,edges);
    // for (auto innerVec : ans)
    // {
    //     std ::cout<<innerVec<<" ";
        
    // }
    DFS(v ,e ,edges);
    return 0;
}