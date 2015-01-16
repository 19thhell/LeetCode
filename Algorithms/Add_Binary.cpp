class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size())
            swap(a, b);
        if (a.size() == 0)
            return b;
        vector<short> num(b.size() + 1, 0);
        string result;
        int cur = 0;
        auto p = a.rbegin(), q = b.rbegin();
        for (;p != a.rend() && q != b.rend();p++, q++, cur++) {
            num[cur] += (*p - '0') + (*q - '0');
            num[cur + 1] += num[cur] / 2;
            num[cur] %= 2;
        }
        for (;q != b.rend();q++, cur++) {
            num[cur] += (*q - '0');
            num[cur + 1] += num[cur] / 2;
            num[cur] %= 2;
        }
        for (cur = (int)(num.size() - 1) + (num.back() - 1);cur >= 0;cur--)
            result += (char)(num[cur] + '0');
        return result;
    }
};
