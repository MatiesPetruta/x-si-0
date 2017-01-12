#include <stdio.h>
#include <stdlib.h>
using namespace std;
int p1Score = 0;
int p2Score = 0;
	//initializeaza tabela cu caracterul "space"
void InitBoard(char table [][3] ) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) table[i][j] = ' ';
	}
}



	//functia care printeza tabla de joc
void PrintBoard(char table [][3]) {

	system("cls");
	printf("Score:\nJucatorul 1: %d\nJucatorul 2: %d\n\n",p1Score,p2Score);
	printf("-------------\n");
	printf("| %c | %c | %c |\n", table[0][0], table[0][1], table[0][2]);
	printf("-------------\n");
	printf("| %c | %c | %c |\n", table[1][0], table[1][1], table[1][2]);
	printf("-------------\n");
	printf("| %c | %c | %c |\n", table[2][0], table[2][1], table[2][2]);
	printf("-------------\n");
}


int main() {
	char board[3][3];
	int noOfPlayers = 0;
	PrintBoard(board);
	//selectam de jucatori
	while (noOfPlayers == 0) {
		printf("Selectati numarul de jucatori: \n");
		scanf("%d", &noOfPlayers);
		if (noOfPlayers != 1 && noOfPlayers != 2) {
			noOfPlayers = 0;
			printf("\nIntroduceti 1 sau 2.\n");
		}
	}

}

