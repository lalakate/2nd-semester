#ifndef PRACTICE_FORD_GRAPH_H
#define PRACTICE_FORD_GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

const int INF = 1000000000;

struct Edge {                                           //Ребро
    int source;                                         //Начальная вершина
    int destination;                                    //Конечная вершина
    int weight;                                         //Вес ребра
};

void ford_algorithm(std::vector<Edge>, int, int, int);

#endif //PRACTICE_FORD_GRAPH_H
