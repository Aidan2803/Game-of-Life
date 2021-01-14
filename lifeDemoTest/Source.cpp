#include <SDL.h>
#include <iostream>
#include <ctime>
#include <vector>

#define WIDTH 1000
#define HEIGHT 1000
#define PIX_WIDTH 5

using namespace std;

const int xAmount = WIDTH / PIX_WIDTH;
const int yAmount = HEIGHT / PIX_WIDTH;
const int maxCells = xAmount * yAmount;

bool xypos[xAmount][yAmount];
bool xyposPrev[xAmount][yAmount];
int xyCounter[xAmount][yAmount];

vector<SDL_Rect> cells;

void reWritePrev() {
	for (int i = 0; i < yAmount; i++) {
		for (int j = 0; j < xAmount; j++) {
			xyposPrev[i][j] = xypos[i][j];
		}		
	}
}

void printCells() {
	for (int i = 0; i < yAmount; i++) {
		for (int j = 0; j < xAmount; j++) {
			cout << xypos[i][j] << " ";
		}
		cout << endl;			
	}
}

void checkCells(SDL_Renderer *rend, int testCounter) {
	for (int i = 0; i < yAmount; i++) {
		for (int j = 0; j < xAmount; j++) {
			int counter = 0, xFlag = -1, yFlag = -1;
			bool checkArr[8] = { false, false, false, false, false, false, false, false };	// state of each cell for check

			if (j == 0) {			//x
				xFlag = 0;
			}
			else if (j == xAmount - 1) {
				xFlag = 1;
			}
			if (i == 0) {			//y
				yFlag = 0;
			}
			else if (i == yAmount - 1) {
				yFlag = 1;
			}
			
			for (int id = 0; id < 8; id++) {
				if (xFlag == 0) {
					if (yFlag == 0) {
						if (xypos[i][j + 1] && !checkArr[0]) {
							counter++;
							checkArr[0] = true;
							//cout << "checks 1" << endl;
							//cout << "xypos[i][j + 1 ]" << xypos[i][j + 1] << " i = " << i << " j = " << j << endl;
						}
						else if (xypos[i + 1][j + 1] && !checkArr[1]) {
							counter++;
							checkArr[1] = true;
							//cout << "checks 2" << endl;
							//cout << "xypos[i + 1][j + 1] " << xypos[i + 1][j + 1] << " i = " << i << " j = " << j << endl;
						}
						else if (xypos[i + 1][j] && !checkArr[2]) {
							counter++;
							checkArr[2] = true;
							//cout << "checks 3" << endl;
							//cout << "xypos[i + 1][j] " << xypos[i + 1][j] << " i = " << i << " j = " << j << endl;
						}
					}
					else if (yFlag == 1) {
						if (xypos[i - 1][j] && !checkArr[0]) {
							counter++;
							checkArr[0] = true;
							//cout << "checks 4" << endl;
						}
						else if (xypos[i - 1][j + 1] && !checkArr[1]) {
							counter++;
							checkArr[1] = true;
							//cout << "checks 5" << endl;
						}
						else if (xypos[i][j + 1] && !checkArr[2]) {
							counter++;
							checkArr[2] = true;
							//cout << "checks 6" << endl;
						}
					}
					else if (yFlag == -1) {
						if (xypos[i - 1][j] && !checkArr[0]) {
							counter++;
							checkArr[0] = true;
							//cout << "checks 7" << endl;
						}
						else if (xypos[i - 1][j + 1] && !checkArr[1]) {
							counter++;
							checkArr[1] = true;
							//cout << "checks 8" << endl;
						}
						else if (xypos[i][j + 1] && !checkArr[2]) {
							counter++;
							checkArr[2] = true;
							//cout << "checks 8" << endl;
						}
						else if (xypos[i + 1][j + 1] && !checkArr[3]) {
							counter++;
							checkArr[3] = true;
							//cout << "checks 9" << endl;
						}
						else if (xypos[i + 1][j] && !checkArr[4]) {
							counter++;
							checkArr[4] = true;
							//cout << "checks 10" << endl;
						}
					}
				}
				else if (xFlag == 1) {
					if (yFlag == 0) {
						if (xypos[i + 1][j] && !checkArr[0]) {
							counter++;
							checkArr[0] = true;
							//cout << "checks 11" << endl;
						}
						else if (xypos[i + 1][j - 1] && !checkArr[1]) {
							counter++;
							checkArr[1] = true;
							//cout << "checks 12" << endl;
						}
						else if (xypos[i][j - 1] && !checkArr[2]) {
							counter++;
							checkArr[2] = true;
							//cout << "checks 13" << endl;
						}
					}
					else if (yFlag == 1) {
						if (xypos[i - 1][j] && !checkArr[0]) {
							counter++;
							checkArr[0] = true;
							//cout << "checks 14" << endl;
						}
						else if (xypos[i][j - 1] && !checkArr[1]) {
							counter++;
							checkArr[1] = true;
							//cout << "checks 15" << endl;
						}
						else if (xypos[i - 1][j - 1] && !checkArr[2]) {
							counter++;
							checkArr[2] = true;
							//cout << "checks 16" << endl;
						}
					}
					else if (yFlag == -1) {
						if (xypos[i - 1][j] && !checkArr[0]) {
							counter++;
							checkArr[0] = true;
							//cout << "checks 17" << endl;
						}
						else if (xypos[i + 1][j] && !checkArr[1]) {
							counter++;
							checkArr[1] = true;
							//cout << "checks 18" << endl;
						}
						else if (xypos[i + 1][j - 1] && !checkArr[2]) {
							counter++;
							checkArr[2] = true;
							//cout << "checks 19" << endl;
						}
						else if (xypos[i][j - 1] && !checkArr[3]) {
							counter++;
							checkArr[3] = true;
							//cout << "checks 20" << endl;
						}
						else if (xypos[i - 1][j - 1] && !checkArr[4]) {
							counter++;
							checkArr[4] = true;
							//cout << "checks 21" << endl;
						}
					}
				}
				else if (xFlag == -1) {
					if (yFlag == 0) {
						if (xypos[i][j + 1] && !checkArr[0]) {
							counter++;
							checkArr[0] = true;
							//cout << "checks 22" << endl;
						}
						else if (xypos[i + 1][j + 1] && !checkArr[1]) {
							counter++;
							checkArr[1] = true;
							//cout << "checks 23" << endl;
						}
						else if (xypos[i + 1][j] && !checkArr[2]) {
							counter++;
							checkArr[2] = true;
							//cout << "checks 24" << endl;
						}
						else if (xypos[i + 1][j - 1] && !checkArr[3]) {
							counter++;
							checkArr[3] = true;
							//cout << "checks 25" << endl;
						}
						else if (xypos[i][j - 1] && !checkArr[4]) {
							counter++;
							checkArr[4] = true;
							//cout << "checks 26" << endl;
						}
					}
					else if (yFlag == 1) {
						if (xypos[i - 1][j] && !checkArr[0]) {
							counter++;
							checkArr[0] = true;
							//cout << "checks 27" << endl;
						}
						else if (xypos[i - 1][j + 1] && !checkArr[1]) {
							counter++;
							checkArr[1] = true;
							//cout << "checks 28" << endl;
						}
						else if (xypos[i][j + 1] && !checkArr[2]) {
							counter++;
							checkArr[2] = true;
							//cout << "checks 29" << endl;
						}
						else if (xypos[i][j - 1] && !checkArr[3]) {
							counter++;
							checkArr[3] = true;
						//	cout << "checks 30" << endl;
						}
						else if (xypos[i - 1][j - 1] && !checkArr[4]) {
							counter++;
							checkArr[4] = true;
							//cout << "checks 31" << endl;
						}
					}
					else if (yFlag == -1) {
						if (xypos[i - 1][j] && !checkArr[0]) {		//1
							counter++;
							checkArr[0] = true;
						}
						else if (xypos[i - 1][j + 1] && !checkArr[1]) {		//2
							counter++;
							checkArr[1] = true;
							//cout << "checks 31" << endl;
						}
						else if (xypos[i][j + 1] && !checkArr[2]) {		//3
							counter++;
							checkArr[2] = true;
							//cout << "checks 32" << endl;
						}
						else if (xypos[i + 1][j + 1] && !checkArr[3]) {		//4
							counter++;
							checkArr[3] = true;
							//cout << "checks 33" << endl;
						}
						else if (xypos[i + 1][j] && !checkArr[4]) {		//5
							counter++;
							checkArr[4] = true;
							//cout << "checks 34" << endl;
						}
						else if (xypos[i + 1][j - 1] && !checkArr[5]) {		//6
							counter++;
							checkArr[5] = true;
							//cout << "checks 35" << endl;
						}
						else if (xypos[i][j - 1] && !checkArr[6]) {	//7
							counter++;
							checkArr[6] = true;
							//cout << "checks 36" << endl;
						}
						else if (xypos[i - 1][j - 1] && !checkArr[7]) {		//8
							counter++;
							checkArr[7] = true;
							//cout << "checks 37" << endl;
						}
					}
				}
			}			

			
			//system("pause");

			/*cout << "xypos[i][j] = " << xypos[i][j] << endl;
			cout << "i = " << i << "j = " << j << endl;
			cout << "xflag = " << xFlag << "yflag = " << yFlag << endl;*/
			//cout << "counter = " << counter << endl;
			//system("pause");

			/*if (testCounter > 8) {
				SDL_SetRenderDrawColor(rend, 240, 248, 255, 0);  //white
				SDL_Rect newR = { j * PIX_WIDTH, i * PIX_WIDTH, PIX_WIDTH, PIX_WIDTH };
				SDL_RenderFillRect(rend, &newR);

				SDL_RenderPresent(rend);

				system("pause");
			}*/
			
			//Œ“À¿ƒ»“‹

			xyCounter[i][j] = counter;			
		}
	}

	for (int i = 0; i < yAmount; i++) {
		for (int j = 0; j < xAmount; j++) {
			if (xypos[i][j]) {		//if cell is alive

				if (xyCounter[i][j] < 2) {
					xypos[i][j] = false;
				}
				else if (xyCounter[i][j] == 2 || xyCounter[i][j] == 3) {
					xypos[i][j] = xypos[i][j];		//or just do not touch
				}
				else if (xyCounter[i][j] > 3) {
					xypos[i][j] = false;
					//cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
				}
			}
			else if (!xypos[i][j]) {
				if (xyCounter[i][j] == 3) {
					xypos[i][j] = true;
				}
			}
		}
	}
}

