
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <cmath>
#include <ranges>
#include <algorithm>
#include <numeric>

int main(){
    std::ifstream file{"aoc2025_6.txt"};

    std::vector<std::vector<uint64_t>> numbers;

    std::string line;
    while(std::getline(file, line) && !line.empty()){
        std::vector<uint64_t> row;
        for (auto segment : std::views::split(line, ' ')){
            auto num = std::stoull(std::string(segment.begin(), segment.end()));
            row.push_back(num);
        }
        numbers.push_back(row);
    }
    // Transpose (Could read input differently to avoid this step)
    std::vector<std::vector<uint64_t>> transposed(numbers[0].size(), std::vector<uint64_t>(numbers.size()));
    for (size_t i = 0; i < numbers.size(); ++i){
        for (size_t j = 0; j < numbers[i].size(); ++j){
            transposed[j][i] = numbers[i][j];
        }
    }
    
    int sum = 0;
    // Depending on the last character of the vector (+ or *), perform the corresponding operation using std::reduce
    for(const auto& vec : transposed){
        auto op = static_cast<char>(vec.back());
        if (op == '+'){
            sum += std::reduce(vec.begin(), vec.end() - 1, 0ULL, std::plus<>());
        } else if (op == '*'){
            sum += std::reduce(vec.begin(), vec.end() - 1, 1ULL, std::multiplies<>());
        }
    }
    std::cout << sum;
}