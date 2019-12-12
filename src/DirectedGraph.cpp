#include "DirectedGraph.h"
#include <iostream>

DirectedGraph::DirectedGraph(Edge *edges, int size) {
    for (int i = 0; i < size; i++) {
        int src = edges[i].src, dest = edges[i].dest;
        if (nodes.count(src) == 0) {
            nodes[src] = new SingleLinkedList<int>();
        }
        nodes[src]->add(dest);
        if (nodes.count(dest) == 0) {
            nodes[dest] = new SingleLinkedList<int>();
        }
    }
}

DirectedGraph::~DirectedGraph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        delete (*it).second;
    }
}

void DirectedGraph::printGraph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        printf("node(%d) has edges: ", (*it).first);
        for (auto itl = (*it).second->begin(); itl != (*it).second->end(); itl++) {
            printf("%d ", (*itl));
        }
        printf("\n");
    }
}

vector<int> *DirectedGraph::topologySort() {
	// homework
	// the return here is a placeholder. replace with your own code

	LinkedStack<int> theStack;

	set<int> theSet;


	for (int i = 0; i < this->nodes.size(); i++) {
	    auto pos = theSet.find(i);
	    if (*pos > theSet.size()) {
	        topologySort(i, theStack, theSet);
	    }
	}

	vector<int> returnVector;

	set<int>::iterator it;
	for (it = theSet.begin(); it != theSet.end(); it++) {
	    returnVector.push_back(*it);
	}

	return new vector<int>();
}

void topologySort(int val, LinkedStack<int> &, set<int> &) {
    
}
