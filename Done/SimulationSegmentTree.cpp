#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;

    void build(const vector<int>& array, int node, int start, int end) {
        if (start == end) {
            tree[node] = array[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node;
            int rightChild = 2 * node + 1;

            build(array, leftChild, start, mid);
            build(array, rightChild, mid + 1, end);

            tree[node] = max(tree[leftChild], tree[rightChild]);
        }
    }

    void update(int index, int value, int node, int start, int end) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node;
            int rightChild = 2 * node + 1;

            if (index <= mid) {
                update(index, value, leftChild, start, mid);
            } else {
                update(index, value, rightChild, mid + 1, end);
            }

            tree[node] = max(tree[leftChild], tree[rightChild]);
        }
    }

    int query(int left, int right, int node, int start, int end) {
        if (right < start || left > end) {
            return 0; // Outside the range
        }

        if (left <= start && right >= end) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        int leftChild = 2 * node;
        int rightChild = 2 * node + 1;

        int maxLeft = query(left, right, leftChild, start, mid);
        int maxRight = query(left, right, rightChild, mid + 1, end);

        return max(maxLeft, maxRight);
    }

public:
    SegmentTree(const vector<int>& array) {
        n = array.size();
        tree.resize(4 * n);
        build(array, 1, 0, n - 1);
    }

    void update(int index, int value) {
        update(index, value, 1, 0, n - 1);
    }

    int query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }
};

int main() {
    // Đọc dữ liệu
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    SegmentTree segmentTree(array);

    int m;
    cin >> m;

    // Đọc toàn bộ dữ liệu hành động trước khi thực hiện
    vector<string> actions(m);
    vector<int> indices(m), values(m), lefts(m), rights(m);

    for (int i = 0; i < m; ++i) {
        cin >> actions[i];

        if (actions[i] == "update") {
            cin >> indices[i] >> values[i];
        } else if (actions[i] == "get-max") {
            cin >> lefts[i] >> rights[i];
        }
    }

    // Thực thi các hành động
    for (int i = 0; i < m; ++i) {
        if (actions[i] == "update") {
            segmentTree.update(indices[i] - 1, values[i]);
        } else if (actions[i] == "get-max") {
            int result = segmentTree.query(lefts[i] - 1, rights[i] - 1);
            cout << result << endl;
        }
    }

    return 0;
}
