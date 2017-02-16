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
    int maxPoints(vector<Point>& points) {
        int result = 0;
        for(int i = 0; i < points.size(); i++){
            int overlap = 1;
            map<pair<int, int>, int> lines;
            for(int j = i + 1; j < points.size(); j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    overlap++;
                }
                else{
                    int a = points[i].y - points[j].y;
                    int b = points[i].x - points[j].x;
                    int g = gcd(a, b); // use a gcd(greatest common divisior) as a key, avoid precision problem
                    a /= g;
                    b /= g;
                    lines[make_pair(a, b)]++;
                }
            }
            int localMax = 0;
            for(auto iter : lines){
                localMax = max(localMax, iter.second);
            }
            localMax += overlap;
            result = max(result, localMax);
        }
        return result;
    }
    
private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }
};
