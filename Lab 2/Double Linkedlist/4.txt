DataLog::DataLog() {
    logList.push_back(0);
    currentState = logList.begin();
}

DataLog::DataLog(const int &data) {
    logList.push_back(data);
    currentState = logList.begin();
}

void DataLog::addCurrentState(int number) {
    *currentState += number;
}

void DataLog::subtractCurrentState(int number) {
    *currentState -= number;
}

void DataLog::save() {
    auto next = currentState;
    ++next;
    if (next != logList.end()) {
        logList.erase(next, logList.end());
    }

    logList.push_back(*currentState);
    currentState = --logList.end();
}

void DataLog::undo() {
    if (currentState != logList.begin()) {
        --currentState;
    }
}

void DataLog::redo() {
    auto next = currentState;
    ++next;
    if (next != logList.end()) {
        currentState = next;
    }
}