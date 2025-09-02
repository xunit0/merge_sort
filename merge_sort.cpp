#include <iostream>
#include <vector>

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

// Build: make
// Run:   ./app <N>
#include <iostream>
#include <vector>
#include <cstdlib>   // rand, srand, atoi
#include <ctime>     // time


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

    // Sort
    std::vector<int> sorted = merge_sort(input);

    // Print sorted numbers (space-separated)
    for (int i = 0; i < (int)sorted.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << sorted[i];
    }
    std::cout << '\n';
    return 0;
}

