#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <ranges>

int main(){
    std::ifstream file{"aoc2025_2.txt"};

    unsigned long long sum = 0;
    std::string line;
    while(std::getline(file, line)){
        // Find largest two digits with their positions
        unsigned int max = 0;
        int pos = -1;
        for(auto i = 0; i < line.size() - 1; ++i){
            const unsigned int val = line[i] - '0';
            if(val > max){
                max = val;
                pos = i;
            }
        }
        sum = max * 10;
        max = 0;
        for(auto i = pos + 1; i < line.size(); ++i){
            const unsigned int val = line[i] - '0';
            if(val > max)
                max = val;
        }
        sum += max;
    }
    std::cout << sum << std::endl;
}