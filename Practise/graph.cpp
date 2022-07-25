#include<bits/stdc++.h>

using namespace std;
class load {
public:
	int dest;
	int cost;
	void show() {
		cout<<"dest: "<<dest<<" cost: "<<cost<<endl;
	}
};

class Graph {
private:
	list<load> *Adj;
	int totalNodes;
public:
	Graph(int total) {
		Adj = new list<load>[total+1];
	}
	void add(int src, int dst, int cst) {
		if(sanityCheck(src,dst)) {
			cout<<"Either src or dst"
			return;
		}
		load l1;
		l1.dest = dst;
		l1.cost = cst;
		Adj[src].push_back(l1);
	}
	void getTest(int src) {
		if(Adj[src].empty()) {
			cout<<"no node connected to: "<<src<<endl;
			return;
		}
		Adj[src].front().show();
	}
};

int main() {
	Graph g1(100);
	g1.add(2,3,44);
	g1.getTest(4);
	return 0;
}
