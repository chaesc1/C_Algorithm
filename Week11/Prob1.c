#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool check(int *graph, int row) {
	for (int i = row-1; i >= 0; i--) {
		//위의 행들이 세로로 있거나 대각에 있으면 return false
		if (graph[i] == graph[row]) {
			return false;
		}
		if (abs(graph[row] - graph[i]) == abs(row - i)) {
			return false;
		}
	}
	return true;
}

int answer = 0;
void backTracking(int *graph,int row, int n) {
	if (row == n) {
		answer++;
		return;
	}
	
	//체스판의 각 행마다 모두 퀸을 놓아보고, 되면 다음 행, 안 되면 다음 열
	for (int col = 0; col < n; col++) {
		graph[row] = col;
		if (check(graph, row)) {
			backTracking(graph, row + 1, n);
		}
		graph[row] = 0;
	}
}

int main() {
	//동적 배열
	int *graph;

    for (int i = 1; i <=15; i++)
    {
        graph = (int *)malloc(sizeof(int) * i);
        graph[i] = 0;
        answer = 0;
        backTracking(graph,0, i);
	    printf("%d:%d\n", i,answer);
    }
	
	return 0;
}