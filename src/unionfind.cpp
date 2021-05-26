#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <crtdbg.h>
#include <time.h>
#include "Union.h"
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

void pomiarstop(clock_t begin) {
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << elapsed_secs << std::endl;
}

void pomiarstop(clock_t begin, int time) {
	clock_t end = clock();
	double elapsed_secs_ave = ((double(end - begin) / CLOCKS_PER_SEC) / time) * 1000;
	std::cout << elapsed_secs_ave << std::endl;
}




int main() {
	clock_t t1,t2;
	std::ifstream plik;
	int tmp, tmp2;
	for (int i = 0; i < 3; i++) {
			std::string lista[1] = { "example.txt"};
			plik.open(lista[i]);
			if (plik.good() == true) {
				plik >> tmp;
				float *x = new float[tmp];
				float *y = new float[tmp];
				for (int i = 0; i < tmp; i++) {
					plik >> x[i] >> y[i];
				}
				plik >> tmp2;
				float *z = new float[tmp2];
				int *index1 = new int[tmp2];
				int *index2 = new int[tmp2];
				for (int i = 0; i < tmp2; i++) {
					plik >> index1[i] >> index2[i] >> z[i];
				}

				for (int i = 0; i < 4; i++) {
					Edge e;
					Union Z(tmp);
					Heap Q(tmp2);
					MSTree T(tmp);
					int licz = 0;
					if (i == 0) {
						for (int i = 0; i < tmp; i++)
							Z.makeSet(i);
						for (int i = 0; i < tmp2; i++) {
							e.in1 = index1[i];
							e.in2 = index2[i];
							e.weight = z[i];
							Q.push(e);
						}

						t1 = t2 = clock();
						int k = 0;
						for (int i = 1; i < tmp; i++)
						{
							do
							{
								k++;
								e = Q.front();
								Q.pop();
							} while (Z.findCompr(e.in1) == Z.findCompr(e.in2));
							if (i == tmp - 1) {
								std::cout << "czas kroku petli sortujacej(ms): ";
								pomiarstop(t2, k);
							}
							T.addEdge(e);
							licz++;
							Z.unionRank(e);
						}
						std::cout << "czas algorytmu Kruskala: ";
						pomiarstop(t1);
						
						std::cout << "krawedzie: " << licz << std::endl;
						std::cout << "operacje find: " << Z.getCykles() << std::endl;
						std::cout << "waga: " << T.getWeight() << std::endl;
						std::cout << std::endl;
						//T.print();
					}
					else if (i==1) {
						for (int i = 0; i < tmp; i++)
							Z.makeSet(i);
						for (int i = 0; i < tmp2; i++) {
							e.in1 = index1[i];
							e.in2 = index2[i];
							e.weight = z[i];
							Q.push(e);
						}

						t1 = t2 = clock();
						int k = 0;
						for (int i = 1; i < tmp; i++)
						{
							do
							{
								k++;
								e = Q.front();
								Q.pop();
							} while (Z.find(e.in1) == Z.find(e.in2));
							if (i == tmp - 1) {
								std::cout << "czas kroku petli sortujacej(ms): ";
								pomiarstop(t2, k);
							}
							T.addEdge(e);
							licz++;
							Z.unionNormal(e);
						}
						std::cout << "czas algorytmu Kruskala bez rang i kompresji : ";
						pomiarstop(t1);
						
						std::cout << "krawedzie: " << licz << std::endl;
						std::cout << "operacje find: " << Z.getCykles() << std::endl;
						std::cout << "waga: " << T.getWeight() << std::endl;
						std::cout << std::endl;
						//T.print();
					}
					else if (i == 2) {
						for (int i = 0; i < tmp; i++)
							Z.makeSet(i);
						for (int i = 0; i < tmp2; i++) {
							e.in1 = index1[i];
							e.in2 = index2[i];
							e.weight = z[i];
							Q.push(e);
						}

						t1 = t2 = clock();
						int k = 0;
						for (int i = 1; i < tmp; i++)
						{
							do
							{
								k++;
								e = Q.front();
								Q.pop();
							} while (Z.find(e.in1) == Z.find(e.in2));
							if (i == tmp - 1) {
								std::cout << "czas kroku petli sortujacej(ms): ";
								pomiarstop(t2, k);
							}
							T.addEdge(e);
							licz++;
							Z.unionRank(e);
						}
						std::cout << "czas algorytmu Kruskala bez kompresji  : ";
						pomiarstop(t1);
						
						std::cout << "krawedzie: " << licz << std::endl;
						std::cout << "operacje find: " << Z.getCykles() << std::endl;
						std::cout << "waga: " << T.getWeight() << std::endl;
						std::cout << std::endl;
						//T.print();
					}
					else {
						for (int i = 0; i < tmp; i++)
							Z.makeSet(i);
						for (int i = 0; i < tmp2; i++) {
							e.in1 = index1[i];
							e.in2 = index2[i];
							e.weight = z[i];
							Q.push(e);
						}

						t1 = t2 = clock();
						int k = 0;
						for (int i = 1; i < tmp; i++)
						{
							do
							{
								k++;
								e = Q.front();
								Q.pop();
							} while (Z.findCompr(e.in1) == Z.findCompr(e.in2));
							if (i == tmp - 1) {
								std::cout << "czas kroku petli sortujacej(ms): ";
								pomiarstop(t2, k);
							}
							T.addEdge(e);
							licz++;
							Z.unionNormal(e);
						}
						std::cout << "czas algorytmu Kruskala bez rang : ";
						pomiarstop(t1);
						
						std::cout << "krawedzie: " << licz << std::endl;
						std::cout << "operacje find: " << Z.getCykles() << std::endl;
						std::cout << "waga: " << T.getWeight() << std::endl;
						std::cout << std::endl;
						//T.print();
					}
				}

				delete[] x;
				delete[] y;
				delete[] z;
				delete[] index1;
				delete[] index2;
				plik.close();
				std::cout << std::endl;
			}
			else
				std::cout << "Brak pliku!" << std::endl;
	}
	
	


	system("PAUSE");
	_CrtDumpMemoryLeaks();
	
}
