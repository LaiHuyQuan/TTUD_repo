#include<bits/stdc++.h>
using namespace std;
int n, res = 0;
int Time = -1;

struct Task{
    int tBegin;
    int tEnd;
};

vector<Task> tasks;

void input(){
    cin >> n;
    for(int i = 0; i < n ; i++){
        Task task;
        cin >> task.tBegin >> task.tEnd;
        tasks.push_back(task);
    }
}

bool CompareByEndTime(const Task&a, const Task& b){
    return a.tEnd < b.tEnd;
}

int main(){
    input();
    sort(tasks.begin(), tasks.end(), CompareByEndTime);
    for(int i = 0; i < n; i++){
        if(tasks[i].tBegin > Time){
            res ++; 
            Time = tasks[i].tEnd;
        }
    }
    cout << res;
    return 0;

}