#include <iostream>
#include <fstream>

using namespace std;

class Catering {
private:
	string numeClient;
	string data;
	int pret;
	char* produse;
public:
	static int nrProduse;

	Catering() {
		this->numeClient = "";
		this->data = "";
		this->pret = 0;
		this->produse = nullptr;
	}

	Catering(string numeClient = "", string data = "", int pret = 0, const char* produse = nullptr) {
		this->numeClient = numeClient;
		this->data = data;
		this->pret = pret;
		if (produse != nullptr) {
			this->produse = new char[strlen(produse) + 1];
			strcpy_s(this->produse, strlen(produse) + 1, produse);
		}
		else {
			this->produse = nullptr;
		}
	}

	Catering(const Catering& c) {
		this->numeClient = c.numeClient;
		this->data = c.data;
		this->pret = c.pret;
		if (c.produse != nullptr) {
			this->produse = new char[strlen(c.produse) + 1];
			strcpy_s(this->produse, strlen(c.produse) + 1, c.produse);
		}
		else {
			this->produse = nullptr;
		}
	}

	~Catering() {
		if (this->produse != nullptr) {
			delete[] this->produse;
		}
	}

	Catering& operator=(const Catering& c) {
		if (this->produse != nullptr) {
			delete[] this->produse;
		}

		this->numeClient = c.numeClient;
		this->data = c.data;
		this->pret = c.pret;
		if (c.produse != nullptr) {
			this->produse = new char[strlen(c.produse) + 1];
			strcpy_s(this->produse, strlen(c.produse) + 1, c.produse);
		}
		else {
			this->produse = nullptr;
		}

		return *this;
	}

	string getNumeClient() {
		return this->numeClient;
	}

	string getData() {
		return this->data;
	}

	int getPret() {
		return this->pret;
	}

	char* getProduse() {
		return this->produse;
	}

	friend ostream& operator<<(ostream& out, Catering c) {
		out << c.numeClient << " " << c.data << " " << c.pret << " " << c.produse << " ";
		if (c.produse != nullptr) {
			out << c.produse;
		}
		return out;
	}

	Catering operator++(int i) {
		Catering copie = *this;
		this->pret++;
		return copie;
	}
	
};

int Catering::nrProduse = 0;

int main() {
	Catering c1("Ionescu", "12.09.2021", 550, "Prajituri");
	cout << "Nume client: " << c1.getNumeClient() << endl;
	cout << "Data: " << c1.getData() << endl;
	cout << "Pret: " << c1.getPret() << " " << "lei" << endl;
	cout << "Produse: " << c1.getProduse() << endl;
	cout << endl;

	Catering c2("Popescu", "21.11.2022", 700, "Bufet Suedez");
	cout << "Nume client: " << c2.getNumeClient() << endl;
	cout << "Data: " << c2.getData() << endl;
	cout << "Pret: " << c2.getPret() << " " << "lei" << endl;
	cout << "Produse: " << c2.getProduse() << endl;
	cout << endl;

	c1.getPret();
	cout << "Pret: " << c1.getPret() << " " << "lei" << endl;
	c1++;
	cout << "Pret: " << c1.getPret() << " " << "lei" << endl;
	c1++;
	cout << "Pret: " << c1.getPret() << " " << "lei" << endl;
	c1++;
}