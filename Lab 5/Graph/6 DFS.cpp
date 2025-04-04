#include <stack>
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
	
	Adjacency *DFS(int v)
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        stack<int> stack;
        Adjacency *result = new Adjacency();

        stack.push(v);

        while (!stack.empty())
        {
            v = stack.top();
            stack.pop();

            if (!visited[v])
            {
                result->push(v);
                visited[v] = true;
            }

            for (int i = adj[v].getSize() - 1; i >= 0; --i)
            {
                int adjVertex = adj[v].getElement(i);
                if (!visited[adjVertex])
                    stack.push(adjVertex);
            }
        }

        delete[] visited;
        return result;
	}
};