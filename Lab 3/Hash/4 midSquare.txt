

long int midSquare(long int seed) {
    long int squared = seed * seed;
    
    squared /= 100;
    
    long int result = squared % 10000;
    
    return result;
}

long int moduloDivision(long int seed, long int mod) {
    return seed % mod;
}

long int digitExtraction(long int seed, int* extractDigits, int size) {
    vector<int> digits;
    
    while (seed > 0) {
        digits.push_back(seed % 10);
        seed /= 10;
    }
    
    reverse(digits.begin(), digits.end()); 
    
    long int extracted = 0;
    for (int i = 0; i < size; ++i) {
        extracted = extracted * 10 + digits[extractDigits[i]];
    }
    
    return extracted;
}


