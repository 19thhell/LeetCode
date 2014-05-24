class Solution {
public:
    string getPermutation(int n, int k) {
		static const int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
		if (k > factorial[n])
            return "";
		set<int> s;
		for (int i = 1;i <= 9;i++)
			s.insert(i);
        string result;
        while (n--) {
            int cur = (k - 1) / factorial[n] + 1, cnt = 1;
			set<int>::iterator p = s.begin();
			while(cnt++ < cur)
				p++;
			result += (*p) + '0';
			s.erase(p);
            k = (k + factorial[n] - 1) % factorial[n] + 1;
        }
		return result;
	}
};
