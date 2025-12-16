#include <iostream>
#include <fstream>
#include <string>

void rotate(int& cur, std::string line) {
    
}

int main(){
    std::string path = "aoc2025_1.txt";
    std::ifstream file{path};

    std::string line;
    int cur = 50;
    int pw = 0;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            char dir = line[0];
            int steps = std::stoi(line.substr(1));
            if (dir == 'R') {
                pw += (cur + steps) / 100;
                cur = (cur + steps) % 100;
            } else if (dir == 'L') {
                if(cur == 0) pw--;
                cur = cur - steps;
                while(cur < 0){
                    cur = cur + 100;
                    pw++;
                }
                if(cur == 0){
                    pw++;
                }
            }
            std::cout << cur << " " << pw << std::endl;
        }
        file.close();
    }
    std::cout << pw << std::endl;
}