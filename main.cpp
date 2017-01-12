
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

	//citeste si verifica inputul userului de la tastatura
bool GetMove(bool player,char table[][3]) {
	int line;
	int column;
	//citim linia
	printf("Line: ");
	scanf("%d", &line);
	if (line < 0 || line > 3) return false;
	//citim coloana
	printf("Column: ");
	scanf("%d", &column);
	if (column < 0 || column > 3) return false;
	line -= 1;
	column -= 1;
	//verificam daca in tabela este ocupata pozitia respectiva
	if (table[line][column] != ' ') return false;
	if (player) table[line][column] = 'X';
	else table[line][column] = '0';
	return true;
}

	//verifica daca cineva a castigat
bool CheckForWin(char table[][3]) {
	//verificam pe linii
	for (int i = 0; i < 3; i++) {
		if ((table[i][0] != ' ') && (table[i][0] == table[i][1]) && (table[i][1] == table[i][2])) return true;
	}
	//verificam pe coloane
	for (int i = 0; i < 3; i++) {
		if ((table[0][i] != ' ') && (table[0][i] == table[1][i]) && (table[1][i] == table[2][i])) return true;
	}
	//verificam diagonalele
	if ((table[0][0] != ' ') && (table[0][0] == table[1][1]) && (table[1][1] == table[2][2])) return true;
	if ((table[2][0] != ' ') && (table[2][0] == table[1][1]) && (table[1][1] == table[0][2])) return true;
	return false;

}

bool CheckForFull(char table[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (table[i][j] == ' ') return false;
		}
	}
}



int main() {
	char board[3][3];
	int noOfPlayers = 0;

	//selectam numarul de jucatori
	while (noOfPlayers == 0) {
		printf("Selectati numarul de jucatori: \n");
		scanf("%d", &noOfPlayers);
		if (noOfPlayers != 1 && noOfPlayers != 2) {
			noOfPlayers = 0;
			printf("\nIntroduceti 1 sau 2.\n");
		}
	}
	//player vs player
	if (noOfPlayers == 2) {
		p1Score = 0;
		p2Score = 0;
		bool exit = false;
		while (!exit) {
			InitBoard(board);
			bool win = false;
			bool full = false;
			bool player = rand()%2;
			bool move = false;
			while (!win && !full) {
				PrintBoard(board);
				if (player) printf("Jucatorul 1\n");
				else printf("Jucatorul 2\n");
				while (!move) {
					move = GetMove(player, board);
					if (!move) printf("Pozitia este ocupata sau invalida!\n");
				}
				full = CheckForFull(board);
				win = CheckForWin(board);
				if (full) {
					PrintBoard(board);
					printf("Remiza!\nDaca doriti sa continuati introduceti 1, daca nu orice altceva\n");
					int quit = 0;
					scanf("%d", &quit);
					if (quit != 1) exit = true;
				}
				if (win) {
					PrintBoard(board);
					printf("A castigat player %d\nDaca doriti sa continuati introduceti 1, daca nu orice altceva\n", (player) ? 1 : 2);
					(player) ? p1Score++ : p2Score++;
					int quit = 0;
					scanf("%d", &quit);
					if (quit != 1) exit = true;
				}
				player = !player;
				move = false;
			}
		}
	}



}
