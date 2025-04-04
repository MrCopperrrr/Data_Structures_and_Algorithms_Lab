#include <iostream>
#include <vector>
#include <list>
using namespace std;

class DirectedGraph 
{ 
	int V;
	vector<list<int>> adj;
public:
	DirectedGraph(int V)
	{
		this->V = V; 
		adj = vector<list<int>>(V, list<int>());
	}
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
	bool isCyclic()
	{
	    vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for(int i = 0; i < V; i++)
            if (isCyclicUtil(i, visited, recStack))
                return true;

        return false;
	    
	}
private:
    bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack)
    {
        if(!visited[v])
        {
            visited[v] = true;
            recStack[v] = true;

            for(auto i = adj[v].begin(); i != adj[v].end(); ++i)
            {
                if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
                    return true;
                else if (recStack[*i])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }
}; 