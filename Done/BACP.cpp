#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int N, M;
vector<int> credits;
vector<vector<int>> prerequisites;
vector<int> assignment;
int maxLoad;

bool isValid(int course, int period) {
    for (int i = 0; i < N; ++i) {
        if (prerequisites[course][i] == 1 && assignment[i] >= period) {
            return false; // Prerequisite not satisfied
        }
    }
    return true;
}

void backtrack(int course) {
    if (course == N) {
        // Calculate the maximum load for the current assignment
        vector<int> periodLoad(M, 0);
        for (int i = 0; i < N; ++i) {
            periodLoad[assignment[i]] += credits[i];
        }
        maxLoad = min(maxLoad, *max_element(periodLoad.begin(), periodLoad.end()));
        return;
    }

    for (int period = 0; period < M; ++period) {
        if (isValid(course, period)) {
            assignment[course] = period;
            backtrack(course + 1);
        }
    }
}

int main() {
    cin >> N >> M;

    credits.resize(N);
    prerequisites.resize(N, vector<int>(N));
    assignment.resize(N);
    maxLoad = INF;

    for (int i = 0; i < N; ++i) {
        cin >> credits[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> prerequisites[i][j];
        }
    }

    backtrack(0);

    cout << maxLoad << endl;

    return 0;
}
