class Solution {
public:
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), cmp);
        string result;
        for (const int &n : num)
            result += to_string(n);
        int ps = 0;
        while (result[ps] == '0' && ps != result.size() - 1)
            ps++;
        return result.substr(ps);
    }
private:
    static bool cmp(const int &a, const int &b)
    {
        int bit_a = 10, bit_b = 10;
        while (a / bit_a)
        {
            bit_a *= 10;
        }
        while (b / bit_b)
        {
            bit_b *= 10;
        }
        return a * bit_b + b > b * bit_a + a;
    }
};
