#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <cmath>

bool check_paper(const std::vector<std::string>& grid, int row, int col){
    // Return true if there are 4 or less '@' in the adjacent cells
    const int rows = grid.size();
    const int cols = grid[0].size();
    int count = 0;

}

int main(){
    std::ifstream file{"aoc2025_3.txt"};

    std::vector<std::string>grid;
    std::string line;
    while(std::getline(file, line)){
        grid.push_back(line);
    }
    unsigned long long sum = 0;
    const int rows = grid.size();
    const int cols = grid[0].size();
    for(int row = 0; row < rows; ++row){
        for(int col = 0; col < cols; ++col){
            if(grid[row][col] == '@'){
                sum += check_paper(grid, row, col);
            }
        }
    }
    std::cout << sum << std::endl;
}