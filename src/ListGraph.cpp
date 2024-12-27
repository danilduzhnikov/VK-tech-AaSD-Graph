#include "ListGraph.hpp"

ListGraph::ListGraph(int size) : adjacencyLists(size) {}

ListGraph::ListGraph(const IGraph& other) : adjacencyLists(other.VerticesCount()) {
    for (int i = 0; i < other.VerticesCount(); ++i) {
        std::vector<int> vertices = other.GetNextVertices(i);
        for (int vertex : vertices) {
            AddEdge(i, vertex);
        }
    }
}

void ListGraph::AddEdge(int from, int to) {
    adjacencyLists[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return adjacencyLists.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    return adjacencyLists[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (int from = 0; from < adjacencyLists.size(); ++from) {
        for (int to : adjacencyLists[from]) {
            if (to == vertex) {
                prevVertices.push_back(from);
            }
        }
    }
    return prevVertices;
}
