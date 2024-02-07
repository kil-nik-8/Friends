#include "Community.h"

#define VERYBIGINT 1000000000

Community::Community() {
    for (int i = 0; i < SIZE; i++)
    {
        vertexes[i] = "";
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    }
    vertexCount = 0;
}
// добавление вершины
void Community::addVertex(std::string name)
{
    vertexes[vertexCount] = name;
    vertexCount++;
}
// добавление ребра
void Community::addEdge(std::string name1, std::string name2)
{
    int v1 = getNumberFromName(name1);
    int v2 = getNumberFromName(name2);
    if (v1 == -1 || v2 == -1)
    {
        std::cout << "Bad attempt to add Edge." << std:: endl;
        return;
    }

    matrix[v1][v2] = 1;
    matrix[v2][v1] = 1;
}

int Community::getNumberFromName(std::string name)
{
    for (int i = 0; i < vertexCount; i++)
    {
        if (vertexes[i] == name)
            return i;
    }
    return -1;
}


// проверка существования ребра
bool Community::edgeExists(std::string name1, std::string name2)
{
    int v1 = getNumberFromName(name1);
    int v2 = getNumberFromName(name2);
    if (v1 == -1 || v2 == -1)
        return false;

    return matrix[v1][v2] > 0;
}
// проверка существования вершины
bool Community::vertexExists(std::string name)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == name)
            return true;
    return false;
}

// удаление вершины
void Community::delVertex(std::string name)
{
    int v1 = getNumberFromName(name);
    if (v1 == -1)
        return;
    for (int i = 0; i < vertexCount; i++)
    {
        if (edgeExists(vertexes[v1], vertexes[i])) {
            delEdge(vertexes[v1], vertexes[i]);
        }
    }

    vertexes[v1] = vertexes[vertexCount - 1];

    for (int i = 0; i < vertexCount; i++)
    {
        matrix[v1][i] = matrix[vertexCount - 1][i];
        matrix[i][v1] = matrix[i][vertexCount - 1];
        matrix[vertexCount - 1][i] = 0;
        matrix[i][vertexCount - 1] = 0;
    }
    vertexes[vertexCount - 1] = "";
    vertexCount--;
}

// удаление ребра
void Community::delEdge(std::string name1, std::string name2)
{
    if (!edgeExists(name1, name2))
        return;

    int v1 = getNumberFromName(name1);
    int v2 = getNumberFromName(name2);
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}

std::string Community::getName(int num)
{
    if (num < SIZE)
        return vertexes[num];
    else
        return "";
}

void Community::showmatrix()
{
    for (int i = 0; i < vertexCount; i++)
        std::cout << "\t" << vertexes[i];
    std::cout << std::endl;
    for (int i = 0; i < vertexCount; i++)
    {
        std::cout << vertexes[i] << "\t";
        for (int j = 0; j < vertexCount; j++)
            std::cout << matrix[i][j] << "\t";
        std::cout << std::endl;
    }
}

void Community::depthInner(int current, bool visited[], int weights[], int to, int* min)
{
    if (current == to)
    {
        return;
    }
    visited[current] = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (edgeExists(vertexes[current], vertexes[i]) && !visited[i])
        {
            *min += matrix[current][i];
            if (*min < weights[i])
                weights[i] = *min;

            if (i == to)
                return;
            else
            {
                depthInner(i, visited, weights, to, min);
                *min = weights[current];
                visited[i] = false;
            }
        }
    }
}

int Community::findMinWayDFS(std::string From, std::string To) {
    // Ваш код должен быть здесь 
    if (From == To)
        return 0;
    if (From == "" || To == "")
        return 0;
    int from = getNumberFromName(From);
    int to = getNumberFromName(To);
    int sum = 0;
    bool visited[SIZE];
    int weights[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        visited[i] = false;
        if (i == from)
            weights[i] = 0;
        else
        {
            if (edgeExists(vertexes[from], vertexes[i]))
                weights[i] = matrix[from][i];
            else
                weights[i] = VERYBIGINT;
        }
    }
    visited[from] = true;

    for (int i = 0; i < SIZE; i++)
    {
        if (edgeExists(vertexes[from], vertexes[i]) && !visited[i])
        {
            sum = matrix[from][i];
            depthInner(i, visited, weights, to, &sum);

            for (int j = 0; j < SIZE; j++)
                visited[j] = false;

            visited[from] = true;
        }
    }

    return weights[to];
}
/*
int Community::findPathCount(int from, int to) {
    // Ваш код должен быть здесь 
    if (from == to)
        return 0;

    bool visited[SIZE];
    int count = 0;
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;

    visited[from] = true;

    for (int i = 0; i < SIZE; i++)
    {
        if (edgeExists(from, i) && !visited[i])
        {
            std::cout << "v0";
            //depthInner(i, visited, to, &count);

            for (int j = 0; j < SIZE; j++)
                visited[j] = false;

            visited[from] = true;
        }
    }
    return count;
}*/