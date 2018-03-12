#include "shakki.h"

Nappula::Nappula(wstring unikoodi, int color, int koodi) {
	unicode = unikoodi;
	_vari = color;
	_koodi = koodi;
}


void Nappula::setKoodi(int koodi) {
	_koodi = koodi;
};

int Nappula::getKoodi() {
	return _koodi;
};

void Nappula::setUnicode(wstring unikoodi) {
	unicode = unikoodi;
};

wstring Nappula::getUnicode() {
	return unicode;
};

void Nappula::setVari(int color) {
	_vari = color;
};

int Nappula::getVari() {
	return _vari;
};

void Nappula::annaSiirrot(std::list<Siirto>& lista, Ruutu& ruutu, Asema& asema, int vari) {

};

void Sotilas::annaSiirrot(std::list<Siirto>& lista, Ruutu& ruutu, Asema& asema, int vari) {
	int alkuRivi = ruutu.getRivi();
	int alkuSarake = ruutu.getSarake();
	if (vari == 0) {
		if (asema._lauta[alkuRivi + 1][alkuSarake] == nullptr && alkuRivi + 1 < 8) {
			Ruutu loppuRuutu(alkuRivi + 1, alkuSarake);
			Siirto temp(ruutu, loppuRuutu);
			if (alkuRivi < 6)
				lista.push_back(temp);
			else
				asema.lisaaSotilaanKorotukset(&temp, lista, &asema);
			
		}if (asema._lauta[alkuRivi + 1][alkuSarake - 1] != nullptr && asema._lauta[alkuRivi + 1][alkuSarake - 1]->getVari() == 1) {
			Ruutu loppuRuutu(alkuRivi + 1, alkuSarake - 1);
			Siirto temp(ruutu, loppuRuutu);
			if (alkuRivi < 6)
				lista.push_back(temp);
			else
				asema.lisaaSotilaanKorotukset(&temp, lista, &asema);
		}if (asema._lauta[alkuRivi + 1][alkuSarake + 1] != nullptr && asema._lauta[alkuRivi + 1][alkuSarake + 1]->getVari() == 1) {
			Ruutu loppuRuutu(alkuRivi + 1, alkuSarake + 1);
			Siirto temp(ruutu, loppuRuutu);
			if (alkuRivi < 6)
				lista.push_back(temp);
			else
				asema.lisaaSotilaanKorotukset(&temp, lista, &asema);
		}
		if (!Onkoliikutettu && asema._lauta[alkuRivi + 1][alkuSarake] == nullptr && asema._lauta[alkuRivi + 2][alkuSarake] == nullptr) {
			Ruutu loppuRuutu(alkuRivi + 2, alkuSarake);
			Siirto temp(ruutu, loppuRuutu);
			lista.push_back(temp);
		}
		if (alkuRivi == 4 && asema._ohestaLyontiSarake + 1 == alkuSarake || asema._ohestaLyontiSarake - 1 == alkuSarake) {
			if (asema._ohestaLyontiSarake + 1 == alkuSarake) {
				Ruutu loppuRuutu(alkuRivi + 1, alkuSarake + 1);
				Siirto temp(ruutu, loppuRuutu);
				lista.push_back(temp);
			}
			else if (asema._ohestaLyontiSarake - 1 == alkuSarake) {
				Ruutu loppuRuutu(alkuRivi + 1, alkuSarake - 1);
				Siirto temp(ruutu, loppuRuutu);
				lista.push_back(temp);
			}
		}
	}
	else if (vari == 1) {
		if (asema._lauta[alkuRivi - 1][alkuSarake] == nullptr && alkuRivi - 1> 0) {
			Ruutu loppuRuutu(alkuRivi - 1, alkuSarake);
			Siirto temp(ruutu, loppuRuutu);
			if (alkuRivi > 1)
				lista.push_back(temp);
			else
				asema.lisaaSotilaanKorotukset(&temp, lista, &asema);
		}if (asema._lauta[alkuRivi - 1][alkuSarake - 1] != nullptr && asema._lauta[alkuRivi - 1][alkuSarake - 1]->getVari() == 0) {
			Ruutu loppuRuutu(alkuRivi - 1, alkuSarake - 1);
			Siirto temp(ruutu, loppuRuutu);
			if (alkuRivi > 1)
				lista.push_back(temp);
			else
				asema.lisaaSotilaanKorotukset(&temp, lista, &asema);
		}if (asema._lauta[alkuRivi - 1][alkuSarake + 1] != nullptr && asema._lauta[alkuRivi - 1][alkuSarake + 1]->getVari() == 0) {
			Ruutu loppuRuutu(alkuRivi - 1, alkuSarake + 1);
			Siirto temp(ruutu, loppuRuutu);
			if (alkuRivi > 1)
				lista.push_back(temp);
			else
				asema.lisaaSotilaanKorotukset(&temp, lista, &asema);
		}
		if (!Onkoliikutettu && asema._lauta[alkuRivi - 1][alkuSarake] == nullptr && asema._lauta[alkuRivi - 2][alkuSarake] == nullptr) {
			Ruutu loppuRuutu(alkuRivi - 2, alkuSarake);
			Siirto temp(ruutu, loppuRuutu);
			lista.push_back(temp);
		}
		if (alkuRivi == 3 && asema._ohestaLyontiSarake + 1 == alkuSarake || asema._ohestaLyontiSarake - 1 == alkuSarake) {
			if (asema._ohestaLyontiSarake + 1 == alkuSarake) {
				Ruutu loppuRuutu(alkuRivi - 1, alkuSarake + 1);
				Siirto temp(ruutu, loppuRuutu);
				lista.push_back(temp);
			}
			else if (asema._ohestaLyontiSarake - 1 == alkuSarake) {
				Ruutu loppuRuutu(alkuRivi - 1, alkuSarake - 1);
				Siirto temp(ruutu, loppuRuutu);
				lista.push_back(temp);
			}
		}
	}
};

