#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int deadline;
    int profit;
};

bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

int maxTotalProfit(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compareJobs);

    vector<bool> slot(jobs.size(), false);
    int totalProfit = 0;

    for (int i = 0; i < jobs.size(); ++i) {
        for (int j = min(jobs[i].deadline - 1, int(jobs.size()) - 1); j >= 0; --j) {
            if (!slot[j]) {
                slot[j] = true;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    return totalProfit;
}

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);

    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].deadline >> jobs[i].profit;
    }

    int result = maxTotalProfit(jobs);

    cout << result << endl;

    return 0;
}
