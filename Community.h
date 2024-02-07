#pragma once
#include <iostream>

#define SIZE 20

class Community {
public:
    Community();
    // ���������� �������
    void addVertex(std::string name);
    // ���������� �����
    void addEdge(std::string name1, std::string name2);
    // �������� �������
    void delVertex(std::string name);
    // �������� �����
    void delEdge(std::string name1, std::string name2);
    // ����� ������������ "����������" ����� ���������
    int findMinWayDFS(std::string from, std::string to);
    // ��������� ������ ��������
    void depthInner(int current, bool visited[], int weights[], int to, int* min);
    // ��������� �������� ������� (�����) �� �� �������
    std::string getName(int num);
    // ����� ������� ��������� �� ����� �������
    void showmatrix();

private:
    // �������� ������������� ����� ����� ���������
    bool edgeExists(std::string name1, std::string name2);
    // �������� ������������� ������� �� �����
    bool vertexExists(std::string name);
    // ��������� ������� ������� �� �� ��������
    int getNumberFromName(std::string name);

    int matrix[SIZE][SIZE]; // ������� ���������

    std::string vertexes[SIZE]; // ��������� ������
    int vertexCount; // ���������� ����������� ������
};

