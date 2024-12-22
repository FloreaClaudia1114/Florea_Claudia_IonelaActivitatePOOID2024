#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Petitie {
private:


public:
    string data_depunerii;
    string numePrenume;
    char* categorie;
    string descriere_solicitare;
    bool status;
    int nrZile;
    int static nrPetitii;

    Petitie() {

        this->data_depunerii = "";
        this->numePrenume = "";
        this->categorie = nullptr;
        this->descriere_solicitare = "";
        this->status = true;
        this->nrZile = 0;

    }

    Petitie(string data_depunerii = "", string numePrenume = "", const char* categorie = nullptr, string descriere_solicitare = "", bool status = true, int nrZile = 0) {

        this->data_depunerii = data_depunerii;
        this->numePrenume = numePrenume;
        bool operator!() {
            if (status == 0 && nrZile > 30) {
                return true;
            }
            else {
                return false;
            }
        }

        void operator~() {
            if (status == 0) {
                status = 1;
            }
            else {
                status = 0;
            }
        }

    };

    int Petitie::nrPetitii = 0;

    int main() {
        Petitie p1("10/12/2024", "IonValentin", "Obligatorie", "AAA", true, 25);
        cout << "Petitie p1" << endl;
        cout << "Categorie: " << p1.getCategorie() << endl;
        cout << "Data depunere: " << p1.getDataDepunerii() << endl;
        cout << "Descriere: " << p1.getDescriereSolicitare() << endl;
        cout << "Nume solicitant: " << p1.getNumePrenume() << endl;
        cout << "Status: " << p1.getStatus() << endl;
        cout << "Nr zile: " << p1.getNrZile() << " " << "zile" << endl;
        cout << endl;

        Petitie p2("10/12/2024", "IonValentin", "Obligatorie", "AAA", false, 31);
        cout << "Petitie p2" << endl;
        cout << "Categorie: " << p2.getCategorie() << endl;
        cout << "Data depunere: " << p2.getDataDepunerii() << endl;
        cout << "Descriere: " << p2.getDescriereSolicitare() << endl;
        cout << "Nume solicitant: " << p2.getNumePrenume() << endl;
        cout << "Status: " << p2.getStatus() << endl;
        cout << "Nr zile: " << p2.getNrZile() << " " << "zile" << endl;
        cout << endl;

        cout << "Status modificat!" << endl;
        bool ok = !p1;
        cout << (p1.getNrZile() > 30 ? "Expirata" : "Ok") << endl;
        cout << endl;

        cout << "Status modificat!" << endl;
        bool ok1 = !p2;
        cout << (p2.getNrZile() > 30 ? "Expirata" : "Ok") << endl;
        cout << endl;

        ~p1;
        cout << "Dupa ~" << endl << p1 << endl;
    }