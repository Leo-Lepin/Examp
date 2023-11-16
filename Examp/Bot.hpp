#pragma once
#include "Table.hpp"

void aiIfShot(Table& tableBot, Table& tablePl)// ��� ��, ���� ��� �����
{
	if ((l || r || d || u) == 0) {
		l = 1;
		r = 1;
		u = 1;
		d = 1;
	}
	vector<pair<int, int>> possible;
	if (l && xl - 1 >= 0 && (tablePl[y][xl - 1] != 'o' || tablePl[y][xl - 1] != 'x'))
		possible.push_back({ y, xl - 1 });// ����
	if (r && xr + 1 < 10 && (tablePl[y][xr + 1] != 'o' || tablePl[y][xr + 1] != 'x'))
		possible.push_back({ y, xr + 1 });// �����
	if (u && yu - 1 >= 0 && (tablePl[yu - 1][x] != 'o' || tablePl[yu - 1][x] != 'x'))
		possible.push_back({ yu - 1, x });// �����
	if (d && yd + 1 < 10 && (tablePl[yd + 1][x] != 'o' || tablePl[yd + 1][x] != 'x'))
		possible.push_back({ yd + 1, x });// ����
	if (possible.size() == 0) {
		cout << "ERROR\n";
		return;
	}
	int rnd = rand() % possible.size();
	int yn = possible[rnd].first, xn = possible[rnd].second;
	if (xn > 9 || yn > 9) {
		cout << "UTRF";
		return;
	}
	if (tablePl[yn][xn] == 'k') {
		ydar = 1;
		if (yn == y) {
			u = d = 0;
			if (xn == xl - 1)
				xl--;
			else
				xr++;
		}
		else {
			r = l = 0;
			if (yn == yu - 1)
				yu--;
			else
				yd++;
		}
		tablePl[yn][xn] = 'x';
		tableBot[yn][xn] = 'x';
	}
	else {
		ydar = 0;
		if (xn == xl - 1)
			l = 0;
		else if (xn == xr + 1)
			r = 0;
		else if (yn == yu - 1)
			u = 0;
		else if (yn == yd + 1)
			d = 0;
		tablePl[yn][xn] = 'o';
		tableBot[yn][xn] = 'o';
	}
}

void aiRnd(Table& tableBot, Table& tablePl)// ��� ��� ����
{
	vector<pair<int, int>> free;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (tableBot[i][j] == '.') {
				free.push_back({ i, j });
			}
		}
	}
	int rnd = rand() % free.size();// ������ ����������
	y = free[rnd].first;
	x = free[rnd].second;
	if (tablePl[y][x] == 'k') {
		shot = 1;
		xl = x; xr = x;
		yu = y; yd = y;
	}
	tableBot[y][x] = (tablePl[y][x] == 'k') ? 'x' : 'o';
	tablePl[y][x] = (tablePl[y][x] == 'k') ? 'x' : 'o';
}

void aiHub()// ��� ��
{
	if (shot && !(tableplship.isShipExist(x, y))) {
		shot = 0;
		tableplship.destroyShip();
		tablebotshoot.destroyShip();
		l = 0; r = 0; d = 0; u = 0;
	}
	if (shot)
		aiIfShot(tablebotshoot, tableplship);
	else
		aiRnd(tablebotshoot, tableplship);
	cout << y + 1 << " " << x + 1 << endl;;
}