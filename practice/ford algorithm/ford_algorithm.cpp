#include "graph.h"

void ford_algorithm(std::vector<Edge> e, int n, int m, int source) {
    std::vector<int> d(n, INF);                  //создание массива расстояний
    d[source] = 0;                                    //расстояние от стартовой вершины = 0
    std::vector<int> p(n, -1);                  //массив предка каждой вершины, т.е. предпоследнюю
                                                     //вершину в кратчайшем пути, ведущем в неё
    int x;
    for (int i = 0; i < n; i++) {                    //нахождение кратчайшего пути
        x = -1;
        for (int j = 0; j < m; j++) {
            if (d[e[j].source] < INF) {
                if (d[e[j].destination] > d[e[j].source] + e[j].weight) {
                    d[e[j].destination] = std::max(-INF, d[e[j].source] + e[j].weight);
                    p[e[j].destination] = e[j].source;
                    x = e[j].destination;
                }
            }
        }
    }


    if (x == -1)                                      //проверка на отрицательный цикл
        std::cout << "\nОтрицательного цикла из вершины " << source << " нет\n";

    else {
        int y = x;
        for (int i = 0; i < n; i++)
            y = p[y];
        std::vector<int> path;
        for (int cur = y;; cur = p[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());
        std::cout << "\nОтрицательный цикл: ";
        for (int i = 0; i < path.size(); i++)
            std::cout << path[i] << ' ';
    }

    printf("\nВершина \t Расстояние от точки отсчёта\n"); // Вывод кратчайших расстояний до всех вершин
    for (int i = 0; i < n; ++i)
        printf("\n%d \t\t %d\n", i, d[i]);
}