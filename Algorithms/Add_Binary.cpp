class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size())
            swap(a, b);
        string result(b.size() + 1, '0');
        int forward = 0;
        auto pa = a.rbegin(), pb = b.rbegin(), pr = result.rbegin();
        while (pa != a.rend() && pb != b.rend())
        {
            *pr++ = add(*pa++, *pb++, forward);
        }
        while (pb != b.rend())
        {
            *pr++ = add('0', *pb++, forward);
        }
        if (forward == 1)
            *pr++ = '1';
        if (result[0] == '0')
            result = result.substr(1);
        return result;
    }
private:
    char add(char a, char b, int &forward)
    {
        if (a != b)
        {
            if (forward)
                return '0';
            else return '1';
        }
        else if (a == '0')
        {
            if (forward)
            {
                forward = 0;
                return '1';
            }
            else return '0';
        }
        else
        {
            if (forward)
                return '1';
            else
            {
                forward = 1;
                return '0';
            }
        }
    }
};
