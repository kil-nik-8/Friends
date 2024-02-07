#include <iostream>
#include "Community.h"
using namespace std;

int main()
{
	Community friends;
	friends.addVertex("Nikita");
	friends.addVertex("Andrew");
	friends.addVertex("Maksim");
	friends.addVertex("Daniil");
	friends.addVertex("Denis");
	friends.addVertex("Dasha");
	friends.addVertex("Nastya");
	friends.addVertex("Egor");

	friends.addEdge("Nikita", "Andrew");
	friends.addEdge("Nikita", "Dasha");
	friends.addEdge("Nikita", "Maksim");
	friends.addEdge("Nikita", "Daniil");
	friends.addEdge("Maksim", "Denis");
	friends.addEdge("Maksim", "Daniil");
	friends.addEdge("Maksim", "Andrew");
	friends.addEdge("Andrew", "Daniil");
	friends.addEdge("Dasha", "Nastya");
	friends.addEdge("Nastya", "Egor");

	int matrix[SIZE][SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		matrix[i][i] = 0;
		for (int j = 0; j < i; j++)
		{
			matrix[i][j] = friends.findMinWayDFS(friends.getName(i), friends.getName(j));
			matrix[j][i] = matrix[i][j];
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (matrix[i][j] < 4 && matrix[i][j] != 0)
				cout << friends.getName(i) << " " << friends.getName(j) << endl;
		}
	}

	return 0;
}