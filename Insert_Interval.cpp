/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> result;
        if (intervals.empty()) {
            result.push_back(newInterval);
            return result;
        }
        for (int i = 0;i < intervals.size();i++) {
			if (newInterval.end < intervals[i].start) {
				result.push_back(newInterval);
				for (int j = i;j < intervals.size();j++)
					result.push_back(intervals[j]);
				return result;
			}
			if (newInterval.start <= intervals[i].end) {
				newInterval.start = min(intervals[i].start, newInterval.start);
				newInterval.end = max(intervals[i].end, newInterval.end);
			}
			else result.push_back(intervals[i]);
        }
		result.push_back(newInterval);
        return result;
    }
};
