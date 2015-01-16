class Solution {
public:
    string multiply(string num1, string num2) {
		string multiple(num1.size() + num2.size(), 0);
        for (char &c : num1)
			c -= '0';
		for (char &c : num2)
			c -= '0';
		for (auto q1 = num1.rbegin();q1 != num1.rend();q1++) {
		    auto p = multiple.begin() + (q1 - num1.rbegin());
			for (auto q2 = num2.rbegin();q2 != num2.rend();q2++) {
			    *p += (*q1) * (*q2);
				*(p + 1) += *p / 10;
				*p %= 10;
				p++;
			}
		}
		auto p = multiple.rbegin();
		while (*p == 0 && (p + 1) != multiple.rend())
			p++;
		multiple = string(p, multiple.rend());
		for (char &c : multiple)
		    c += '0';
		return multiple;
    }
};
