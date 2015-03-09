class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.size() < 10)
            return result;
        unordered_map<int, int> dict;
        unordered_map<char, int> char2int {{'C' - 'A', 1}, {'G' - 'A', 2}, {'T' - 'A', 3}};
        for (int i = 0; i < s.size() - 9; i++)
        {
            int window = 0;
            for (int j = i; j < i + 10; j++)
            {
                window <<= 2;
                window |= char2int[s[j] - 'A'];
            }
            dict[window]++;
            if (dict[window] > 1 && dict[window] < 3)
                result.push_back(s.substr(i, 10));
        }
        return result;
    }
};
