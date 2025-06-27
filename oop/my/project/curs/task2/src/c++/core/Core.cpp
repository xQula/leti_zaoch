//
// Created by xqula on 23.06.24.
//

#include "Core.h"
#include "limits"
#include "string"
#include "iostream"
#include "algo/dijkstra.h"

using VecInt = std::vector<int>;
using Vec2DInt = std::vector<VecInt>;

namespace {

    constexpr auto INF = std::numeric_limits<int>::max( );

    auto input_start_end(const std::string &txt, int &var) -> void{
        std::cout << txt;
        std::cin >> var;
        var--;
    }

    auto output_path(const VecInt &path) -> void {
        std::cout << "PATH:" << std::endl;
        std::cout << "-----------------------" << std::endl;
        for (int i : path) {
            std::cout << ++i << " ";
        }
        std::cout << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    auto output_tab(const Vec2DInt &tab) -> void {
        std::cout << "GRAPH:" << std::endl;
        std::cout << "-----------------------" << std::endl;
        for (const auto & i : tab) {
            for (const int j : i) {
                if(j == INF) std::cout << "INF" << " ";
                else std::cout << j << "   ";
            }
            std::cout << std::endl;
        }
        std::cout << "-----------------------" << std::endl;
    }

    auto slice_tab(const Vec2DInt &tab, const int start, const int end) -> Vec2DInt {
        Vec2DInt new_tab;
        for (int i = start; i <= end; i++) {
            new_tab.push_back(tab[i]);
        }
        return new_tab;
    }

    auto check_start_and_finish(const int start, const int end, const Vec2DInt &tab) -> bool {
        if (start < 0 || start >= tab.size() || end < 0 || end >= tab.size()) {
            return false;
        }
        return true;
    }

    auto sum_path(const VecInt &path, const Vec2DInt &tab) -> int {
        auto sum = 0;
        for (int i = 0; i < path.size() - 1; i++) {
            sum += tab[path[i]][path[i+1]];
        }
        return sum;
    }

    auto output_sum_path(const int sum_path) -> void {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Sum path: " << sum_path << std::endl;
        std::cout << "-----------------------" << std::endl;
    }
}

core::Core::Core() {

    m_tab = {
            {INF,   6, INF,   5,   1, INF, INF, INF, INF, INF, INF, INF},
            {INF, INF,   2,   2,   5,   9, INF, INF, INF, INF, INF, INF},
            {INF, INF, INF, INF, INF,   1, INF, INF, INF, INF, INF, INF},
            {INF, INF, INF, INF,   6, INF,   5, INF, INF, INF, INF, INF},
            {INF, INF,   1, INF, INF,   6,   2, INF,   9, INF, INF, INF},
            {INF, INF, INF, INF, INF, INF, INF,   2,   1, INF, INF, INF},
            {INF, INF, INF, INF, INF, INF, INF,   6, INF,   4,   8, INF},
            {INF, INF, INF,   1,   1, INF, INF, INF, INF,   2,  10,   9},
            {INF, INF, INF, INF, INF, INF, INF,   1, INF, INF, INF, INF},
            {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   4, INF},
            {INF ,INF, INF, INF, INF, INF, INF ,INF,   9, INF, INF,   2},
            {INF, INF, INF, INF, INF, INF, INF, INF,   9, INF, INF, INF}
    };
}

auto core::Core::process() -> void {
    auto start  = 0;
    auto end = 0;
    ::output_tab(m_tab);
    ::input_start_end("Enter start: ", start);
    ::input_start_end("Enter end: ", end);
    if(!::check_start_and_finish(start, end, m_tab)) {
        throw std::runtime_error("Invalid start or end");
    }
    m_tab = ::slice_tab(m_tab, start, end);
    ::output_tab(m_tab);
    const auto path = algo::Dijkstra::get_shortest_path(m_tab);
    ::output_path(path);
    const auto sum = ::sum_path(path, m_tab);
    ::output_sum_path(sum);
}


