#pragma once
#include "IGraph.hpp"
#include <vector>
#include <utility>

class ArcGraph : public IGraph {
public:
    ArcGraph(int size);
    ArcGraph(const IGraph& other);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::pair<int, int>> edges;
    int verticesCount;
};
