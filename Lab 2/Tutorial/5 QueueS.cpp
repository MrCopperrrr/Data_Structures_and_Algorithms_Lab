#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

class QueueS {
private:
    stack<int> s1;    // stack dùng cho enqueue
    stack<int> s2;    // stack dùng cho dequeue
    
    // Hàm helper để chuyển các phần tử từ s1 sang s2
    void transferElements() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    
public:
    void enqueue(int value) {
        s1.push(value);
    }
    
    int dequeue() {
        if (s1.empty() && s2.empty()) {
            throw out_of_range("Empty queue");
        }
        
        transferElements();
        int frontValue = s2.top();
        s2.pop();
        return frontValue;
    }
    
    int front() {
        if (s1.empty() && s2.empty()) {
            throw out_of_range("Empty queue");
        }
        
        transferElements();
        return s2.top();
    }
    
    int rear() {
        if (s1.empty() && s2.empty()) {
            throw out_of_range("Empty queue");
        }
        
        // Nếu s1 không rỗng, phần tử cuối là top của s1
        if (!s1.empty()) {
            return s1.top();
        }
        
        // Nếu s1 rỗng, phần tử cuối là bottom của s2
        // Cần chuyển tất cả từ s2 sang s1 và ngược lại
        stack<int> temp;
        while (!s2.empty()) {
            temp.push(s2.top());
            s2.pop();
        }
        int rearValue = temp.top();
        
        // Khôi phục lại s2
        while (!temp.empty()) {
            s2.push(temp.top());
            temp.pop();
        }
        
        return rearValue;
    }
    
    string toString() {
        string result = "FRONT|";
        
        // Tạo bản sao của cả hai stack
        stack<int> temp1 = s1;
        stack<int> temp2 = s2;
        
        // In các phần tử từ s2 trước (phần đầu của queue)
        vector<int> elements;
        while (!temp2.empty()) {
            elements.push_back(temp2.top());
            temp2.pop();
        }
        
        // Đảo ngược các phần tử từ s1 và thêm vào
        vector<int> s1Elements;
        while (!temp1.empty()) {
            s1Elements.push_back(temp1.top());
            temp1.pop();
        }
        for (int i = s1Elements.size() - 1; i >= 0; i--) {
            elements.push_back(s1Elements[i]);
        }
        
        // Tạo chuỗi kết quả
        for (size_t i = 0; i < elements.size(); i++) {
            result += " " + to_string(elements[i]);
        }
        
        result += "|REAR";
        return result;
    }
};