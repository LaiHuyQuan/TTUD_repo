#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    queue<int> myQueue;
    vector<pair<string, int>> operations;
    string operation;
    int value;

    // Read all input into the vector
    while (cin >> operation && operation != "#") {
        if (operation == "PUSH") {
            cin >> value;
            operations.push_back({operation, value});
        } else if (operation == "POP") {
            operations.push_back({operation, 0});
        }
    }

    // Execute operations
    for (const auto& op : operations) {
        if (op.first == "PUSH") {
            myQueue.push(op.second);
        } else if (op.first == "POP") {
            if (!myQueue.empty()) {
                cout << myQueue.front() << endl;
                myQueue.pop();
            } else {
                cout << "NULL" << endl;
            }
        }
    }

    return 0;
}
