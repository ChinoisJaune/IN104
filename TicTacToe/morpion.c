#include "morpion.h"

char** create_grid() {
	char** grid = malloc(3*sizeof(char*));
	if (grid==NULL) {
		printf("Erreur mémoire\n");
		return NULL;
	}
	for (int i=0;i<3;i++) {
		grid[i]=malloc(3*sizeof(char));
		if (grid[i]==NULL) {
			printf("Erreur mémoire\n");
			free(grid);
			return NULL;
		}
		for (int j=0;j<3;j++) {
			grid[i][j]='.';
		}
	}
	return grid;
}

void free_grid(char** grid) {
	for (int i=0;i<3;i++) {
		free(grid[i]);
	}
	free(grid);
}

void reset_grid(char** grid) {
	for (int i=0;i<3;i++) {
		for (int j=0;j<3;j++) {
			grid[i][j]='.';
		}
	}
}

void print_grid(char** grid) {
	for (int i=2;i>=0;i--) {
		for (int j=0;j<3;j++) {
			printf("%c",grid[i][j]);
		}
		printf("\n");
	}
}

bool is_game_over(char** grid) {
	if ((grid[0][0]!='.' && grid[0][0]==grid[1][1] && grid[0][0]==grid[2][2])
		|| (grid[0][2]!='.' && grid[0][2]==grid[1][1] && grid[0][2]==grid[2][0])) 
		return true;
	for (int i=0;i<3;i++) {
		if ((grid[i][0]!='.' && grid[i][0]==grid[i][1] && grid[i][0]==grid[i][2])
		|| (grid[0][i]!='.' && grid[0][i]==grid[1][i] && grid[0][i]==grid[2][i])) 
		return true;
	}
	return false;
}

void place_on_grid(char symbol, char** grid, int i, int j) {
	grid[i][j]=symbol;
}

