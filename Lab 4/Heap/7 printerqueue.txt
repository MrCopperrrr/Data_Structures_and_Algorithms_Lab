#include <queue>
#include <string>
#include <tuple>
#include <functional>
#include <iostream>

using namespace std;

// Define a custom comparator struct
struct Compare {
    bool operator()(const tuple<int, int, string>& a, const tuple<int, int, string>& b) const {
        if (std::get<0>(a) != std::get<0>(b))
            return std::get<0>(a) < std::get<0>(b); // Higher priority first
        return std::get<1>(a) > std::get<1>(b); // Earlier insertion first
    }
};

class PrinterQueue
{
private:
    // Tuple structure: (priority, insertionOrder, fileName)
    priority_queue<
        tuple<int, int, string>, 
        vector<tuple<int, int, string>>, 
        Compare
    > pq;
    int counter; // To keep track of insertion order

public:
    PrinterQueue() : counter(0) {}

    void addNewRequest(int priority, string fileName)
    {
        if(pq.size() < 100){
            pq.emplace(priority, counter++, fileName);
        }
    }

    void print()
    {
        if(pq.empty()){
            cout << "No file to print" << endl;
        }
        else{
            auto top = pq.top();
            pq.pop();
            cout << get<2>(top) << endl;
        }
    }
};
