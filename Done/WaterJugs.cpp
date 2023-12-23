#include <iostream>
#include <queue>
#include <set>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int minSteps(int a, int b, int c) {
    if (c > max(a, b) || c % gcd(a, b) != 0)
        return -1;

    set<pair<int, int>> visited;
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited.insert({0, 0});

    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == c || y == c)
                return steps;

            // Fill jug 1
            if (visited.insert({a, y}).second)
                q.push({a, y});

            // Fill jug 2
            if (visited.insert({x, b}).second)
                q.push({x, b});

            // Empty jug 1
            if (visited.insert({0, y}).second)
                q.push({0, y});

            // Empty jug 2
            if (visited.insert({x, 0}).second)
                q.push({x, 0});

            // Pour water from jug 1 to jug 2
            int pour1to2 = min(x, b - y);
            if (visited.insert({x - pour1to2, y + pour1to2}).second)
                q.push({x - pour1to2, y + pour1to2});

            // Pour water from jug 2 to jug 1
            int pour2to1 = min(y, a - x);
            if (visited.insert({x + pour2to1, y - pour2to1}).second)
                q.push({x + pour2to1, y - pour2to1});
        }
        steps++;
    }

    return -1;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int result = minSteps(a, b, c);
    cout << result << endl;

    return 0;
}
