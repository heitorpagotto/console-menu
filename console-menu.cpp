#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define colNumber 100

SYSTEM_INFO siSysInfo;

int isProgramRunning = 1;

void renderNavbar(int options);
void transformCursor(int x, int y);
int handleProgram();
void handleNavbarOptions(int pressedChar);
void renderPcInfo();
void renderDownloadsInfo();
void renderFavoritesInfo();
void renderContainer(int menuHeight);

int main() {
	system("mode con:cols=100 lines=30");
	renderNavbar(0);
	GetSystemInfo(&siSysInfo);
	return handleProgram();
}

int handleProgram() {
	while(isProgramRunning == 1) {
		char pressedChar = getch();
		handleNavbarOptions(pressedChar);
		if (pressedChar == 27) {
			isProgramRunning = 0;
		}
	}
	
	return 0;
}

void renderNavbar(int options) {
	int col = 0;
	printf("\n");
	printf("     1.PC                2.Downloads                3.Favoritos");
	printf("\n");
	
	for (col = 0; col < colNumber; col++) {
		printf("_");	
	}
	
	switch(options) {
		case 1:
			renderPcInfo();
			break;
		case 2:
			renderDownloadsInfo();
			break;
		case 3:
			renderFavoritesInfo();
			break;
		default:
			break;
	}
	
	transformCursor(0,25);
	printf("\n    Pressione ESC para Sair...");
	
}

void renderPcInfo() {
	renderContainer(5);
	transformCursor(30, 5);
	printf("Processador: INTEL i5 limonations\n");
	transformCursor(30, 6);
	printf("Quantidade de Núcleos: %u\n", siSysInfo.dwNumberOfProcessors);
	transformCursor(30, 7);
	printf("Armazenamento: 465GB\n");
	transformCursor(30, 8);
	printf("Memoria RAM: 8GB 2000MhZ\n");
}

void renderDownloadsInfo() {
	renderContainer(10);
	transformCursor(25, 5);
	printf("%c Rock lee vs Gaara ao som de Linkin park.mp4", 16);
	transformCursor(25, 7);
	printf("%c As melhores video cacetadas do faustao 2012.mp3", 14);
	transformCursor(25, 9);
	printf("%c Rap do Minecraft.mp3", 14);
	transformCursor(25, 11);
	printf("%c CromaCartao.exe", 2);
	transformCursor(25, 13);
	printf("%c utorrent.exe", 2);
}

void renderFavoritesInfo() {
	renderContainer(12);
	transformCursor(25, 5);
	printf("%c Rock lee vs Gaara ao som de Linkin park.mp4", 16);
	transformCursor(25, 7);
	printf("%c As melhores video cacetadas do faustao 2012.mp3", 14);
	transformCursor(25, 9);
	printf("%c MensagensDeBomDia.jpg", 20);
	transformCursor(25, 11);
	printf("%c Fotos ano novo 2000", 15);
	transformCursor(25, 13);
	printf("%c Half-Life.exe", 5);
	transformCursor(25, 15);
	printf("%c Tibia.exe", 5);
}

void handleNavbarOptions(int pressedChar) {
	switch (pressedChar) {
		case 49:
			system("cls");
			renderNavbar(1);
			break;
		case 50:
			system("cls");
			renderNavbar(2);
			break;
		case 51:
			system("cls");
			renderNavbar(3);
			break;
	}
}

void transformCursor(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void renderContainer(int menuHeight) {
	transformCursor(20, 4);
	printf("%c", 201);
	printf("===========================================================");
	printf("%c", 187);

	int transformationQty;
	for (transformationQty = 0; transformationQty < menuHeight; transformationQty++) 
	{
		transformCursor(20, 5 + transformationQty);
		printf("%c",186);
	}
	for (transformationQty = 0; transformationQty < menuHeight; transformationQty++)
	{
		transformCursor(80, 5 + transformationQty);
		printf("%c", 186);
	}

	transformCursor(20, 4 + menuHeight);
	printf("%c", 200);
	printf("===========================================================");
	printf("%c", 188);
}