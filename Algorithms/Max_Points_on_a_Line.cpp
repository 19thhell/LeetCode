/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        unordered_map<double, int> slopes;
        int max_k = 0x7fffffff, min_k = 0x80000000, max_num = 0, same;
        double k;
        for (int i = 0;i < points.size();i++) {
            same = 0;
            slopes.clear();
            slopes[min_k] = 0;
            for (int j = 0;j < points.size();j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    same++;
                    continue;
                }
                if (points[i].x == points[j].x)
                    k = (double)max_k;
                else k = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
                slopes[k]++;
            }
            for (auto p = slopes.begin();p != slopes.end();p++)
                if (p->second + same > max_num)
                    max_num = p->second + same;
        }
        return max_num;
    }
};
