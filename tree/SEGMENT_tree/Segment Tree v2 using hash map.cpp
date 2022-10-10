#include <bits/stdc++.h>

using namespace std;

/**
 * [Note: Need to test]
 * Unordered Map for lazy & max <br>
 * 01. Need to track lazy came till curr node. No need to propagate lazy to left or right child <br>
 * 02. Need to track max lazy goes deeper to curr node left & right child <br>
 * 03. Curr node max result will be, maxRes[curr] = lazy[curr] + max(maxRes[left], maxRes[right]); <br>
 */
class SegmentTree {

private:
    unordered_map<int, int> lazy;
    unordered_map<int, int> maxVal;

public:
    SegmentTree() {
    }

    void update(int start, int end, int left, int right, int index) {

        if (start > right || end < left) return;

        if (left >= start && right <= end) {
            lazy[index]++;
            maxVal[index]++;
        } else {
            int mid = (left + right) / 2;
            update(start, end, left, mid, 2 * index);
            update(start, end, mid + 1, right, 2 * index + 1);
            maxVal[index] = lazy[index] + max(maxVal[2 * index], maxVal[2 * index + 1]);
        }
    }

    int query(int start, int end, int left, int right, int index) {

        if (start > right || end < left) return 0;

        if (left >= start && right <= end) {
            return maxVal[index];
        }

        return max(query(start, end, left, (left + right) / 2, 2 * index),
                   query(start, end, (left + right) / 2 + 1, right, 2 * index + 1));
    }
};