void drawCells(SDL_Renderer *rend) {
	//delete false cells
	int randColour = 0;
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderClear(rend);	
	
	
	SDL_SetRenderDrawColor(rend, 255, 69, 0, 0);

	for (int i = 0, k = 0; i < yAmount; i++) {		
		for (int j = 0; j < xAmount; j++, k++) {
			//SDL_SetRenderDrawColor(rend, rand() % 255, rand() % 255, rand() % 255, 0);
			/*randColour = rand() % 100;
			if (randColour < 50) {
				SDL_SetRenderDrawColor(rend, 64, 224, 208, 0);
			}
			else {
				SDL_SetRenderDrawColor(rend, 255, 69, 0, 0);
			}*/
			if (xypos[i][j]) {
				cells[k] = { j * PIX_WIDTH, i * PIX_WIDTH, PIX_WIDTH, PIX_WIDTH };
				SDL_RenderFillRect(rend, &cells[k]);
			}			
		}		
	}	

	SDL_RenderPresent(rend);
}

void start() {	
	for (int i = 0; i < yAmount; i++) {
		for (int j = 0; j < xAmount; j++) {
			xypos[i][j] = false;
			xyCounter[i][j] = 0;
		}
	}

	for (int i = 0; i < 6000; i++) {
		xypos[rand() % xAmount][rand() % yAmount] = true;
	}

	for (int i = 0; i < maxCells; i++) {
		SDL_Rect newRect;
		cells.push_back(newRect);
	}
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	SDL_Init(SDL_INIT_EVERYTHING);

	bool quite = false;
	int testCounter = 0;

	SDL_Window *window = SDL_CreateWindow("pls work", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	start();

	while (!quite) {		
		drawCells(renderer);
		//printCells();

		//system("pause");

		reWritePrev();
		checkCells(renderer, testCounter);

		SDL_Delay(5);		

		drawCells(renderer);
		testCounter++;
		//printCells();

		//system("pause");
	}	

	return 0;
}