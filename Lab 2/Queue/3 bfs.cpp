void bfs(vector<vector<int>> graph, int start) {
    int n = graph.size();  
    vector<bool> visited(n, false); 
    queue<int> q;  

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front(); 
        q.pop(); 
        cout << current << " ";

        for (int i = 0; i < graph[current].size(); i++) {
            int neighbor = graph[current][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
