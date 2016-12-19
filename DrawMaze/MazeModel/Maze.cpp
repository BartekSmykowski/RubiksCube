#define _CRT_SECURE_NO_WARNINGS
#include "Maze.h"
#include <time.h>
#include <iostream>

MazeModel::Maze::Maze()
{
	board = nullptr;
	dimensions.x = 0;
	dimensions.y = 0;
	player = new MazeModel::Player();
	LoadFromFile(".\\SavedMazes\\labirynt_domyslny");
}

MazeModel::Maze::~Maze()
{
	for (int i = 0; i < dimensions.x; i++) {
		delete board[i];
	}
	delete[] board;
	delete player;
}

void MazeModel::Maze::LoadFromFile(char *filename)
{
	FILE* labirynt_plik = fopen(filename, "r");
	char znak = 0;
	srand((unsigned int)time(NULL));

	if (labirynt_plik == NULL) {
		std::cout << "nie udalo sie wczytac labiryntu" << std::endl;
	}
	else {



		fscanf(labirynt_plik, "%d %d\n", &dimensions.x, &dimensions.y);   //czytanie z pliku wysokosci i szerokosci labiryntu
		board = new char*[(int)dimensions.x];
		for (int i = 0; i < dimensions.x; i++) {
			board[i] = new char[(int)dimensions.y];
		}
		for (int i = 0; i < dimensions.x; i++)                 //tymczasowe inicjalizowanie planszy/labiryntu
			for (int j = 0; j < dimensions.y; j++)
				board[i][j] = '.';

		for (int j = 0; j < dimensions.y; j++) {        //czytanie z pliku ukladu scian
			for (int i = 0; i < dimensions.x + 1; i++) {
				znak = getc(labirynt_plik);
				if (znak == ' ')
					board[i][j] = ' ';
				if (strcmp(filename, ".\\SavedMazes\\labirynt_domyslny") == 0) {
					if (znak != '\n' && znak != ' ') {
						switch (rand() % 5) {
						case 0: board[i][j] = '#'; break;
						case 1: board[i][j] = 'B'; break;
						case 2: board[i][j] = '%'; break;
						case 3: board[i][j] = '&'; break;
						case 4: board[i][j] = '@'; break;
						}
					}
				}
				else if (znak != '\n')
					board[i][j] = znak;
			}
		}
		int x, y;
		fscanf(labirynt_plik, "%d %d", &x, &y);   //czytanie z pliku poczatkowego polozenia gracza
		//player->GetCamera()->
		player->setPosition(glm::vec2(2 * x, 2 * y));

		fclose(labirynt_plik);
	}
}

void MazeModel::Maze::SaveToFile(const std::string & filename)
{
	FILE *plik_zapisu = fopen(filename.c_str(), "w");
	fprintf(plik_zapisu, "%d %d\n", dimensions.x, dimensions.y);
	for (int i = 0; i < dimensions.y; i++) {
		for (int j = 0; j < dimensions.x; j++) {
			putc(board[j][i], plik_zapisu);
		}
		putc('\n', plik_zapisu);
	}
	//fprintf(plik_zapisu, "%f %f", player->GetLocation().x, player->GetLocation().y);
	fclose(plik_zapisu);
}

MazeModel::Player *MazeModel::Maze::Getplayer()
{
	return player;
}

glm::ivec2 MazeModel::Maze::GetDimensions()
{
	return dimensions;
}

char MazeModel::Maze::GetTypeOfWall(glm::ivec2 coordinates)
{
	int x = coordinates.x;
	int y = coordinates.y;
	return board[x][y];
}
