#include <iostream>
#include <string>
#ifndef drzewo_h
#define drzewo_h


struct Node {
	int parent;
	int rank;
};
struct Edge {
	int in1, in2;
	float weight;
};
class Union
{
private:
	int cykle=0;
	Node * Z;
public:
	Union(const int &n);
	~Union();
	const int getCykles();
	void makeSet(const int &v);
	int findCompr(const int &v);
	void unionRank(Edge e);
	int find(const int &v);
	void unionNormal(const Edge &e);
};



class Heap{
private:
	Edge * heap;
	int hpos;
public:
	Heap(const int &n);
	~Heap();
	Edge front();
	void push(const Edge &e);
	void pop();
};

struct Tnode {
	Tnode *next;
	int v;
	float weight;
};

class MSTree
{
private:
	Tnode ** A;                  
	int Alen;                    
	float weight;                  
public:
	const float getWeight();
	MSTree(const int &n);
	~MSTree();
	void addEdge(const Edge &e);
	void print();
};
Union::Union(const int &n)
{
	Z = new Node[n];
}

Union::~Union()
{
	delete[] Z;
}

const int Union::getCykles()
{
	return cykle;
}

void Union::makeSet(const int &v)
{
	Z[v].parent = v;  //ok
	Z[v].rank = 0;
}

int Union::findCompr(const int &v)
{
	cykle++;
	if (Z[v].parent != v) Z[v].parent = findCompr(Z[v].parent);
	return Z[v].parent;  //ok
}

void Union::unionRank(Edge e)
{
	int ru, rv;

	ru = findCompr(e.in1);
	rv = findCompr(e.in2);
	if (Z[ru].rank < Z[rv].rank)
		Z[ru].parent = rv;
	else if (Z[ru].rank >Z[rv].rank)  //ok
		Z[rv].parent = ru;
	else{
		Z[rv].parent = ru;
		Z[ru].rank++;
	}
}

int Union::find(const int &v)
{
	cykle++;
	if (Z[v].parent != v)return find(Z[v].parent);
	return v;
}

void Union::unionNormal(const Edge &e)
{
	int ru, rv;
	ru = find(e.in1);
	rv = find(e.in2);
	Z[ru].parent = rv;
}

Heap::Heap(const int &n)
{
	heap = new Edge[n];            
	hpos = 0;
}

Heap::~Heap()
{
	delete[]heap;
}

Edge Heap::front()
{
	return heap[0];
}

void Heap::push(const Edge &e)
{
	int i, j;
	i = hpos++;                    
	j = (i - 1) / 2;              					
	while (i && (heap[j].weight > e.weight)){
		heap[i] = heap[j];
		i = j;
		j = (i - 1) / 2;
	}
	heap[i] = e;
}

void Heap::pop()
{
	int i, j;
	Edge e;
	if (hpos){
		e = heap[--hpos];
		i = 0;
		j = 1;
		while (j < hpos){
			if ((j + 1 < hpos) && (heap[j + 1].weight < heap[j].weight)) j++;
			if (e.weight <= heap[j].weight) break;
			heap[i] = heap[j];
			i = j;
			j = (j * 2) + 1;
		}
		heap[i] = e;
	}
}
const float MSTree::getWeight()
{
	return weight;
;
}
MSTree::MSTree(const int &n)
{
	int i;

	A = new Tnode *[n];            
	for (i = 0; i < n; i++) A[i] = NULL; 
	Alen = n - 1;                   
	weight = 0;
}

MSTree::~MSTree()
{
	int i;
	Tnode *p, *r = nullptr;

	for (i = 0; i <= Alen; i++){
		p = A[i];
		while (p){
			r = p;                      
			p = p->next;                
			delete r;  
		}
	}
	delete[] A;
}

void MSTree::addEdge(const Edge &e)
{
	Tnode *p;

	weight += e.weight;             
	p = new Tnode;                 
	p->v = e.in2;                   
	p->weight = e.weight;          
	p->next = A[e.in1];
	A[e.in1] = p;

	p = new Tnode;                 
	p->v = e.in1;                   
	p->weight = e.weight;          
	p->next = A[e.in2];             
	A[e.in2] = p;
}

void MSTree::print()
{
	int i;
	Tnode *p;

	std::cout << std::endl;
	for (i = 0; i <= Alen; i++){
		std::cout << "wierzcholek " << i << " - ";
		for (p = A[i]; p; p = p->next) std::cout << p->v << ":" << p->weight << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl << "Minimalne drzewo rozpinające waga = " << weight << std::endl << std::endl;
}


#endif


