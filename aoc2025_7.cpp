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

using Grid = std::vector<std::vector<char>>;

class Coord{
public:
    Coord(int x, int y) : x(x), y(y) {}

    Coord search(const Grid& grid) {
        Coord cur = *this;
        while(!cur.isOutside(grid) == false && cur.get(grid) == '.'){
            cur.y++;
            if (cur.get(grid) == '#')
                return cur;
        }
        return cur;
    }

    char get(const Grid& grid) const {
        return grid[x][y];
    }

    bool isOutside(const Grid& grid) const {
        return x < 0 || y < 0 || y >= static_cast<uint64_t>(grid.size()) || x >= static_cast<uint64_t>(grid[0].size());
    }

    uint64_t x;
    uint64_t y;
};

int main(){
    std::ifstream file{"aoc2025_7.txt"};

    Grid numbers;
    std::string line;
    while(std::getline(file, line)){
        std::vector<char> row;
        for (auto segment : std::views::split(line, ' ')){
            row.push_back(std::ranges::to<std::string>(segment)[0]);
        }
        numbers.push_back(row);
    }
    uint64_t sum = 0;



    std::cout << sum;
}