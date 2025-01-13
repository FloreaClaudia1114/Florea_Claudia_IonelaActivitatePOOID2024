#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Asigurare {
private:
	string nume;
	int sumaA;
	int durataA;
	char* tipA;
public:
	static int nrAsigurari;

	Asigurare() {
		this->nume = "";
		this->sumaA = 0;
		this->durataA = 0;
		this->tipA = nullptr;
	}

	Asigurare(string nume = "", int sumaA = 0,
		int durataA = 0, const char* tipA = nullptr) {
		this->nume = nume;
		this->sumaA = sumaA;
		this->durataA = durataA;
		if (tipA != nullptr) {
			this->tipA = new char[strlen(tipA) + 1];
			strcpy_s(this->tipA, strlen(tipA) + 1, tipA);
		} else {
			this->tipA = nullptr;
		}
	}

	Asigurare(const Asigurare& a) {
		this->nume = a.nume;
		this->sumaA = a.sumaA;
		this->durataA = a.durataA;
		if (a.tipA != nullptr) {
			this->tipA = new char[strlen(a.tipA) + 1];
			strcpy_s(this->tipA, strlen(a.tipA) + 1, a.tipA);
		}
		else {
			this->tipA = nullptr;
		}
	}

	~Asigurare() {
		if (this->tipA != nullptr) {
			delete[] this->tipA;
		}
	}

	Asigurare& operator=(const Asigurare& a) {
		if (this->tipA != nullptr) {
			delete[] this->tipA;
		}

		this->nume = a.nume;
		this->sumaA = a.sumaA;
		this->durataA = a.durataA;
		if (a.tipA != nullptr) {
			this->tipA = new char[strlen(a.tipA) + 1];
			strcpy_s(this->tipA, strlen(a.tipA) + 1, a.tipA);
		}
		else {
			this->tipA = nullptr;
		}

		return *this;
	}

	string getNume() {
		return this->nume;
	}

	int getSumaA() {
		return this->sumaA;
	}

	int getDurataA() {
		return this->durataA;
	}

	char* getTipA() {
		return this->tipA;
	}

	friend ostream& operator<<(ostream& out, Asigurare a) {
		out << a.nume << " " << a.sumaA << " " <<
			a.durataA << " " << a.tipA << " ";
		if (a.tipA != nullptr) {
			out << a.tipA;
		}

		return out;
	}

	operator int() {
		return this->sumaA * this->sumaA;
	}
};

int Asigurare::nrAsigurari = 0;

int main() {
	Asigurare a1("Ionescu", 250, 10, "Sanatate");
	cout << "Asigurare 1" << endl;
	cout << "Nume: " << a1.getNume() << endl;
	cout << "Suma asigurare: " << a1.getSumaA() << " " << "lei" << endl;
	cout << "Durata asigurare: " << a1.getDurataA() << " " << "luni" << endl;
	cout << "Tip asigurare: " << a1.getTipA() << endl;
	cout << endl;

	Asigurare a2("Popescu", 400, 15, "Calatorie");
	cout << "Asigurare 2" << endl;
	cout << "Nume: " << a2.getNume() << endl;
	cout << "Suma asigurare: " << a2.getSumaA() << " " << "lei" << endl;
	cout << "Durata asigurare: " << a2.getDurataA() << " " << "luni" << endl;
	cout << "Tip asigurare: " << a2.getTipA() << endl;
	cout << endl;

	double b = 250.8;
	int x;
	x = b;
	cout << "b = " << b << endl;
	cout << "x = " << x << endl;

	cout << "Suma asigurarilor este de " << int(a1.getSumaA() * a2.getSumaA()) << " " << "lei" << endl;
}