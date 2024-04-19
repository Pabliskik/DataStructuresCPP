#include <iostream>
#include <unordered_map> 
#include <unordered_set>

class Graph {
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> adjList;

public:

    void printGraph() {
            std::unordered_map<std::string, std::unordered_set<std::string>>::iterator kvPair = adjList.begin();
            while (kvPair != adjList.end()) {
                std::cout  << kvPair->first << ": [ ";
                std::unordered_set<std::string>::iterator edge = kvPair->second.begin();
                while (edge != kvPair->second.end()) {
                    std::cout  << edge->data() << " ";
                    edge++;
                }
                std::cout << "]" << std::endl;
                kvPair++;
            }
        }
    
    bool addVertex(std::string vertex) {
        if (adjList.count(vertex) == 0) {
            adjList[vertex];
            return true;
        }

        return false;
    }

    bool addEdge(std::string vertex1, std::string vertex2) {
        if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
            adjList.at(vertex1).insert(vertex2);
            adjList.at(vertex2).insert(vertex1);
            return true;
        }

        return false;
    }

    bool removeEdge(std::string vertex1, std::string vertex2) {
        if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
            adjList.at(vertex1).erase(vertex2);
            adjList.at(vertex2).erase(vertex1);
            return true;
        }

        return false;
    }

    bool removeVertex(std::string vertex) {
        if(adjList.count(vertex) == 0) return false;

        for(auto otherVertex: adjList.at(vertex)) {
            adjList.at(otherVertex).erase(vertex);
        }
        adjList.erase(vertex);
        return true;
    }
};

int main() {

    Graph* myGraph = new Graph();
    myGraph->addVertex("A");
    myGraph->addVertex("B");
    myGraph->addVertex("C");
    myGraph->addVertex("D");
    myGraph->addEdge("A", "B");
    myGraph->addEdge("C", "B");
    myGraph->addEdge("C", "D");
    myGraph->addEdge("D", "B");
    myGraph->removeEdge("C", "B");
    myGraph->removeVertex("D");
    myGraph->printGraph();

    return 0;
}