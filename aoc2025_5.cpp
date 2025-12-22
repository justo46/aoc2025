#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <cmath>
#include <ranges>
#include <algorithm>

class Endpoint{
public:
    Endpoint(uint64_t value, bool is_end) : value(value), is_end(is_end) {}

    constexpr auto operator<=> (const Endpoint& other) const {
        if(value == other.value){
            return is_end <=> other.is_end;
        }
        return value <=> other.value;
    }

    uint64_t value;
    bool is_end;
};

class Intervals{
public:
    constexpr void add(uint64_t start, uint64_t end){
        // Merge intervals if necessary
        endpoints.emplace_back(start, false);
        endpoints.emplace_back(end, true); 
    }

    constexpr void calcIntervals(){
        std::sort(endpoints.begin(), endpoints.end());
        int active = 0;
        uint64_t current_start = 0;

        for(const auto& endpoint : endpoints){
            if(!endpoint.is_end){
                if(active == 0)
                    current_start = endpoint.value;
                active++;
            } else {
                active--;
                if(active == 0)
                    intervals.emplace_back(current_start, endpoint.value);
            }
        }
    }

    constexpr bool contains(uint64_t num) const {
        for (const auto& [start, end] : intervals) {
            if (num >= start && num <= end) {
                return true;
            }
        }
        return false;
    }

    constexpr uint64_t countTotalNumbers() const {
        uint64_t count = 0;

        for (const auto& [start, end] : intervals) {
            count += (end - start + 1);
        }
        return count;
    }

private:
    std::vector<Endpoint> endpoints;
    std::vector<std::pair<uint64_t, uint64_t>> intervals;
};

int main(){
    std::ifstream file{"aoc2025_5.txt"};

    Intervals intervals;

    std::string line;
    while(std::getline(file, line) && !line.empty()){
        for (auto segment : std::views::split(line, ',')) {
            std::string seg(segment.begin(), segment.end());
            auto dash_pos = seg.find('-');

            const auto start = std::stoull(seg.substr(0, dash_pos));
            const auto end = std::stoull(seg.substr(dash_pos + 1));

            if(start > end) throw std::runtime_error("Invalid interval: start greater than end");

            intervals.add(start, end);
        }
    }

    intervals.calcIntervals();

    // Only relevant for part 1
    uint64_t sum = 0;
    while(std::getline(file, line)){
        const auto num = std::stoull(line);
        if(intervals.contains(num)){
            sum++;
        }
    }
    std::cout << "Part 1: " << sum << "\nPart 2: " << intervals.countTotalNumbers() << std::endl;
}