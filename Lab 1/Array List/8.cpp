int longestSublist(vector<string>& words) {
    // STUDENT ANSWER
    if (words.empty()) return 0;  // Nếu danh sách rỗng, trả về 0
    int maxLength = 1;  // Độ dài chuỗi con dài nhất
    int currentLength = 1;  // Độ dài chuỗi con hiện tại
    // Duyệt qua các từ trong danh sách, bắt đầu từ từ thứ hai
    for (int i = 1; i < words.size(); i++) {
        // Nếu ký tự đầu tiên của từ hiện tại giống với từ trước đó
        if (words[i][0] == words[i - 1][0]) {
            currentLength++;  // Tăng độ dài chuỗi con hiện tại
        } else {
            // Cập nhật độ dài chuỗi con dài nhất nếu cần
            maxLength = max(maxLength, currentLength);
            currentLength = 1;  // Bắt đầu chuỗi con mới
        }
    }
    // Kiểm tra lần cuối cùng cho chuỗi con kết thúc ở phần tử cuối cùng
    maxLength = max(maxLength, currentLength);
    return maxLength;
 }