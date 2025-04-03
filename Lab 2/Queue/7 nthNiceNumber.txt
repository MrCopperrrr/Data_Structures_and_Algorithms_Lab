// iostream, vector and queue are included
// You can write helper methods

long long nthNiceNumber(int n) {
    queue<long long> q;
    
    q.push(2);
    q.push(5);

    long long current = 0;

    for (int i = 0; i < n; i++) {
        current = q.front();
        q.pop();

        q.push(current * 10 + 2);
        q.push(current * 10 + 5);
    }
    
    return current;
}
