class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> tmp(max(a.size(), b.size()) + 1);
        int i = a.size() - 1, j = b.size() - 1, k = tmp.size() - 1, cnt = 0, p = 0;
        while (i >= 0 && j >= 0) {
            tmp[k] += (a[i] - '0') + (b[j] - '0');
			tmp[k - 1] = tmp[k] / 2;
			tmp[k] %= 2;
			i--;j--;k--;
        }
		while (i >= 0) {
			tmp[k] += (a[i] - '0');
			tmp[k - 1] = tmp[k] / 2;
			tmp[k] %= 2;
			i--;k--;
		}
		while (j >= 0) {
			tmp[k] += (b[j] - '0');
			tmp[k - 1] = tmp[k] / 2;
			tmp[k] %= 2;
			j--;k--;
		}
		while (tmp[cnt] == 0 && cnt < tmp.size() - 1)
			cnt++;
		string result(tmp.size() - cnt, '0');
		for (;cnt < tmp.size();cnt++)
			result[p++] = (char)(tmp[cnt] + '0');
		return result;
    }
};
