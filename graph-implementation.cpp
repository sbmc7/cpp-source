#include<iostream>
#include<cstdio>
#include<list>

using namespace std;

//-----------Graph DS start-------------------------
typedef struct Edge{
		int e;//Ending vertex
		int c;//Cost of Edge
	}Edge;
	
typedef struct Graph{
	int V,E; //No. of Vertices and Edges
	char *vertices; //Array for mapping vertices to lablel
	list<Edge> *adj; //Adjacency List 
	void init(int V);//Initializer
	void addEdge(int s, int e);//Add edge without cost
	void addEdge(int s, int e, int c);//Add edge with cost;
}Graph;

void Graph::init(int V){
	this->V = V;
	adj = new list<Edge>[V];
}

void Graph::addEdge(int s, int e){
	Edge edge;
	edge.e = e;
	edge.c = 0; //Make default cost zero 
	this->adj[s].push_back(edge);
}

void Graph::addEdge(int s, int e, int c){
	Edge edge;
	edge.e = e;
	edge.c = c;
	this->adj[s].push_back(edge);
}
//-----------Graph DS end-------------------------

void displayEdges(Graph &g){
	for(int i=0; i<g.V; ++i){
		list<Edge>::iterator itr;
		for(itr=g.adj[i].begin(); itr!=g.adj[i].end(); ++itr){
			Edge edge = *itr;
			printf("s = %d, e = %d, c = %d\n",i,edge.e,edge.c);
		}
		
	}
}

int main(){
	Graph g;
	g.init(5);
	printf("The graph has been initialized\n");
	printf("V = %d\n",g.V);
	g.addEdge(0,2);
	g.addEdge(0,1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(1,4,9);
	printf("Edges of the graph are:\n");
	displayEdges(g);
	return 0;
}

