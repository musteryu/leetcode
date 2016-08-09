class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int lo = 0, hi = len - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (citations[mid] < len - mid) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return len - lo;
    }
};
