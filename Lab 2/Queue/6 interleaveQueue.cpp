void interleaveQueue(queue<int>& q) {
    // Kiểm tra nếu hàng đợi có số phần tử lẻ thì không xử lý
    if (q.size() % 2 != 0) {
        return;
    }

    stack<int> s;
    int halfSize = q.size() / 2;

    // Đưa nửa đầu của hàng đợi vào stack
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    // Đưa các phần tử trong stack trở lại hàng đợi
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Đưa nửa sau của hàng đợi lên đầu hàng đợi
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    // Đưa nửa đầu vào stack lần nữa
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    // Xen kẽ phần tử của stack (nửa đầu) và hàng đợi (nửa sau)
    while (!s.empty()) {
        q.push(s.top());  // Đưa phần tử từ stack vào hàng đợi
        s.pop();
        q.push(q.front());  // Đưa phần tử từ hàng đợi vào lại
        q.pop();
    }
}