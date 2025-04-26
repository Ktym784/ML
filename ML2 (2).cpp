#include <iostream>
#include <string>
#include <vector>
using namespace std;
void reflex(const vector<vector<int>>& r) {
	bool flag = true;
	for (int i = 0; i < r.size(); i++) {
		if (r[i][i] != 1)
			flag = false;
	}
	if (flag == false) {
		cout << "не рефлексивно" << endl;
	}
	else {
		cout << "рефлексивно" << endl;
	}
}

void symmetric(const vector<vector<int>>& r) {
	bool flag = true;
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r.size(); j++) {
			if (r[i][j] != r[j][i])
				flag = false;
		}
	}
	if (flag == false) {
		cout << "не симметрично"<<endl;
	}
	else {
		cout << "симметрично" << endl;
	}

}
void antiSymmetric(const vector<vector<int>>& r) {
	bool flag = true;
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r.size(); j++) {
			if (r[i][j] == 1 && r[j][i] == 1 && i != j)
				flag = false;
		
		}
	}
	if (flag == false) {
		cout << "не кососимметрично" << endl;
	}
	else {
		cout << "кососимметрично" << endl;
	}

}

void Transit(const vector<vector<int>>& r) {
	bool flag = true;
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r.size(); j++) {
			if (r[i][j] == 1) {
				for (int k = 0; k < r.size(); k++) {
					if (r[j][k] == 1 && r[i][k] != 1)
						flag = false;
				}
			}
		}
	}
	if (flag == false) {
		cout << "не транзитивно" << endl;
	}
	else {
		cout << "транзитивно" << endl;
	}

}


int main() {
	setlocale(LC_ALL, "Russian");
	int size;
	

	cout << "¬ведите размер множества: ";
	cin >> size;
	vector<vector<int>> r(size, vector<int>(size));
	cout << "¬ведите элементы матрицы" <<" : "<<endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			
			cin >> r[i][j];
			if (r[i][j] != 0 && r[i][j] != 1) {
				cout << "ќшибка: матрица должна содержать только 0 или 1." << endl;
				return 1;
			}
		}
	}
	reflex(r);
	symmetric(r);
	antiSymmetric(r);
	Transit(r);

}