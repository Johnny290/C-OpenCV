// Matrix rain effect in terminal

#include <iostream>
#include <windows.h>

int Modulus(int iN, int iMod) {
	int iQ = (iN / iMod);
	return iN - (iQ * iMod);
}

char GetChar(int iGenerator, char cBase, int iRange) {
	return (cBase + Modulus(iGenerator, iRange));
}

int main() {
	// Color code
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 2);

	char caRow[80];
	int j = 7;
	int k = 2;
	int l = 5;
	int m = 1;
	while (true) {
		int i = 0;
		while (i < 80) {
			if (caRow[i] != ' ') {
				caRow[i] = GetChar(j + i * i, 180, 39);
				if (((i * i + k) % 71) == 0) {
					SetConsoleTextAttribute(hConsole, 7);
				}
				else {
					SetConsoleTextAttribute(hConsole, 2);
				}
			}
			std::cout << caRow[i];
			++i;
			SetConsoleTextAttribute(hConsole, 2);
		}
		j = (j + 31);
		k = (k + 17);
		l = (l + 47);
		m = (m + 67);
		caRow[Modulus(j, 80)] = '-';
		caRow[Modulus(k, 80)] = ' ';
		caRow[Modulus(l, 80)] = '-';
		caRow[Modulus(m, 80)] = ' ';
		// Delay
		Sleep(0.01);
	}
	return 0;
}
