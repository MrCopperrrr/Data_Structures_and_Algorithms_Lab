#include <queue>
class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *BFS(int v)
    {
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++)
            visited[i] = false;

        queue<int> queue;
        Adjacency *bfsResult = new Adjacency();

        visited[v] = true;
        queue.push(v);

        while(!queue.empty())
        {
            v = queue.front();
            bfsResult->push(v);
            queue.pop();

            for(int i = 0; i < adj[v].getSize(); ++i)
            {
                int adjVertex = adj[v].getElement(i);
                if(!visited[adjVertex])
                {
                    visited[adjVertex] = true;
                    queue.push(adjVertex);
                }
            }
        }

        delete[] visited;
        return bfsResult;
	}
};