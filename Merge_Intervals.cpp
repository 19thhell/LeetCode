/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool cmp(const Interval &itv1, const Interval &itv2) {
    return itv1.start < itv2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if (intervals.empty())
            return result;
        sort(intervals.begin(), intervals.end(), cmp);
        result.push_back(intervals[0]);
        for (int i = 1;i < intervals.size();i++) {
            if (result.back().end >= intervals[i].start)
                result.back().end = max(intervals[i].end, result.back().end);
            else result.push_back(intervals[i]);
        }
        return result;
    }
};
