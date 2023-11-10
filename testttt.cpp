#include <iostream>
#include <vector>
#include <algorithm>

// Định nghĩa cấu trúc để lưu thông tin về mỗi phần tử
struct Task {
    int start_time;
    int end_time;
};

// Hàm so sánh để sắp xếp theo thời gian bắt đầu
bool compareByStartTime(const Task& a, const Task& b) {
    return a.start_time < b.start_time;
}

int main() {
    int num_tasks;
    std::cout << "Nhập số lượng công việc: ";
    std::cin >> num_tasks;

    std::vector<Task> tasks;
    for (int i = 0; i < num_tasks; i++) {
        Task task;
        std::cout << "Nhập thời gian bắt đầu cho công việc " << i + 1 << ": ";
        std::cin >> task.start_time;
        std::cout << "Nhập thời gian kết thúc cho công việc " << i + 1 << ": ";
        std::cin >> task.end_time;
        tasks.push_back(task);
    }

    // Sắp xếp mảng theo thời gian bắt đầu tăng dần
    std::sort(tasks.begin(), tasks.end(), compareByStartTime);

    // In ra mảng sau khi sắp xếp
    std::cout << "Danh sách công việc sau khi sắp xếp:" << std::endl;
    for (const Task& task : tasks) {
        std::cout << "Start Time: " << task.start_time << ", End Time: " << task.end_time << std::endl;
    }

    return 0;
}
