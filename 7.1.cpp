#include <stdio.h>
#include <windows.h>
#include <time.h>

void DFS(int k, int* vis, int** G, int n)
{
	vis[k] = 1;
	printf("%d ", k);
	for (int i = 0; i < n; i++)
	{
		if (G[k][i] == 1 && vis[i] == 0)
			DFS(i, vis, G, n);
	}
}

int main(void)
{
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int n, k;
	printf("Введите количество вершин графа: ");
	scanf_s("%d", &n);
	printf("Матрица смежности:\n");
	int** G = (int**)malloc(n * sizeof(int*));
	int* vis = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		vis[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			G[i][j] = rand() % 2;
			if (i == j)
			{
				G[i][j] = 0;
			}
			G[j][i] = G[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", G[i][j]);
		}
		printf("\n");
	}
	printf("\nВершина, с которой начнется обход: ");
	scanf_s("%d", &k);
	DFS(k, vis, G, n);
	printf("\n");
}
