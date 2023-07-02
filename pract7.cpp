#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <set>
using namespace std;
vector<int> dikshtrasShortestPath(int offices, int edges, vector<vector<int>>& vec, int source)
{
    unordered_map<int, list<pair<int, int>>> adjlist;
    // Create adjacency list
    for (int i = 0; i < edges; i++)
    {
        int a = vec[i][0];
        int b = vec[i][1];
        int c = vec[i][2];
        adjlist[a].push_back(make_pair(b, c));
        adjlist[b].push_back(make_pair(a, c));
    }
    vector<int> dist;
    for (int i = 0; i < offices; i++)
    {
        dist.push_back(INT32_MAX);
    }
    dist[source] = 0;

    set<pair<int, int>> st; // Set to store data in specific order <distance, node>
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        auto top = *(st.begin()); // Get the minimum from the set
        int nodeData = top.second;
        int nodeDistance = top.first;
        st.erase(st.begin());

        for (auto neighbor : adjlist[nodeData])
        {
            if (nodeDistance + neighbor.second < dist[neighbor.first])
            {
                auto record = st.find(make_pair(dist[neighbor.first], neighbor.first));

                if (record != st.end())
                {
                    // Update existing record
                    st.erase(record);
                }

                dist[neighbor.first] = nodeDistance + neighbor.second;
                st.insert(make_pair(dist[neighbor.first], neighbor.first));
            }
        }
    }

    return dist;
}

int main()
{
    vector<vector<int>> input;
    int vertex, edges;

    cout << "Enter the number of offices: ";
    cin >> vertex;

    cout << "Enter the number of connections: ";
    cin >> edges;

    vector<int> ans;

    for (int i = 0; i < edges; i++)
    {
        vector<int> temp;
        int a, b, c;

        cout << "Enter connection " << i + 1 << ": ";
        cin >> a >> b >> c;

        temp.push_back(a);
        temp.push_back(b);
        temp.push_back(c);
        input.push_back(temp);
    }
    ans = dikshtrasShortestPath(vertex, edges, input, 0);
    cout << "Shortest distances from source (0): ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
