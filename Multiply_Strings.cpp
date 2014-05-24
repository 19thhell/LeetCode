class Solution {
public:
    string multiply(string num1, string num2) {
		int n1 = num1.size(), n2 = num2.size(), pos = 0;
		string multiple(n1 + n2, 0);
        for (int i = 0;i < n1;i++)
			num1[i] -= '0';
		for (int i = 0;i < n2;i++)
			num2[i] -= '0';
		for (int i = n1 - 1;i >= 0;i--) {
			for (int j = n2 - 1;j >= 0;j--) {
				multiple[i + j + 1] += num1[i] * num2[j];
				multiple[i + j] += multiple[i + j + 1] / 10;
				multiple[i + j + 1] %= 10;
			}
		}
		while (multiple[pos] == 0 && pos < multiple.size() - 1)
			pos++;
		for (int i = pos;i < multiple.size();i++)
			multiple[i] += '0';
		multiple = multiple.substr(pos);
		return multiple;
    }
};
