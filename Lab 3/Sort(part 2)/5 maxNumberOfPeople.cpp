int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
    sort(rooms.begin(), rooms.end());
    sort(people.begin(), people.end());
    int i = 0, j = 0; 
    int count = 0; 

    while (i < people.size() && j < rooms.size()) {
        if (rooms[j] >= people[i] - k && rooms[j] <= people[i] + k) {
            count++;
            i++; 
            j++; 
        } else if (rooms[j] < people[i] - k) {
            j++;
        } else {
            i++;
        }
    }

    return count;
}