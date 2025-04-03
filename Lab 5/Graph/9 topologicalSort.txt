class Graph {

    int V;
    Adjacency* adj;

public:
    Graph(int V){
        this->V = V;
        adj = new Adjacency[V];
    }
    void addEdge(int v, int w){
        adj[v].push(w);
    }
    
    void topologicalSort(){
        stack<int> Stack;
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
    
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                topologicalSortUtil(i, visited, Stack);
    
        while (!Stack.empty()) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
        delete[] visited;
    }
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack) {
        visited[v] = true;
    
        for (int i = 0; i < adj[v].getSize(); ++i) {
            int adjVertex = adj[v].getElement(i);
            if (!visited[adjVertex])
                topologicalSortUtil(adjVertex, visited, Stack);
        }
    
        Stack.push(v);
    }
};