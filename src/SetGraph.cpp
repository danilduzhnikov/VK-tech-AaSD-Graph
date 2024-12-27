
#include "SetGraph.hpp"

SetGraph::SetGraph(int size) : adjacencySets(size) {}

SetGraph::SetGraph(const IGraph& other) : adjacencySets(other.VerticesCount()) {
    for (int i = 0; i < other.VerticesCount(); ++i) {
        std::vector<int> vertices = other.GetNextVertices(i);
        for (int vertex : vertices) {
            AddEdge(i, vertex);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    adjacencySets[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return adjacencySets.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    return std::vector<int>(adjacencySets[vertex].begin(), adjacencySets[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (int from = 0; from < adjacencySets.size(); ++from) {
        if (adjacencySets[from].find(vertex) != adjacencySets[from].end()) {
            prevVertices.push_back(from);
        }
    }
    return prevVertices;
}
