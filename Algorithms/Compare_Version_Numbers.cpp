class Solution {
public:
    int compareVersion(string version1, string version2) {
        int seg1 = 0, seg2 = 0;
        auto p = version1.begin();
        auto q = version2.begin();
        while (p < version1.end() || q < version2.end()) {
            while (p < version1.end() && *p != '.')
                seg1 = seg1 * 10 + (*p++ - '0');
            while (q < version2.end() && *q != '.')
                seg2 = seg2 * 10 + (*q++ - '0');
            if (seg1 != seg2)
                return (seg1 < seg2) ? -1 : 1;
            seg1 = 0;
            seg2 = 0;
            p++;
            q++;
        }
        return 0;
    }
};
