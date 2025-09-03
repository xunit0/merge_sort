#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

void print_current_time_ms() {
    using namespace std::chrono;

    // Get current time point
    auto now = system_clock::now();

    // Break into seconds and milliseconds
    auto now_ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;
    std::time_t now_time = system_clock::to_time_t(now);

    // Convert to local time
    std::tm* local_tm = std::localtime(&now_time);

    // Print as HH:MM:SS.mmm
    std::cout << "[TIME] "
              << std::put_time(local_tm, "%H:%M:%S") << "."
              << std::setfill('0') << std::setw(3) << now_ms.count()
              << "\n";
}



std::vector<int> merge(std::vector<int> left, std::vector<int> right) {
    std::vector<int> output;

    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {output.push_back(left[i]); ++i; }
        else {output.push_back(right[j]); ++j; }
    }


    while (j < right.size()) {
        output.push_back(right[j]);
        ++j;
    }
    while (i < left.size()) {output.push_back(left[i]); ++i;}

    return output;

}
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
std::vector<int> merge_sort(std::vector<int>& v) {

    if (v.size() == 1) {
        return v;
    }else {
        int mid = v.size()/2;
        std::vector<int> left(v.begin(), v.begin() + mid);
        std::vector<int> right(v.begin() + mid, v.end());
        left = merge_sort(left);
        right = merge_sort(right);
        return merge(left, right);



    }


}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <N>\n";
        return 1;
    }

    int N = std::atoi(argv[1]);
    if (N <= 0) {
        std::cerr << "N must be a positive integer.\n";
        return 1;
    }

    // Generate random data
    std::srand((unsigned)std::time(nullptr));
    std::vector<int> input;
    input.reserve(N);
    for (int i = 0; i < N; ++i) {
        input.push_back(std::rand() % 1000); // 0..99,999
    }

    print_current_time_ms();
    // Sort
    std::vector<int> sorted = merge_sort(input);

    print_current_time_ms();

    // Print sorted numbers (space-separated)
    for (int i = 0; i < (int)sorted.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << sorted[i];
    }
    std::cout << '\n';
    return 0;
}

