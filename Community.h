#pragma once
#include <iostream>

#define SIZE 20

class Community {
public:
    Community();
    // добавление вершины
    void addVertex(std::string name);
    // добавление ребра
    void addEdge(std::string name1, std::string name2);
    // удаление вершины
    void delVertex(std::string name);
    // удаление ребра
    void delEdge(std::string name1, std::string name2);
    // поиск минимального "расстояния" между вершинами
    int findMinWayDFS(std::string from, std::string to);
    // алгоритма обхода вглубину
    void depthInner(int current, bool visited[], int weights[], int to, int* min);
    // получение названия вершины (имени) по ее индексу
    std::string getName(int num);
    // вывод матрицы смежности на экран консоли
    void showmatrix();

private:
    // проверка существования ребра между вершинами
    bool edgeExists(std::string name1, std::string name2);
    // проверка существования вершины по имени
    bool vertexExists(std::string name);
    // получение индекса вершины по ее названию
    int getNumberFromName(std::string name);

    int matrix[SIZE][SIZE]; // матрица смежности

    std::string vertexes[SIZE]; // хранилище вершин
    int vertexCount; // количество добавленных вершин
};

