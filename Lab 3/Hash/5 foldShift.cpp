int foldShift(long long key, int addressSize)
{
    std::string keyStr = std::to_string(key);  
    int hash = 0;

    for (size_t i = 0; i < keyStr.length(); i += addressSize) {
        std::string partStr = keyStr.substr(i, addressSize);  
        int part = std::stoi(partStr);  
        hash += part;  
    }

    int divisor = std::pow(10, addressSize);
    return hash % divisor;
}

int rotation(long long key, int addressSize)
{
    int lastDigit = key % 10;       
    key = (lastDigit * pow(10, static_cast<int>(log10(key)))) + (key / 10);  
    return foldShift(key, addressSize); 
}