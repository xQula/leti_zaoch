//
// Created by xqula on 23.06.24.
//

#pragma once
#include "vector"
#include "set"
#include "limits"
#include "ranges"
#include "algorithm"

namespace algo {
    using VecInt = std::vector<int>;
    using Vec2DInt = std::vector<VecInt>;
    class Dijkstra {
    public:
        Dijkstra() = delete;
        Dijkstra(const Dijkstra &) = delete;
        Dijkstra operator=(const Dijkstra &) = delete;
        static auto get_shortest_path(const Vec2DInt &graph)
            -> VecInt;
    };

    inline auto Dijkstra::get_shortest_path(const Vec2DInt &graph)
        -> VecInt
    {
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
}


