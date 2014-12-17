class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	string result;
    	unordered_map<int, int> record;
    	if (numerator < 0 ^ denominator < 0 && numerator)
    		result += '-';
    	long long numer = abs((long long)numerator), denom = abs((long long)denominator);
    	result += to_string(numer / denom);
    	if (numer % denom == 0)
    		return result;
    	else result += '.';
    	for (long long remainder = numer % denom;remainder > 0;remainder %= denom) {
    		if (record.count(remainder)) {
    			result.insert(record[remainder], "(");
    			result += ')';
    			return result;
    		}
    		record[remainder] = result.size();
    		remainder *= 10;
    		result += to_string(remainder / denom);
    	}
    	return result;
    }
};
