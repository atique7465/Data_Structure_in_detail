#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int lo;
    int hi;
    int max = 0;
    int lazy = 0;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int lo, int hi) {
        this->lo = lo;
        this->hi = hi;
    }
};

/**
 * Overcomes the array/list based segment tree limitation of range size
 */
class SegmentTree {
public:
    Node *root;

    SegmentTree(int hi) {
        root = new Node(0, hi);
    }

    /**
     * 01. if curr node totally in the range add the value to curr lazy <br>
     * 02. push this curr node <br>
     * 03. if curr node totally in or totally out of the range nothing to do <br>
     * 04. if curr node partially in the range we need to update further <br>
     * 05. as, left & right child updated we need to update current result/max
     *
     * @param curr root node
     */
    void update(int l, int r, int value, Node *curr) {

        if (l <= curr->lo && r >= curr->hi) {
            curr->lazy += value;
        }

        push(curr);

        if ((l <= curr->lo && r >= curr->hi) || l > curr->hi || r < curr->lo) {
            return;
        }

        update(l, r, value, curr->left);
        update(l, r, value, curr->right);

        curr->max = max(curr->left->max, curr->right->max);
    }

    /**
     * 01. make sure lazy value handled properly by calling push() for curr node <br>
     * 02. if curr node totally out of query range return 0 <br>
     * 03. if curr node totally in query range return curr->max <br>
     * 04. if curr node partially in the query range return result from child <br>
     *
     * @param curr root node
     */
    int query(int l, int r, Node *curr) {

        push(curr);

        if (l > curr->hi || r < curr->lo) {
            return 0;
        }

        if (l <= curr->lo && r >= curr->hi) {
            return curr->max;
        }

        return max(query(l, r, curr->left), query(l, r, curr->right));
    }

    /**
     * 01. Add lazy to max and reset the lazy fot this Node <br>
     * 02. propagate the lazy value to the left & right children [create if they don't exists]
     * @param curr Node
     */
    void push(Node *curr) {

        curr->max += curr->lazy;

        if (curr->lo != curr->hi) {
            int mid = (curr->lo + curr->hi) / 2;

            if (curr->left == nullptr) {
                curr->left = new Node(curr->lo, mid);
            }
            if (curr->right == nullptr) {
                curr->right = new Node(mid + 1, curr->hi);
            }

            curr->left->lazy += curr->lazy;
            curr->right->lazy += curr->lazy;
        }

        curr->lazy = 0;
    }
};