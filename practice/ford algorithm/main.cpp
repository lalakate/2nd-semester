#include "graph.h"

int main() {
    system("chcp 65001");

    int n, m, source;                       //количество вершин; количество рёбер; номер вершины отсчета расстояний
    std::cout << "Введите количество вершин: ";
    std::cin >> n;
    std::cout << "\nВведите количество рёбер: ";
    std::cin >> m;
    std::vector<Edge> e (m);                //создание графа, реализованного на списке рёбер
    std::cout << "\nВведите информацию о рёбрах(начальная вершина, конечная вершина, вес ребра): \n";
    for (int i = 0; i < m; i++) {
        std::cout <<'\n'<< i + 1 << "-е ребро: ";
        std::cin >> e[i].source >> e[i].destination >> e[i].weight;
    }
    std::cout << "\nВведите номер вершины отсчета расстояний(от 0 до " << n - 1 << "): ";
    std::cin >> source;
    ford_algorithm(e, n, m, source);
    return 0;
}
