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
    while(std::getline(file, line)){
        if (line[0] == '*' || line[0] == '+') break;
        std::vector<uint64_t> row;
        for (auto segment : std::views::split(line, ' ')){
            if (segment.empty()) continue;
            row.push_back(std::stoull(std::ranges::to<std::string>(segment)));
        }
        numbers.push_back(row);
    }
    
    std::vector<char> operators;
    for (char c : line){
        if (c == '+' || c == '*')
            operators.push_back(c);
    }

    // Transpose (Could read input differently to avoid this step)
    std::vector<std::vector<uint64_t>> transposed(numbers[0].size(), std::vector<uint64_t>(numbers.size()));
    for (size_t i = 0; i < numbers.size(); ++i){
        for (size_t j = 0; j < numbers[i].size(); ++j){
            transposed[j][i] = numbers[i][j];
        }
    }

    uint64_t sum = 0;
    // Depending on the last character of the vector (+ or *), perform the corresponding operation using std::reduce
    for(size_t i = 0; i < transposed.size(); ++i){
        const auto& vec = transposed[i];
        const auto& op = operators[i];
        if (op == '+'){
            sum += std::reduce(vec.begin(), vec.end(), 0ULL, std::plus<>());
        } else if (op == '*'){
            sum += std::reduce(vec.begin(), vec.end(), 1ULL, std::multiplies<>());
        }
    }
    std::cout << sum;
}