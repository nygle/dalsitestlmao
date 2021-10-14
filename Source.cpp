#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Auta {
private:
	string model;
	string znacka;
	int rok;
public:
	Auta() {}
	Auta(string model, string znacka, int rok) {
		this->znacka = znacka;
		this->rok = rok;
		this->model = model;
	}
	string dejJmeno() { return znacka; }
	int dejRok() { return rok; }
	string dejModel() { return model; }

};

class AutoBazar{
private:
	string soubor;
	string nazev;
	int pocet = 0;
	Auta pocetAut[500];
	bool aktualizace;
public:
	AutoBazar(){}
	AutoBazar(string nazev,string soubor) {
		this->nazev = nazev;
		this->soubor = soubor;
		ifstream cteni(soubor);
		if (cteni.fail()) {
			cout << "chyba...." << endl;
			system("pause");
			exit(0);
		}
		string model;
		string znacka;
		int rok;
		while (cteni >> znacka >> model >> rok) {
			pocetAut[pocet] = Auta(znacka, model, rok);
			pocet++;
		}
		cteni.close();
	}
	string dejNazev() { return nazev; }
	void vypisAut() {
		for  (int i = 0; i < pocet; i++){
			cout << pocetAut[i].dejJmeno() << " " << pocetAut[i].dejModel() << " " << pocetAut[i].dejRok() << endl;
		}
	}
	void pridejAuto() {
		string znacka;
		cout << "Znacka: ";
		cin >> znacka;
		string model;
		cout << "Model: ";
		cin >> model;
		int rok;
		cout << "Rok: ";
		cin >> rok;
		pocetAut[pocet] = Auta(znacka, model, rok);
		pocet++;
	}
	void aktualizovatBazar() {
		if (aktualizace) {
			ofstream zapis(soubor);
			for (int i = 0; i < pocet; i++) {
				zapis << pocetAut[i].dejJmeno() << " " << pocetAut[i].dejModel() << " " << pocetAut[i].dejRok() << endl;
			}
			zapis.close();
		}

	}
};



int main(void) {
//---------------------ZKOUŠKA--------------------------------------------
	//Auta _petr("Skoda", 1890);
	//cout << _petr.dejJmeno() << " " << _petr.dejRok() << endl;

	//AutoBazar Pepca("AutoBazar", "Auta.txt");

//-----------------------PROGRAM-----------------------------------------------------
	AutoBazar nyglo("Autobazar", "Auta.txt");
	int volba;
	string jmeno;
	string model;
	int rok;
	do {
		system("cls");
		cout << "\t"<<nyglo.dejNazev() << endl;
		cout << "--------MENU--------" << endl << endl;
		cout << "1. Ukazka vsech aut v Bazaru" << endl;
		cout << "2. Pridat Auto do bazaru" << endl;
		cout << "3. ukoncit program" << endl;
		cin >> volba;
		switch (volba) {
		case 1:
			system("cls");
			nyglo.vypisAut();
			system("pause");
			break;
		case 2:
			system("cls");
			nyglo.pridejAuto();
			system("pause");
			break;
		case 3:
			nyglo.aktualizovatBazar();
			return 0;
		}



	} while (volba != 3);






	system("pause");
	return 0;
}