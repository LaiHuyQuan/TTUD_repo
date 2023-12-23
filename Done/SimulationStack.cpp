#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    stack<int> myStack;
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
            myStack.push(op.second);
        } else if (op.first == "POP") {
            if (!myStack.empty()) {
                cout << myStack.top() << endl;
                myStack.pop();
            } else {
                cout << "NULL" << endl;
            }
        }
    }

    return 0;
}
