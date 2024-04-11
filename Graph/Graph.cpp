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
};

int main() {

    Graph* myGraph = new Graph();
    myGraph->addVertex("A");

    myGraph->printGraph();

    return 0;
}