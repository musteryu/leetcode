#include <vector>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;

class MinHeap {
public:
    MinHeap(vector<int>& nums, int k): data(new int[k+1]), top(0), capacity(k) {
        for (int num: nums) {
            if (top < k) {
                push(num);
            } else {
                if (data[1] < num) {
                    swap(data[1], data[top]);
                    top--;
                    sink(1);
                    push(num);
                }
            }
        }
    }
    ~MinHeap() {
        delete[] data;
    }

    inline int getMin() {
        return data[1];
    }
private:
    int* data;
    int top;
    int capacity;

    void push(int v) {
        data[++top] = v;
        swim(top);
    }

    void swim(int index) {
        while (index > 1 && data[index] < data[index/2]) {
            swap(data[index], data[index/2]);
            index /= 2;
        }
    }

    void sink(int index) {
        while (2 * index <= top) {
            int j = index * 2;
            if (j < top && data[j] > data[j+1]) j = j + 1;
            if (data[index] <= data[j]) break;
            swap(data[index], data[j]);
            index = j;
        }
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::greater<int>> pq;
        // for (auto& i: nums) {
        //     pq.push(i);
        //     if (pq.size() > k)
        //         pq.pop();
        // }
        // return pq.top();
        MinHeap mh(nums, k);
        return mh.getMin();
    }
};



auto main() -> int {
    vector<int> nums = {1,8,5,6,3,4,0,9,7,2};
    Solution s;
    for (int i = 1; i < 10; i++) {
        cout << s.findKthLargest(nums, i) << endl;
    }
}