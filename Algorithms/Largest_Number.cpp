class Solution {
public:
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), cmp);
        string result;
        for (const int &n : num)
            result += to_string(n);
        int first_zero = 0;
        while (result[first_zero] == '0' && first_zero != result.size() - 1)
            first_zero++;
        return result.substr(first_zero);
    }
private:
    static bool cmp(const int &a, const int &b)
    {
        string a_str = to_string(a), b_str = to_string(b);
        return a_str + b_str > b_str + a_str;
    }
};
