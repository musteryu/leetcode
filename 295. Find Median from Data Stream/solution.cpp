class MedianFinder {
private:
    priority_queue<int> l;
    priority_queue<int, vector<int>, std::greater<int>> r;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (l.empty()) {
            l.push(num);
            return;
        }
        if (num < l.top()) {
            l.push(num);
            if (l.size() - r.size() > 1) {
                r.push(l.top());
                l.pop();
            }
        } else {
            r.push(num);
            if (r.size() - l.size() > 1) {
                l.push(r.top());
                r.pop();
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (l.size() > r.size())
            return l.top();
        else if (l.size() < r.size())
            return r.top();
        else 
            return (l.top() + r.top()) / 2.;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();