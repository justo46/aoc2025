#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <ranges>

bool is_repeating(const std::string& s, size_t div){
    const auto len = s.length();
    const auto len_of_sub = len / div;
    // j: which subnumber (first is fixed for comparison)
    for(auto j = 1; j < div; ++j){
        // l: position in subnumber
        for(auto l = 0; l < len_of_sub; ++l){
            if(s[l] != s[len_of_sub * j + l]) 
                return false;
        }
    }
    return true;
}

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
            const auto len = s.length();

            for(auto div = 2; div <= len; ++div){
                if(len % div != 0) continue;
                if(is_repeating(s, div)){
                    sum += i;
                    break;
                }
            }

        }
    }
    std::cout << sum << std::endl;
}