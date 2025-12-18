#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <cmath>

bool check_paper(const std::vector<std::string>& grid, int row, int col){
    // Return true if there are 4 or less '@' in the adjacent cells
}

int main(){
    std::ifstream file{"aoc2025_3.txt"};

    unsigned long long sum = 0;
    std::vector<std::string>grid;
    std::string line;
    while(std::getline(file, line)){
        grid.push_back(line);
    }

    std::cout << sum << std::endl;
}