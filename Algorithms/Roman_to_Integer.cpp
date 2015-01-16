class Solution {
public:
    int romanToInt(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> roman = setRoman();
        int result = 0, last = 4000;
        for (int i = 0;i < s.size();i++) {
            result += roman[s[i]];
            if (roman[s[i]] > last)
                result -= last * 2;
            last = roman[s[i]];
        }
        return result;
    }

    vector<int> setRoman() {
        vector<int> roman(256);
        roman['i'] = roman['I'] = 1;
        roman['v'] = roman['V'] = 5;
        roman['x'] = roman['X'] = 10;
        roman['l'] = roman['L'] = 50;
        roman['c'] = roman['C'] = 100;
        roman['d'] = roman['D'] = 500;
        roman['m'] = roman['M'] = 1000;
        return roman;
    }
};
