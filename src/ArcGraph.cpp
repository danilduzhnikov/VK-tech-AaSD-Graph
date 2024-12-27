#include "ArcGraph.hpp"

ArcGraph::ArcGraph(int size) : verticesCount(size) {}

ArcGraph::ArcGraph(const IGraph& other) : verticesCount(other.VerticesCount()) {
    for (int i = 0; i < other.VerticesCount(); ++i) {
        std::vector<int> vertices = other.GetNextVertices(i);
        for (int vertex : vertices) {
            AddEdge(i, vertex);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    edges.push_back({from, to});
}

int ArcGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> nextVertices;
    for (const auto& edge : edges) {
        if (edge.first == vertex) {
            nextVertices.push_back(edge.second);
        }
    }
    return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (const auto& edge : edges) {
        if (edge.second == vertex) {
            prevVertices.push_back(edge.first);
        }
    }
    return prevVertices;
}