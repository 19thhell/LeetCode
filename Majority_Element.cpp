class Solution {
public:
    int majorityElement(vector<int> &num) {
        int threshold = num.size() / 2, count = 0, majority;
        for (int elem : num) {
            if (count == 0) {
                majority = elem;
                count++;
            }
            else if (majority == elem) {
                count++;
                if (count > threshold)
                    return majority;
            }
            else count--;
        }
        return majority;
    }
};
