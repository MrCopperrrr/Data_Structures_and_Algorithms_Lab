int Dijkstra(int** graph, int src, int dst) {
	int n = 6; // Assuming the graph has 6 vertices
	vector<int> dist(n, INT_MAX);
	vector<bool> visited(n, false);
	dist[src] = 0;

	for (int i = 0; i < n - 1; ++i) {
		int minDist = INT_MAX, u = -1;
		for (int v = 0; v < n; ++v) {
			if (!visited[v] && dist[v] < minDist) {
				minDist = dist[v];
				u = v;
			}
		}

		if (u == -1) break;
		visited[u] = true;

		for (int v = 0; v < n; ++v) {
			if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}

	return dist[dst];
}
