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

    uint64_t max = 0;
    std::vector<std::vector<std::string>> numbers;
    std::string line;
    while(std::getline(file, line)){
        if (line[0] == '*' || line[0] == '+') break;
        std::vector<std::string> row;
        for (auto segment : std::views::split(line, ' ')){
            if (segment.empty()) continue;
            const auto& str = std::ranges::to<std::string>(segment);
            row.push_back(str);
            if (str.size() > max) max = str.size();
        }
        numbers.push_back(row);
    }
    
    std::vector<char> operators;
    for (char c : line){
        if (c == '+' || c == '*')
            operators.push_back(c);
    }

    // Transpose (Could read input differently to avoid this step)
    std::vector<std::vector<std::string>> transposed(numbers[0].size(), std::vector<std::string>(numbers.size()));
    for (size_t i = 0; i < numbers.size(); ++i){
        for (size_t j = 0; j < numbers[i].size(); ++j){
            transposed[j][i] = numbers[i][j];
            std::reverse(transposed[j][i].begin(), transposed[j][i].end());
            transposed[j][i].resize(max, ' ');
        }
    }

    std::vector<std::vector<uint64_t>> final(transposed.size(), std::vector<uint64_t>(max, 0));
    for (auto i = 0uz; i < transposed.size(); ++i){
        for (auto k = 0uz; k < max; ++k){
            auto tmp = 0ULL;
            for (auto j = 0uz; j < transposed[i].size(); ++j){
                if (transposed[i][j][k] == ' ') continue;
                tmp *= 10;
                tmp += static_cast<uint64_t>(transposed[i][j][k] - '0');
            }
            final[i][k] = tmp;
        }
    }

    uint64_t sum = 0;
    // Depending on the last character of the vector (+ or *), perform the corresponding operation using std::reduce
    for(size_t i = 0; i < final.size(); ++i){
        const auto& vec = final[i];
        const auto& op = operators[i];
        if (op == '+'){
            sum += std::reduce(vec.begin(), vec.end(), 0ULL, std::plus<>());
        } else if (op == '*'){
            sum += std::reduce(vec.begin(), vec.end(), 1ULL, std::multiplies<>());
        }
    }
    std::cout << sum;
}