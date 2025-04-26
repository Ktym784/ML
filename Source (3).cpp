#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Element {
	char oddNum;
	char Num;
	char letter;
	char evenNum;
};

void inputArr(vector<Element>& mass, int size) {
	Element el;
	for (int i = 0; i < size; i++) {
		cout << "Input елемент jcbi " << i << " : ";
		string input;
		cin >> input;

		if (input.length() == 4 &&
			(input[0] >= '0' && input[0] <= '9') && ((input[0] - '0') % 2 != 0) &&
			(input[1] >= '0' && input[1] <= '9') &&
			(input[2] >= 'a' && input[2] <= 'z') &&
			(input[3] >= '0' && input[3] <= '9') && ((input[3] - '0') % 2 == 0))
			{
				el.oddNum = input[0];
				el.Num = input[1];
				el.letter = input[2];
				el.evenNum = input[3];
				mass.push_back(el);
			}
		else {
			cout << "Error" << endl;
			i--;
		}
	}

}

void printArray(const vector<Element>& mass) {
	for (int i = 0; i < mass.size(); ++i) {
		cout << "Element " << i << ": " << mass[i].oddNum << mass[i].Num << mass[i].letter << mass[i].evenNum << endl;
	}
}

void delSameEl(vector<Element>& mass) {
	vector<Element> sameEl;
	for (int i = 0; i < mass.size(); ++i) {
		bool isUnique = true;

		// ѕровер€ем, встречаетс€ ли элемент в uniqueElements
		for (int j = 0; j < sameEl.size(); ++j) {
			if (mass[i].oddNum == sameEl[j].oddNum &&
				mass[i].Num == sameEl[j].Num &&
				mass[i].letter == sameEl[j].letter &&
				mass[i].evenNum == sameEl[j].evenNum) {
				isUnique = false;
				break;
			}
		}

		// ≈сли элемент уникален, добавл€ем его в uniqueElements
		if (isUnique) {
			sameEl.push_back(mass[i]);
		}
	}

	// ќчищаем оригинальный вектор и заполн€ем его уникальными элементами
	mass.clear();
	for (size_t i = 0; i < sameEl.size(); ++i) {
		mass.push_back(sameEl[i]);
	}
}
void unionArrays(vector<Element>& result, vector<Element>& mass1, vector<Element>& mass2) {
	for (int i = 0; i < mass1.size(); ++i)
		result.push_back(mass1[i]);
	for (int i = 0; i < mass2.size(); ++i)
		result.push_back(mass2[i]);
	delSameEl(result);
}

void intersection(vector<Element>& result, vector<Element>& mass1, vector<Element>& mass2) {
	for (int i = 0; i < mass1.size(); i++) {
	
		for (int j = 0; j < mass2.size(); j++) {
			if (mass1[i].oddNum == mass2[j].oddNum &&
				mass1[i].Num == mass2[j].Num &&
				mass1[i].letter == mass2[j].letter &&
				mass1[i].evenNum == mass2[j].evenNum) {
				result.push_back(mass1[i]);
				break;

			}
		}
	}
	delSameEl(result);
}
void complement(vector<Element>& result, vector<Element>& mass1, vector<Element>& mass2) {
	for (int i = 0; i < mass1.size();i++) {
		bool flag = true;
		for (int j = 0; j < mass2.size(); j++) {
			if (mass1[i].oddNum == mass2[j].oddNum &&
				mass1[i].Num == mass2[j].Num &&
				mass1[i].letter == mass2[j].letter &&
				mass1[i].evenNum == mass2[j].evenNum) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			result.push_back(mass1[i]);
		}
	}
	delSameEl(result);
}
void difference(vector<Element>& result, vector<Element>& mass1, vector<Element>& mass2) {
	for (int i = 0; i < mass1.size(); i++) {
		bool flag = true;
		for (int j = 0; j < mass2.size(); j++) {
			if (mass1[i].oddNum == mass2[j].oddNum &&
				mass1[i].Num == mass2[j].Num &&
				mass1[i].letter == mass2[j].letter &&
				mass1[i].evenNum == mass2[j].evenNum) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			result.push_back(mass1[i]);
		}


	}
	for (int i = 0; i < mass2.size(); i++) {
		bool flag = true;
		for (int j = 0; j < mass1.size(); j++) {
			if (mass1[j].oddNum == mass2[i].oddNum &&
				mass1[j].Num == mass2[i].Num &&
				mass1[j].letter == mass2[i].letter &&
				mass1[j].evenNum == mass2[i].evenNum) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			result.push_back(mass2[i]);
		}
	}
	delSameEl(result);
}


int main() {
	setlocale(LC_ALL, "Russian");
	int size1, size2;
	vector<Element> mass1;
	vector<Element> mass2;
	vector<Element> mass_unification;
	vector<Element> mass_intersection;
	vector<Element> mass_complemen;
	vector<Element> mass_complemen2;
	vector<Element> mass_diff;
	cout << "с - цифра, b-буква, i -четна€ цифра.j-нечетна€\n";
	cout << "¬ведите размер первого множества: ";
	cin >> size1;

	inputArr(mass1, size1);
	cout << "\n";

	cout << "¬ведите размер второго множества: ";
	cin >> size2;
	inputArr(mass2, size2);
	cout << "\n";

	

	delSameEl(mass1);
	delSameEl(mass2);
	cout << "Ёлементы первого множества: " << endl;
	printArray(mass1);
	cout << "\n";

	cout << "Ёлементы второго множества: " << endl;
	printArray(mass2);
	cout << "\n";

	
	unionArrays(mass_unification, mass1, mass2);
	cout << "Ёлементы обьединени€ множеств: " << endl;
	printArray(mass_unification);
	cout << "\n";
	cout << "Ёлементы пересечени€ множеств:"  << endl;
	intersection(mass_intersection, mass1, mass2);
	printArray(mass_intersection);
	cout << "\n";
	cout << "Ёлементы обьединени€ AB множеств: " << endl;
	complement(mass_complemen, mass1, mass2);
	printArray(mass_complemen);
	cout << "\n";
	cout << "Ёлементы обьединени€ BA множеств: " << endl;
	complement(mass_complemen2, mass2, mass1);
	printArray(mass_complemen2);
	cout << "\n";
	cout << "Ёлементы симметрической разности множеств: " << endl;
	difference(mass_diff, mass1, mass2);
	printArray(mass_diff);
	return 0;
}