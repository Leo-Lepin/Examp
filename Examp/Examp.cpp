#include "Game.hpp"



int main() {
	setlocale(LC_ALL, "Russian");
	cout << "1-PvP\n2-Bot\n";
	int choose;
	cin >> choose;
	while (choose < 1 || choose > 2) {
		cout << "ОТ 1 ДО 2 ВВОД\n";
		cin >> choose;
	}
	game(choose);
	cout << "Корабли первого игрока\n";
	tableplship.print();
	cout << "Поле стрельбы первого и игрока\n";
	tableplshoot.print();
	cout << "Кораблии второго игрока\n";
	tablebotship.print();
	cout << "Поле стрельбы второго игрока\n";
	tablebotshoot.print();
}