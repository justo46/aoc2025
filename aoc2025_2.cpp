#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <ranges>

int main(){
    std::ifstream file{"aoc2025_2.txt"};
    std::string line;
    std::getline(file, line);

    unsigned long long sum = 0;
    for (auto segment : std::views::split(line, ',')) {
        std::string seg(segment.begin(), segment.end());
        auto dash_pos = seg.find('-');

        const auto start = std::stoull(seg.substr(0, dash_pos));
        const auto end = std::stoull(seg.substr(dash_pos + 1));

        for(auto i = start; i <= end; ++i){
            std::string s = std::to_string(i);
            if(s.length() % 2 == 1) continue;
            bool is_repeating = true;
            for(auto j = 0; j < s.length() / 2; ++j){
                if(s[j] != s[s.length() / 2 + j]) is_repeating = false;
            }
            if(is_repeating) sum += i;
        }
    }
    std::cout << sum << std::endl;
}