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

    map<int, SingleLinkedList<int> *>::iterator it;

	for (it = this->nodes.begin(); it != this->nodes.end(); ++it) {
	    if (!inSet(theSet, it->first)) {
	        topologySort(it->first, theStack, theSet);
	    }
	}

	vector<int> returnVector;

	while(!theStack.isEmpty()) {
	    returnVector.push_back(theStack.peek());
	    theStack.pop();
	}

	return new vector<int>();
}

void DirectedGraph::topologySort(int val, LinkedStack<int> & theStack, set<int> & theSet) {

    theSet.insert(val);

    map<int, SingleLinkedList<int> *>::iterator i;
    for (i = this->nodes.begin(); i != this->nodes.end(); ++i)
        if (!inSet(theSet, i->first)) {
            topologySort(i->first, theStack, theSet);
        }

}
