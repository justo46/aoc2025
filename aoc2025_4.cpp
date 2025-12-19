#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <cmath>

inline bool check_paper(const std::vector<std::string>& grid, int row, int col) noexcept{
    // Return true if there are 4 or less '@' in the adjacent cells
    const int rows = grid.size();
    const int cols = grid[0].size();
    int count = 0;
    for(int dr = -1; dr <= 1; ++dr){
        for(int dc = -1; dc <= 1; ++dc){
            if(dr == 0 && dc == 0) continue; // Skip the center cell
            const int new_row = row + dr;
            const int new_col = col + dc;
            if(new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols){
                if(grid[new_row][new_col] == '@'){
                    count++;
                }
            }
        }
    }
    return count < 4;
}

int main(){
    std::ifstream file{"aoc2025_4.txt"};
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
                sum += static_cast<unsigned long long>(check_paper(grid, row, col));
            }
        }
    }
    std::cout << sum << std::endl;
}