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
		cout << "�� �����������" << endl;
	}
	else {
		cout << "�����������" << endl;
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
		cout << "�� �����������"<<endl;
	}
	else {
		cout << "�����������" << endl;
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
		cout << "�� ���������������" << endl;
	}
	else {
		cout << "���������������" << endl;
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
		cout << "�� �����������" << endl;
	}
	else {
		cout << "�����������" << endl;
	}

}


int main() {
	setlocale(LC_ALL, "Russian");
	int size;
	

	cout << "������� ������ ���������: ";
	cin >> size;
	vector<vector<int>> r(size, vector<int>(size));
	cout << "������� �������� �������" <<" : "<<endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			
			cin >> r[i][j];
			if (r[i][j] != 0 && r[i][j] != 1) {
				cout << "������: ������� ������ ��������� ������ 0 ��� 1." << endl;
				return 1;
			}
		}
	}
	reflex(r);
	symmetric(r);
	antiSymmetric(r);
	Transit(r);

}