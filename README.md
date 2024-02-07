# Friends
Данный проект описывает граф знакомств "друзей". Результатом выполнения программы является вывод всех пар, которые знакомы не более, чем через 3 "рукопожатия".
Реализован данный граф с помощью класса Community, который состоит из:
* приватных полей:
    - int matrix[SIZE][SIZE]; // матрица смежности
    - std::string vertexes[SIZE]; // хранилище вершин
    - int vertexCount; // количество добавленных вершин
  (SIZE - максимальная вместимость графа; в данном случае – 20)
* публичных методов:
    - void addVertex(std::string name); // добавление вершины
    - void addEdge(std::string name1, std::string name2); // добавление ребра
    - void delVertex(std::string name); // удаление вершины
    - void delEdge(std::string name1, std::string name2); // удаление ребра
    - int findMinWayDFS(std::string from, std::string to); // поиск минимального "расстояния" между вершинами
    - void depthInner(int current, bool visited[], int weights[], int to, int* min); // алгоритма обхода вглубину
    - std::string getName(int num); // получение названия вершины (имени) по ее индексу
    - void showmatrix(); // вывод матрицы смежности на экран консоли
* приватных методов:
    - bool edgeExists(std::string name1, std::string name2); // проверка существования ребра между вершинами
    - bool vertexExists(std::string name); // проверка существования вершины по имени
    - int getNumberFromName(std::string name); // получение индекса вершины по ее названию
