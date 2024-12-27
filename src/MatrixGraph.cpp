
#include "MatrixGraph.hpp"

MatrixGraph::MatrixGraph(int size) : adjacencyMatrix(size, std::vector<int>(size, 0)) {}

MatrixGraph::MatrixGraph(const IGraph& other)
        : adjacencyMatrix(other.VerticesCount(), std::vector<int>(other.VerticesCount(), 0)) {
    for (int i = 0; i < other.VerticesCount(); ++i) {
        std::vector<int> vertices = other.GetNextVertices(i);
        for (int vertex : vertices) {
            AddEdge(i, vertex);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    adjacencyMatrix[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
    return adjacencyMatrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> nextVertices;
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        if (adjacencyMatrix[vertex][i] == 1) {
            nextVertices.push_back(i);
        }
    }
    return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        if (adjacencyMatrix[i][vertex] == 1) {
            prevVertices.push_back(i);
        }
    }
    return prevVertices;
}
