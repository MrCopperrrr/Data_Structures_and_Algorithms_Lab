#include <iostream>
#include <stack>
using namespace std;

bool isValid(int maze[5][5], int visited[5][5], int x, int y) {
    return (x >= 0 && x < 5 && y >= 0 && y < 5 && maze[x][y] == 1 && visited[x][y] == 0);
}

bool canEatFood(int maze[5][5], int fx, int fy) {
    int visited[5][5] = {0};

    stack<Node> s;
    s.push(Node(0, 0));  
    
    visited[0][0] = 1;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    
    while (!s.empty()) {
        Node current = s.top();
        s.pop();
        
        int x = current.x, y = current.y, dir = current.dir;

        if (x == fx && y == fy) {
            return true;
        }

        for (int i = dir; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (isValid(maze, visited, newX, newY)) {
                visited[newX][newY] = 1;
                s.push(Node(newX, newY));
            }
        }
    }

    return false;
}
