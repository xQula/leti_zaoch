//
// Created by xqula on 23.06.24.
//

#include "Core.h"
#include "limits"
#include "iostream"
#include "set"
#include "algorithm"

using VecInt = std::vector<int>;
using Vec2DInt = std::vector<VecInt>;

namespace {

    constexpr auto INF = std::numeric_limits<int>::max( );

    auto output_path(const VecInt &path) -> void {
        std::cout << "Short path:" << std::endl;
        std::cout << "**********************" << std::endl;
        for (int i : path) {
            std::cout << ++i << " ";
        }
        std::cout << std::endl;
        std::cout << "**********************" << std::endl;
    }

    auto output_tab(const Vec2DInt &tab) -> void {
        std::cout << "orgraph:" << std::endl;
        std::cout << "**********************" << std::endl;
        for (const auto & i : tab) {
            for (const int j : i) {
                if(j == INF) std::cout << "INF" << " ";
                else std::cout << j << "   ";
            }
            std::cout << std::endl;
        }
        std::cout << "**********************" << std::endl << std::endl;
    }

}

core::Core::Core() {

    m_tab = {
            {INF,   7, INF,   1,   7, INF, INF, INF, INF, INF, INF, INF},
            {INF, INF,   1, INF,   4,   9, INF, INF, INF, INF, INF, INF},
            {INF, INF, INF, INF,   1,   5, INF, INF, INF, INF, INF, INF},
            {INF,   1, INF, INF,   6, INF,   5,   7, INF, INF, INF, INF},
            {INF, INF, INF, INF, INF,   6,   1,   4,   8, INF, INF, INF},
            {INF, INF, INF, INF, INF, INF, INF, INF,   1, INF, INF, INF},
            {INF, INF, INF, INF, INF, INF, INF,   1, INF,   4,   7, INF},
            {INF, INF, INF, INF, INF,   2, INF, INF,   6, INF,   4,   8},
            {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF,   1,   4},
            {INF, INF, INF, INF, INF, INF, INF,   1, INF, INF,   4, INF},
            {INF ,INF, INF, INF, INF, INF, INF ,INF, INF, INF, INF,   2},
            {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}
    };
}

auto core::Core::process() const -> void {
    ::output_tab(m_tab);
    const auto path = getShortPath(m_tab);
    ::output_path(path);
}

auto core::Core::getShortPath(const Vec2DInt &graph) -> VecInt {
    using Vec2DIntSize_t  = Vec2DInt::size_type;
    constexpr double INF = std::numeric_limits<int>::max( );
    const auto n = graph.size();
    int s = 0; // стартовая вершина
    std::vector<double> d(n, INF);
    std::vector<int> p (n);
    d[s] = 0;
    std::set<std::pair<double,int>> q;
    q.insert (std::make_pair(d[s], s));
    while (!q.empty()) {
        const auto v = q.begin()->second;
        q.erase (q.begin());
        for (Vec2DIntSize_t j=0; j<graph[v].size(); ++j) {
            const auto to = j;
            const auto len = graph[v][j];
            if (d[v] + graph[v][j] < d[to]) {
                q.erase (std::make_pair(d[to], static_cast<int>(to)));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert (std::make_pair(d[to], static_cast<int>(to)));
            }
        }
    }
    const auto t = graph.size()-1;
    std::vector<int> path;
    for (auto v=t; v!=s; v=p[v])
        path.push_back(static_cast<int>(v));
    path.push_back (s);
    std::ranges::reverse(path);
    return path;
}


