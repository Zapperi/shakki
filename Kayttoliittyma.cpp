#include "shakki.h"



Kayttoliittyma::Kayttoliittyma(Asema* asema) {
	_asema = asema;
}

Kayttoliittyma::Kayttoliittyma() {
	_asema = new Asema();
}

void Kayttoliittyma::annaVastustajanVari(){
	int vari;
	wcout << L"Anna syotettavan pelaajan vari: 0(Valkoinen), 1(Musta):\n";
	wcin >> vari;
	cin.ignore();
	this->vastustajanVari = vari;
}

void Kayttoliittyma::piirraLauta() {
	for (int i = 7; i >= 0; i--) {
		//Lis‰t‰‰n numerot vasempaan laitaan
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN);
		wcout << i + 1;
		for (int j = 0; j <= 7; j++) {
			if ((i + j) % 2 == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_GREEN);
				if (_asema->_lauta[i][j]) {
					wcout << _asema->_lauta[i][j]->getUnicode();
				}
				else {
					wcout << L"   ";
				}
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
				if (_asema->_lauta[i][j]) {
					wcout << _asema->_lauta[i][j]->getUnicode();
				}
				else {
					wcout << L"   ";
				}
			}
		}
		wcout << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN);
	char* kirjaimet[] = { " "," A ", " B ", " C "," D "," E "," F "," G "," H " };
	for (int i = 0; i < 9; i++) {
		wcout << kirjaimet[i];
	}
	wcout << endl;
};


Siirto Kayttoliittyma::kasittely(string syote, int vari) {
	//Saa syˆtteen muodossa esim ( S1a-3a  )
	int alkurivi, alkusarake, loppurivi, loppusarake;
	char nappulanMerkki = syote[0]; //<-- muutetaan myˆhemmin

	if (syote == "O-O" || syote == "o-o") {
		Siirto siirto(true, false);
		return siirto;
	}
	else if (syote == "O-O-O" || syote == "o-o-o") {
		Siirto siirto(false, true);
		return siirto;
	}
	else {

		//Selvitet‰‰n alkuruudun koordinaatit
		alkurivi = syote[2] - '0';
		alkurivi--;
		switch (syote[1])
		{
		case 'A':
		case 'a':
			alkusarake = 0;
			break;
		case 'B':
		case 'b':
			alkusarake = 1;
			break;
		case 'C':
		case 'c':
			alkusarake = 2;
			break;
		case 'D':
		case 'd':
			alkusarake = 3;
			break;
		case 'E':
		case 'e':
			alkusarake = 4;
			break;
		case 'F':
		case 'f':
			alkusarake = 5;
			break;
		case 'G':
		case 'g':
			alkusarake = 6;
			break;
		case 'H':
		case 'h':
			alkusarake = 7;
			break;
		default:
			wcout << L"No et osannut.." << endl;
			wcout << "Anna uusi syote : ";
			string temp;
			cin.clear();
			getline(cin, temp);
			kasittely(temp, vari);
			break;
		}
		//Selvitet‰‰n loppuruudun koordinaatit
		loppurivi = syote[5] - '0';
		loppurivi--;
		switch (syote[4])
		{
		case 'A':
		case 'a':
			loppusarake = 0;
			break;
		case 'B':
		case 'b':
			loppusarake = 1;
			break;
		case 'C':
		case 'c':
			loppusarake = 2;
			break;
		case 'D':
		case 'd':
			loppusarake = 3;
			break;
		case 'E':
		case 'e':
			loppusarake = 4;
			break;
		case 'F':
		case 'f':
			loppusarake = 5;
			break;
		case 'G':
		case 'g':
			loppusarake = 6;
			break;
		case 'H':
		case 'h':
			loppusarake = 7;
			break;
		default:
			wcout << L"No et osannut.." << endl;
			wcout << "Anna uusi syote : ";
			string temp;
			cin.clear();
			getline(cin, temp);
			kasittely(temp, vari);
			break;
		}
		Ruutu alkuruutu(alkurivi, alkusarake);
		Ruutu loppuruutu(loppurivi, loppusarake);
		/*_asema->lista.clear();
		_asema->annaLaillisetSiirrot(_asema->lista);
		_asema->listanSiivous(_asema->lista, vari);*/
		if (vari == 0) {
			if (alkuruutu == _asema->vkruutu)
				_asema->vkruutu = loppuruutu;
		}
		else {
			if (alkuruutu == _asema->mkruutu)
				_asema->mkruutu = loppuruutu;
		}
		_asema->_lauta[alkurivi][alkusarake]->Onkoliikutettu = true;
		Siirto siirto(alkuruutu, loppuruutu);
		char korotus;
		if (nappulanMerkki == 's' && (loppurivi == 0 && vari == 1 || loppurivi == 7 && vari == 0)) {
			wcout << "Miksi nappulaksi haluat korottaa? (esim. D)\n";
			cin >> korotus;
			cin.ignore();
			if (loppurivi == 7) {
				if (korotus == 'D' || korotus == 'd')
					siirto._nappulanKorotus = _asema->vd;
				if (korotus == 'T' || korotus == 't') 
					siirto._nappulanKorotus = _asema->vt;
				if (korotus == 'R' || korotus == 'r') 
					siirto._nappulanKorotus = _asema->vr;
				if (korotus == 'L' || korotus == 'l') 
					siirto._nappulanKorotus = _asema->vl;
			}
			if (loppurivi == 0) {
				if (korotus == 'D' || korotus == 'd')
					siirto._nappulanKorotus = _asema->md;
				if (korotus == 'T' || korotus == 't') 
					siirto._nappulanKorotus = _asema->mt;
				if (korotus == 'R' || korotus == 'r') 
					siirto._nappulanKorotus = _asema->mr;
				if (korotus == 'L' || korotus == 'l') 
					siirto._nappulanKorotus = _asema->ml;
			}
		}
		return siirto;
	}
}