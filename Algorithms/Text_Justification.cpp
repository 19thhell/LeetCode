class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        if (words.empty())
            return words;
		vector<string> line, result;
		int total = 0;
        string tmp;
		for (int i = 0;i < words.size();i++) {
			if (line.size() == 0) {
				line.push_back(words[i]);
				total = words[i].size() + 1;
			}
			else {
				if (total + words[i].size() > L) {
					if (line.size() == 1) {
						tmp = line[0];
						while (tmp.size() < L)
							tmp += ' ';
						result.push_back(tmp);
						line.clear();
						line.push_back(words[i]);
						total = words[i].size() + 1;
					}
					else {
						vector<string> space(line.size() - 1);
						total -= line.size();
						int cnt = 0;
						while (total < L) {
							space[cnt++ % space.size()] += ' ';
							total++;
						}
						tmp = line[0];
						for (int i = 1;i < line.size();i++) {
							tmp += space[i - 1];
							tmp += line[i];
						}
						result.push_back(tmp);
						line.clear();
						line.push_back(words[i]);
						total = words[i].size() + 1;
					}
				}
				else {
					line.push_back(words[i]);
					total += words[i].size() + 1;
				}
			}
		}
		if (line.size() > 0) {
			string tmp;
			tmp = line[0];
			for (int i = 1;i < line.size();i++) {
				tmp += ' ';
				tmp += line[i];
			}
			while (tmp.size() < L)
				tmp += ' ';
			result.push_back(tmp);
		}
		return result;
    }
};
