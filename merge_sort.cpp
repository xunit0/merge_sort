#include <iostream>
#include <vector>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char* argv[]) {

    std::vector<int> input;

   for (int i = 1; i < argc; i++) {
       input.push_back(std::stoi(argv[i]));
   }

    while (input.size() > 2) {

    }
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}

std::vector<int> merge(std::vector<int>& v, int left, int mid, int right) {

    if (v.size() == 2) {
        if (v[0] > v[1]) {
            std::swap(v[0], v[1]);
        }
        return v;
    }else if (v.size() == 1) {
         return v;
    }else {
        int mid = v.size()/2;
        std::vector<int> left(v.begin(), v.begin() + mid);
        std::vector<int> right(v.begin() + mid, v.end());



    }


}
