#include <iostream>
#include <unordered_map>
#include <queue>
#include <typeinfo>
#include "boost/core/demangle.hpp"

int main(int argc, char** argv) {
    std::unordered_map<std::string, int> indegree{{"1", 1}, {"0", 0}, {"3", 3}, {"2", 2}};

    auto comp = [](std::pair<std::string, int> const & p1, std::pair<std::string, int> const & p2) {return p1.second > p2.second;};
    std::cout << boost::core::demangle(typeid(comp).name()) << std::endl;

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(comp)> min_heap(indegree.begin(), indegree.end(), comp);

    while (!min_heap.empty()) {
        std::cout << min_heap.top().first << ": " << min_heap.top().second << std::endl;
        min_heap.pop();
    }
    return 0;
}