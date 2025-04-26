#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Relation {
	char first;
	char second;
};
struct Element {
	char one;
};

void inputArr(vector<Element>& mass, int size) {
	Element el;
	cout << "Input елемент " <<" : ";
	for (int i = 0; i < size; i++) {
		/*cout << "Input елемент " << i << " : ";*/
		
		cin >> el.one;
			
			mass.push_back(el);
		
	}

}

void inputRelation(vector<Relation>& volume,vector<Element>& mass, vector<Element>& mass2,int n,int size1,int size2){
	Relation rel;
	cout << "Введите отношение в формате (a,b)" << endl;
	for (int i = 0; i < n; i++) {
		bool flag1 = false;
		bool flag2 = false;
		string input;
		cin >> input;
		for (int j=0;j<size1;j++){
			if (input[1] == mass[j].one) {
				flag1 = true;
				break;
			}
		}
		for (int j = 0; j < size2; j++) {
			if (input[3] == mass2[j].one) {
				flag2 = true;
				break;
			}
		}
		if (flag1 == true && flag2 == true) {
			rel.first = input[1];
			rel.second = input[3];
			volume.push_back(rel);
		}
		else {
			cout << "Неккоректный ввод";
			i--;
		}
		
	}
}
void findFunction(vector<Element>& mass, vector<Relation>& volume, int size,int n) {
	bool flag = true;
	for (int i = 0; i < size; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (mass[i].one == volume[j].first)
				count++;
		}
		if (count != 1) {
			flag = false;
			break;

		}
	}
	if (flag == true)
		cout << "отношение является функцией" << endl;
	else
		cout << "отношение НЕ является функцией" << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	vector<Relation> volume1;
	vector<Element> mass1;
	vector<Element> mass2;
	int size1;
	int size2;
	int n;
	cout << "Введите размер первого множества: ";
	cin >> size1;

	inputArr(mass1, size1);
	

	cout << "Введите размер второго множества: ";
	cin >> size2;
	inputArr(mass2, size2);
	

	cout << "Введите размер отношения: ";
	cin >> n;
	inputRelation(volume1, mass1, mass2, n, size1, size2);

	findFunction(mass1, volume1, size1, n);
}