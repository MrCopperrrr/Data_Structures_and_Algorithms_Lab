// iostream, vector and queue are included
// Hint: use breadth-first-search

int secondsToBeRotten(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    queue<pair<int, int>> q;
    int freshApples = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j});  
            } else if (grid[i][j] == 1) {
                freshApples++; 
            }
        }
    }

    if (freshApples == 0) return 0;
    
    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        bool hasRot = false;
        
        for (int i = 0; i < size; ++i) {
            pair<int, int> cell = q.front();
            q.pop();
            
            int x = cell.first;
            int y = cell.second;

            for (int d = 0; d < 4; ++d) {
                int newX = x + dx[d];
                int newY = y + dy[d];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    freshApples--;  
                    q.push({newX, newY});  
                    hasRot = true;
                }
            }
        }
        
        if (hasRot) {
            time++; 
        }
    }

    return (freshApples == 0) ? time : -1;
}
