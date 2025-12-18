#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <cmath>

int main(){
    std::ifstream file{"aoc2025_3.txt"};

    unsigned long long sum = 0;
    std::string line;
    while(std::getline(file, line)){
        // Find largest twelve digits with their positions
        int pos = -1;
        unsigned int max = 0;
        for(int i = 11 ; i >= 0; --i){
            for(auto j = pos + 1; j < line.size() - i; ++j){
                const unsigned int val = line[j] - '0';
                if(val > max){
                    max = val;
                    pos = j;
                }
            }
            std::cout << "Found max " << max << " at pos " << pos << std::endl;
            sum += max * std::pow(10, i);
            max = 0;
        }
    }
    std::cout << sum << std::endl;
}