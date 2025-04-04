int baseballScore(string ops){
    vector<int> record; 
    for (char op : ops) {
        if (isdigit(op)) {
            record.push_back(op - '0');  
        } else if (op == 'C') {
            record.pop_back(); 
        } else if (op == 'D') {
            record.push_back(2 * record.back());  
        } else if (op == '+') {
            int size = record.size();
            record.push_back(record[size - 1] + record[size - 2]);  
        }
    }

    int totalSum = 0;
    for (int score : record) {
        totalSum += score;  
    }

    return totalSum;
}
