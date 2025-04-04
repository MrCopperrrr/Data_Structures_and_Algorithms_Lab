int numberOfFriendGroups(vector<vector<int>>& friends) {
    int n = friends.size();
    vector<bool> visited(n, false);
    int friendGroups = 0;

    function<void(int)> dfs = [&](int node) {
        visited[node] = true;
        for (int neighbor : friends[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++friendGroups;
            dfs(i);
        }
    }

    return friendGroups;
}