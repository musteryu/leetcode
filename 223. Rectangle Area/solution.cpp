#include <algorithm>
using namespace std;

class Solution {
private:
    inline int overlap(int x1, int x2, int x3, int x4) {
        int right = min(x2, x4);
        int left = max(x1, x3);
        if (right <= left) return 0;
        else return right - left;
    }
    inline int area(int x1, int x2, int y1, int y2) {
        return (x2 - x1) * (y2 - y1);
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return area(A, C, B, D) + area(E, G, F, H) - overlap(A, C, E, G) * overlap(B, D, F, H);
    }
};