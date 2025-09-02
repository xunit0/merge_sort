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

int main(int argc, char* argv[]) {

    std::vector<int> input;

   for (int i = 1; i < argc; i++) {
       input.push_back(std::stoi(argv[i]));
   }


    std::vector<int> sorted = merge_sort(input);

    for (int i = 0; i < sorted.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << sorted[i];
    }
    std::cout << '\n';

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}



