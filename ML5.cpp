#include <iostream>
#include <string>
#include <vector>
using namespace std;

void uorshil(vector<vector<int>>& W, const vector<vector<int>>& M, int size) {
	
	for (int k = 0; k < size; k++) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (M[i][j] || (M[i][k]) &&M[k][j])
					W[i][j] = 1;
			}
		}
	}

}


int main() {
	setlocale(LC_ALL, "Russian");
	int size;


	cout << "������� ���-�� ������: ";
	cin >> size;
	vector<vector<int>> W(size, vector<int>(size));
	vector<vector<int>> M(size, vector<int>(size));
	cout << "������� �������� �������" << " : " << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			cin >> M[i][j];
			if (M[i][j] != 0 && M[i][j] != 1) {
				cout << "������: ������� ������ ��������� ������ 0 ��� 1." << endl;
				return 1;
			}
		}
	}

	uorshil(W, M, size);
	cout <<"\n������� ������������:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			cout << W[i][j]<< " ";
			
		}
		cout << endl;
	}

}