void Ratsu::annaSiirrot(std::list<Siirto>& lista, Ruutu& ruutu, Asema& asema, int vari) {
	int x, y;
	x = ruutu.getRivi();
	y = ruutu.getSarake();
	if (x + 2 < 8 && y + 1 < 8) {
		if (asema._lauta[x + 2][y + 1] == nullptr) {
			Ruutu temp_ruutu(x + 2, y + 1);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x + 2][y + 1]->getVari() != vari) {
				Ruutu temp_ruutu(x + 2, y + 1);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
	if (x + 2 < 8 && y - 1 >= 0) {
		if (asema._lauta[x + 2][y - 1] == nullptr) {
			Ruutu temp_ruutu(x + 2, y - 1);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x + 2][y - 1]->getVari() != vari) {
				Ruutu temp_ruutu(x + 2, y - 1);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
	if (x + 1 < 8 && y + 2 < 8) {
		if (asema._lauta[x + 1][y + 2] == nullptr) {
			Ruutu temp_ruutu(x + 1, y + 2);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x + 1][y + 2]->getVari() != vari) {
				Ruutu temp_ruutu(x + 1, y + 2);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
	if (x + 1 < 8 && y - 2 >= 0) {
		if (asema._lauta[x + 1][y - 2] == nullptr) {
			Ruutu temp_ruutu(x + 1, y - 2);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x + 1][y - 2]->getVari() != vari) {
				Ruutu temp_ruutu(x + 1, y - 2);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
	if (x - 1 >= 0 && y + 2 < 8) {
		if (asema._lauta[x - 1][y + 2] == nullptr) {
			Ruutu temp_ruutu(x - 1, y + 2);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x - 1][y + 2]->getVari() != vari) {
				Ruutu temp_ruutu(x - 1, y + 2);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
	if (x - 1 >= 0 && y - 2 >= 0) {
		if (asema._lauta[x - 1][y - 2] == nullptr) {
			Ruutu temp_ruutu(x - 1, y - 2);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x - 1][y - 2]->getVari() != vari) {
				Ruutu temp_ruutu(x - 1, y - 2);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
	if (x - 2 >= 0 && y - 1 >= 0) {
		if (asema._lauta[x - 2][y - 1] == nullptr) {
			Ruutu temp_ruutu(x - 2, y - 1);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x - 2][y - 1]->getVari() != vari) {
				Ruutu temp_ruutu(x - 2, y - 1);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
};

void Lahetti::annaSiirrot(std::list<Siirto>& lista, Ruutu& ruutu, Asema& asema, int vari) {
	int x, y, itx, ity;
	Ruutu alkuruutu = ruutu;
	x = ruutu.getRivi();
	y = ruutu.getSarake();
	itx = x + 1;
	ity = y + 1;
	while (itx < 8 && ity < 8 && itx >= 0 && ity >= 0) {
		if (asema._lauta[itx][ity] == nullptr) {
			Ruutu temp_ruutu(itx, ity);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[itx][ity]->getVari() != vari) {
				Ruutu temp_ruutu(itx, ity);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
				break;
			}
			else {
				break;
			}
		}
		itx = itx + 1;
		ity = ity + 1;

	}
	itx = x + 1;
	ity = y - 1;
	while (itx < 8 && ity < 8 && itx >= 0 && ity >= 0) {
		if (asema._lauta[itx][ity] == nullptr) {
			Ruutu temp_ruutu(itx, ity);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[itx][ity]->getVari() != vari) {
				Ruutu temp_ruutu(itx, ity);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
				break;
			}
			else {
				break;
			}
		}
		itx = itx + 1;
		ity = ity - 1;

	}
	itx = x - 1;
	ity = y + 1;
	while (itx < 8 && ity < 8 && itx >= 0 && ity >= 0) {
		if (asema._lauta[itx][ity] == nullptr) {
			Ruutu temp_ruutu(itx, ity);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[itx][ity]->getVari() != vari) {
				Ruutu temp_ruutu(itx, ity);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
				break;
			}
			else {
				break;
			}
		}
		itx = itx - 1;
		ity = ity + 1;
	}
	itx = x - 1;
	ity = y - 1;
	while (itx < 8 && ity < 8 && itx >= 0 && ity >= 0) {
		if (asema._lauta[itx][ity] == nullptr) {
			Ruutu temp_ruutu(itx, ity);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[itx][ity]->getVari() != vari) {
				Ruutu temp_ruutu(itx, ity);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
				break;
			}
			else {
				break;
			}
		}
		itx = itx - 1;
		ity = ity - 1;
	}
};

void Torni::annaSiirrot(std::list<Siirto>& lista, Ruutu& ruutu, Asema& asema, int vari) {
	Ruutu alkuRuutu = ruutu;
	//Asema* peliLauta = asema;
	int alkuRivi = ruutu.getRivi();
	int alkuSarake = ruutu.getSarake();

	//Ylöspäin checkaus
	for (int i = alkuRivi + 1; i < 8; i++) {
		if (asema._lauta[i][alkuSarake]) {
			if (asema._lauta[i][alkuSarake]->getVari() == vari) {
				break;
			}
			else {
				Ruutu loppuRuutu(i, alkuSarake);
				Siirto temp(alkuRuutu, loppuRuutu);
				lista.push_back(temp);
				break;
			}
		}
		else {
			Ruutu loppuRuutu(i, alkuSarake);
			Siirto temp(alkuRuutu, loppuRuutu);
			lista.push_back(temp);
		}
	}
	//Alaspäin checkaus
	for (int i = alkuRivi - 1; i > 0; i--) {
		if (asema._lauta[i][alkuSarake]) {
			if (asema._lauta[i][alkuSarake]->getVari() == vari) {
				break;
			}
			else {
				Ruutu loppuRuutu(i, alkuSarake);
				Siirto temp(alkuRuutu, loppuRuutu);
				lista.push_back(temp);
				break;
			}
		}
		else {
			Ruutu loppuRuutu(i, alkuSarake);
			Siirto temp(alkuRuutu, loppuRuutu);
			lista.push_back(temp);
		}
	}
	//Oikealle checkaus
	for (int i = alkuSarake + 1; i < 8; i++) {
		if (asema._lauta[alkuRivi][i]) {
			if (asema._lauta[alkuRivi][i]->getVari() == vari) {
				break;
			}
			else {
				Ruutu loppuRuutu(alkuRivi, i);
				Siirto temp(alkuRuutu, loppuRuutu);
				lista.push_back(temp);
				break;
			}
		}
		else {
			Ruutu loppuRuutu(alkuRivi, i);
			Siirto temp(alkuRuutu, loppuRuutu);
			lista.push_back(temp);
		}
	}
	//Vasemalle checkaus
	for (int i = alkuSarake - 1; i > 0; i--) {
		if (asema._lauta[alkuRivi][i]) {
			if (asema._lauta[alkuRivi][i]->getVari() == vari) {
				break;
			}
			else {
				Ruutu loppuRuutu(alkuRivi, i);
				Siirto temp(alkuRuutu, loppuRuutu);
				lista.push_back(temp);
				break;
			}
		}
		else {
			Ruutu loppuRuutu(alkuRivi, i);
			Siirto temp(alkuRuutu, loppuRuutu);
			lista.push_back(temp);
		}
	}
};

void Kuningas::annaSiirrot(std::list<Siirto>& lista, Ruutu& ruutu, Asema& asema, int vari) {
	int x, y;
	x = ruutu.getRivi();
	y = ruutu.getSarake();
	if (x + 1 < 8) {
		if (asema._lauta[x + 1][y] == nullptr) {
			Ruutu temp_ruutu(x + 1, y);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x + 1][y]->getVari() != vari) {
				Ruutu temp_ruutu(x + 1, y);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
	if (x + 1 < 8 && y + 1 < 8) {
		if (asema._lauta[x + 1][y + 1] == nullptr) {
			Ruutu temp_ruutu(x + 1, y + 1);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x + 1][y + 1]->getVari() != vari) {
				Ruutu temp_ruutu(x + 1, y + 1);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
	if (y + 1 < 8) {
		if (asema._lauta[x][y + 1] == nullptr) {
			Ruutu temp_ruutu(x, y + 1);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x][y + 1]->getVari() != vari) {
				Ruutu temp_ruutu(x, y + 1);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
	if (x - 1 >= 0) {
		if (asema._lauta[x - 1][y] == nullptr) {
			Ruutu temp_ruutu(x - 1, y);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x - 1][y]->getVari() != vari) {
				Ruutu temp_ruutu(x - 1, y);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
	if (y - 1 >= 0) {
		if (asema._lauta[x][y - 1] == nullptr) {
			Ruutu temp_ruutu(x, y - 1);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x][y - 1]->getVari() != vari) {
				Ruutu temp_ruutu(x, y - 1);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
	if (x - 1 >= 0 && y - 1 >= 0) {
		if (asema._lauta[x - 1][y - 1] == nullptr) {
			Ruutu temp_ruutu(x - 1, y - 1);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x - 1][y - 1]->getVari() != vari) {
				Ruutu temp_ruutu(x - 1, y - 1);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
	if (x + 1 < 8 && y - 1 >= 0) {
		if (asema._lauta[x + 1][y - 1] == nullptr) {
			Ruutu temp_ruutu(x + 1, y - 1);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x + 1][y - 1]->getVari() != vari) {
				Ruutu temp_ruutu(x + 1, y - 1);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
	if (x - 1 >= 0 && y + 1 < 8) {
		if (asema._lauta[x - 1][y + 1] == nullptr) {
			Ruutu temp_ruutu(x - 1, y + 1);
			Siirto temp_siirto(ruutu, temp_ruutu);
			lista.push_back(temp_siirto);
		}
		else {
			if (asema._lauta[x - 1][y + 1]->getVari() != vari) {
				Ruutu temp_ruutu(x - 1, y + 1);
				Siirto temp_siirto(ruutu, temp_ruutu);
				lista.push_back(temp_siirto);
			}
		}
	}
};

void Daami::annaSiirrot(std::list<Siirto>& lista, Ruutu& ruutu, Asema& asema, int vari) {
	this->Lahetti::annaSiirrot(lista, ruutu, asema, vari);
	this->Torni::annaSiirrot(lista, ruutu, asema, vari);
};

