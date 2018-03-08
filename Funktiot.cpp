#include<iostream>
#include <Windows.h>
#include"shakki.h"

//_.--~~SYVÄ AJATUS~~--._


// ---Nappula Classin toteutus--------
Nappula::Nappula(wstring unikoodi, int color, int koodi) {
	unicode = unikoodi;
	_vari = color;
	_koodi = koodi;
}

// jee
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
		if (asema._lauta[alkuRivi + 1][alkuSarake] == nullptr  && alkuRivi +1 < 8) {
			Ruutu loppuRuutu(alkuRivi + 1, alkuSarake);
			Siirto temp(ruutu, loppuRuutu);
			lista.push_back(temp);
		}if (asema._lauta[alkuRivi + 1][alkuSarake - 1] != nullptr && asema._lauta[alkuRivi + 1][alkuSarake - 1]->getVari() == 1) {
			Ruutu loppuRuutu(alkuRivi + 1, alkuSarake -1);
			Siirto temp(ruutu, loppuRuutu);
			lista.push_back(temp);
		}if (asema._lauta[alkuRivi + 1][alkuSarake + 1] != nullptr && asema._lauta[alkuRivi + 1][alkuSarake + 1]->getVari() == 1) {
			Ruutu loppuRuutu(alkuRivi + 1, alkuSarake + 1);
			Siirto temp(ruutu, loppuRuutu);
			lista.push_back(temp);
		}
		if (!Onkoliikutettu && asema._lauta[alkuRivi + 2][alkuSarake] == nullptr && asema._lauta[alkuRivi + 1][alkuSarake] == nullptr) {
			Ruutu loppuRuutu(alkuRivi + 2, alkuSarake);
			Siirto temp(ruutu, loppuRuutu);
			lista.push_back(temp);
		}
		if (alkuRivi == 4 && asema._ohestaLyontiSarake +1 == alkuSarake || asema._ohestaLyontiSarake -1 == alkuSarake) {
			if (asema._ohestaLyontiSarake +1 == alkuSarake) {
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
	else if (vari == 0) {
		if (asema._lauta[alkuRivi - 1][alkuSarake] == nullptr  && alkuRivi - 1> 0) {
			Ruutu loppuRuutu(alkuRivi - 1, alkuSarake);
			Siirto temp(ruutu, loppuRuutu);
			lista.push_back(temp);
		}if (asema._lauta[alkuRivi - 1][alkuSarake - 1] != nullptr && asema._lauta[alkuRivi - 1][alkuSarake - 1]->getVari() == 0) {
			Ruutu loppuRuutu(alkuRivi - 1, alkuSarake - 1);
			Siirto temp(ruutu, loppuRuutu);
			lista.push_back(temp);
		}if (asema._lauta[alkuRivi - 1][alkuSarake + 1] != nullptr && asema._lauta[alkuRivi - 1][alkuSarake + 1]->getVari() == 0) {
			Ruutu loppuRuutu(alkuRivi - 1, alkuSarake + 1);
			Siirto temp(ruutu, loppuRuutu);
			lista.push_back(temp);
		}
		if (!Onkoliikutettu && asema._lauta[alkuRivi -2][alkuSarake] == nullptr && asema._lauta[alkuRivi - 1][alkuSarake] == nullptr) {
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

//----- Nappula classi loppuu------

//-----Asema Classi toteutus alkaa------
Asema::Asema() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			_lauta[i][j] = nullptr;
	_lauta[0][0] = vt; _lauta[0][1] = vr; _lauta[0][2] = vl; _lauta[0][3] = vd; _lauta[0][4] = vk; _lauta[0][5] = vl; _lauta[0][6] = vr; _lauta[0][7] = vt;
	_lauta[1][0] = vs; _lauta[1][1] = vs; _lauta[1][2] = vs; _lauta[1][3] = vs; _lauta[1][4] = vs; _lauta[1][5] = vs; _lauta[1][6] = vs; _lauta[1][7] = vs;
	_lauta[6][0] = ms; _lauta[6][1] = ms; _lauta[6][2] = ms; _lauta[6][3] = ms; _lauta[6][4] = ms; _lauta[6][5] = ms; _lauta[6][6] = ms; _lauta[6][7] = ms;
	_lauta[7][0] = mt; _lauta[7][1] = mr; _lauta[7][2] = ml; _lauta[7][3] = md; _lauta[7][4] = mk; _lauta[7][5] = ml; _lauta[7][6] = mr; _lauta[7][7] = mt;
	vkruutu.setRivi(0);
	vkruutu.setSarake(4);
	mkruutu.setRivi(7);
	mkruutu.setSarake(4);
}

void Asema::paivitaAsema(Siirto* siirto) {


	if (siirto->onkoLyhytLinna()) {
		if (_siirtovuoro == 0 && !_onkoValkeaKuningasLiikkunut && !_onkoValkeaKTliikkunut) {
			//Tehdään Valkoisen lyhyt tornitus.
			_lauta[0][5] = _lauta[0][7];
			_lauta[0][7] = nullptr;
			_lauta[0][6] = _lauta[0][4];
			_lauta[0][4] = nullptr;
			_onkoValkeaKuningasLiikkunut = true;
			vkruutu.setRivi(0);
			vkruutu.setSarake(6);
		}
		else if (_siirtovuoro == 1 && !_onkoMustaKuningasLiikkunut && !_onkoMustaKTliikkunut) {
			//Tehdään mustan lyhyt tornitus.
			_lauta[7][5] = _lauta[7][7];
			_lauta[7][7] = nullptr;
			_lauta[7][6] = _lauta[7][4];
			_lauta[7][4] = nullptr;
			_onkoMustaKuningasLiikkunut = true;
			mkruutu.setRivi(7);
			mkruutu.setSarake(6);
		}
	}
	else if (siirto->onkoPitkälinna()) {
		if (_siirtovuoro == 0 && !_onkoValkeaKuningasLiikkunut && !_onkoValkeaDTliikkunut) {
			//Tehdään Valkoisen pitkä tornitus.
			_lauta[0][3] = _lauta[0][0];
			_lauta[0][0] = nullptr;
			_lauta[0][2] = _lauta[0][4];
			_lauta[0][4] = nullptr;
			_onkoValkeaKuningasLiikkunut = true;
			vkruutu.setRivi(0);
			vkruutu.setSarake(2);
		}
		else if (_siirtovuoro == 1 && !_onkoMustaKuningasLiikkunut && !_onkoMustaDTliikkunut) {
			// Tehdään mustien pitkä tornitus.
			_lauta[7][3] = _lauta[7][0];
			_lauta[7][0] = nullptr;
			_lauta[7][2] = _lauta[7][4];
			_lauta[7][4] = nullptr;
			_onkoMustaKuningasLiikkunut = true;
			mkruutu.setRivi(7);
			mkruutu.setSarake(2);
		}
	}
	else {
		Ruutu ekaruutu = siirto->getAlkuruutu();
		Ruutu tokaruutu = siirto->getLoppuruutu();

		if (ekaruutu.getRivi() == 0 && ekaruutu.getSarake() == 0 || tokaruutu.getRivi() == 0 && tokaruutu.getSarake() == 0) {
			_onkoValkeaDTliikkunut = true;

		}
		if (ekaruutu.getRivi() == 0 && ekaruutu.getSarake() == 7 || tokaruutu.getRivi() == 0 && tokaruutu.getSarake() == 7) {
			_onkoValkeaKTliikkunut = true;

		}
		if (ekaruutu.getRivi() == 0 && ekaruutu.getSarake() == 4 || tokaruutu.getRivi() == 0 && tokaruutu.getSarake() == 4) {
			_onkoValkeaKuningasLiikkunut = true;

		}
		if (ekaruutu.getRivi() == 7 && ekaruutu.getSarake() == 0 || tokaruutu.getRivi() == 7 && tokaruutu.getSarake() == 0) {
			_onkoMustaDTliikkunut = true;

		}
		if (ekaruutu.getRivi() == 7 && ekaruutu.getSarake() == 7 || tokaruutu.getRivi() == 7 && tokaruutu.getSarake() == 7) {
			_onkoMustaKTliikkunut = true;

		}
		if (ekaruutu.getRivi() == 7 && ekaruutu.getSarake() == 4 || tokaruutu.getRivi() == 7 && tokaruutu.getSarake() == 4) {
			_onkoMustaKuningasLiikkunut = true;

		}

		Nappula* siirettava = _lauta[ekaruutu.getRivi()][ekaruutu.getSarake()];
		_lauta[tokaruutu.getRivi()][tokaruutu.getSarake()] = siirettava;
		_lauta[ekaruutu.getRivi()][ekaruutu.getSarake()] = nullptr;
	}
};

int Asema::getSiirtovuoro() {
	return _siirtovuoro;
};
void Asema::setSiirtovuoro(int vari) {
	this->_siirtovuoro = vari;
};
bool Asema::getOnkoValkeaKuningasLiikkunut() {
	return _onkoValkeaKuningasLiikkunut;
};
bool Asema::getOnkoMustaKuningasLiikkunut() {
	return _onkoMustaKuningasLiikkunut;
};
bool Asema::getOnkoValkeaDTliikkunut() {
	return _onkoValkeaDTliikkunut;
};
bool Asema::getOnkoValkeaKTliikkunut() {
	return _onkoValkeaKTliikkunut;
};
bool Asema::getOnkoMustaDTliikkunut() {
	return _onkoMustaDTliikkunut;
};
bool Asema::getOnkoMustaKTliikkunut() {
	return _onkoMustaKTliikkunut;
};

double Asema::evaluoi() {
	double _arvo = arvo;
	double D_arvo = 9, T_arvo = 5, L_arvo = 3.5, R_arvo = 3, S_arvo = 1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			switch (_lauta[i][j]->getKoodi) {
			case VS:
				_arvo += S_arvo;
			case VR:
				_arvo += R_arvo;
			case VL:
				_arvo += L_arvo;
			case VT:
				_arvo += T_arvo;
			case VD:
				_arvo += D_arvo;
			case MS:
				_arvo -= S_arvo;
			case MR:
				_arvo -= R_arvo;
			case ML:
				_arvo -= L_arvo;
			case MT:
				_arvo -= T_arvo;
			case MD:
				_arvo -= D_arvo;
				break;
			}
			if ((_lauta[i][j]->getKoodi == VK && i + 1 < 8) || (_lauta[i][j]->getKoodi == VK && i - 1 > 0)) {
				if (_lauta[i + 1][j]->getKoodi == VT) {
					if (_vuorolkm < 11) {
						_arvo += 0.6;
					}
				}
				if (_lauta[i - 1][j]->getKoodi == VT) {
					if (_vuorolkm < 11) {
						_arvo += 0.8;
					}
				}
			}
			if ((_lauta[i][j]->getKoodi == MK && i + 1 < 8) || (_lauta[i][j]->getKoodi == MK && i - 1 > 0)) {
				if (_lauta[i + 1][j]->getKoodi == MT) {
					if (_vuorolkm < 11) {
						_arvo -= 0.6;
					}
				}
				if (_lauta[i - 1][j]->getKoodi == MT) {
					if (_vuorolkm < 11) {
						_arvo -= 0.8;
					}
				}
			}
		}
	}

	return _arvo;

}
//double Asema::maxi(int syvyys, Asema a) {
//	if (syvyys == 0) return evaluoi();
//	int max = -oo;
//	for (a.lista) {
//		arvo = mini(syvyys - 1);
//		if (arvo > max)
//			max = arvo;
//	}
//	return max;
//}
//double Asema::mini(int syvyys, Asema a) {
//	if (syvyys == 0) return evaluoi();
//	int min = +oo;
//	for (a.lista) {
//		arvo = maxi(syvyys - 1);
//		if (arvo < min)
//			min = arvo;
//	}
//	return min;
//}

void Asema::annaLaillisetSiirrot(list<Siirto>& lista) {
	int vari = this->getSiirtovuoro();

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//Ei kysele tyhjiltä ruuduilta nappulan nimeä
			if (this->_lauta[i][j] == nullptr) {
				continue;
			}
			if (this->_lauta[i][j]->getVari() != vari) {
				continue;
			}
			this->_lauta[i][j]->annaSiirrot(lista, Ruutu(i, j), *this, vari); // myöhäinen sidonta!
		}
	}
	
}

bool Asema::onkoRuutuTurvallinen(Ruutu* kunkkuRuutu, int vastustajanVari) {
	std::list<Siirto> vastustajanSiirrot;
	//Väreittäin käydään läpi kaikki ruudut ja niissä olevan nappulan siirrot kerätään vastustajan siirtolistaan
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->_lauta[i][j] == NULL) {
				continue;
			}
			if (this->_lauta[i][j]->getVari() == vastustajanVari)
				this->_lauta[i][j]->annaSiirrot(vastustajanSiirrot, Ruutu(i, j), *this, vastustajanVari);
		}
	}
	// Katsoo onko lisätyissä siirroissa ruutu jossa sijaitsee kuningas.
	bool ruutuOk = true;
	for (auto siirto : vastustajanSiirrot)
	{
		if (kunkkuRuutu->getSarake() == siirto.getLoppuruutu().getSarake() && kunkkuRuutu->getRivi() == siirto.getLoppuruutu().getRivi()) {
			ruutuOk = false;
			break;
		}
	}
	return ruutuOk;
}

void Asema::listanSiivous(list<Siirto>& lista, int pelaajaVari) {
	list<Siirto> tempList;
	if (pelaajaVari == 0) {
		for (auto siirto : lista) {
			if (this->onkoRuutuTurvallinen(&this->vkruutu, 1) == true)
				tempList.push_back(siirto);
		}
	}
	else {
		for (auto siirto : lista) {
			if (this->onkoRuutuTurvallinen(&this->mkruutu, 0) == true)
				tempList.push_back(siirto);
		}
	}
	lista = tempList;
}

//------Asema classi toteutus loppuu-----

//------Kayttoliittyma classi toteutus alkaa------
Kayttoliittyma::Kayttoliittyma(Asema* asema) {
	_asema = asema;
}

Kayttoliittyma::Kayttoliittyma() {
	_asema = new Asema();
}

void Kayttoliittyma::piirraLauta() {
	for (int i = 7; i >= 0; i--) {
		//Lisätään numerot vasempaan laitaan
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN);
		wcout << i +1;
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
	char* kirjaimet[] = { " "," A ", " B ", " C "," D "," E "," F "," G "," H "};
	for (int i = 0; i < 9; i++) {
		wcout << kirjaimet[i];
	}
	wcout << endl;
};
 
//------Kayttoliittyma classi toteutus loppuu------

//------Ruutu classi toteutus alkaa------
Ruutu::Ruutu(int rivi, int sarake) {
	_rivi = rivi;
	_sarake = sarake;
}

//Ruutu::Ruutu() {
//}
void Ruutu::setRivi(int rivi) {
	_rivi = rivi;
}
void Ruutu::setSarake(int sarake) {
	_sarake = sarake;
}
int Ruutu::getRivi() {
	return this->_rivi;
}
int Ruutu::getSarake() {
	return this->_sarake;
}
bool Ruutu::operator== (Ruutu& rhs) const{
	return (rhs.getRivi() == this->_rivi && rhs.getSarake() == this->_sarake);
}
//------Ruutu classi toteutus loppuu------


//-----Siirto classi toteutus alkaa-----
//Siirto::Siirto() {}
Siirto::Siirto(Ruutu alku, Ruutu loppu) {
	_alkuRuutu = alku;
	_loppuRuutu = loppu;
};

// Poikkeussiirto linnoitusta varten
Siirto::Siirto(bool lyhytLinna, bool pitkaLinna) {
	if (lyhytLinna)
		_lyhytLinna = true;
	if (pitkaLinna)
		_pitkalinna = true;
};
Ruutu Siirto::getAlkuruutu() {
	return _alkuRuutu;
};
Ruutu Siirto::getLoppuruutu() {
	return _loppuRuutu;
};
bool Siirto::onkoLyhytLinna() {
	if (_lyhytLinna)
		return true;
	else
		return false;
};
bool Siirto::onkoPitkälinna() {
	if (_pitkalinna)
		return true;
	else
		return false;
};

//-----Siirto classi loppuu-----------

Siirto Kayttoliittyma::kasittely(string syote, int vari) {
	//Saa syötteen muodossa esim ( S1a-3a  )
	int alkurivi, alkusarake, loppurivi, loppusarake;
	char nappulanMerkki; //<-- muutetaan myöhemmin
	nappulanMerkki = syote[0]; // <-- Ei vielä käytetä mihinkään

	if (syote == "O-O" || syote == "o-o") {
		Siirto siirto(true, false);
		return siirto;
	}
	else if (syote == "O-O-O" || syote == "o-o-o") {
		Siirto siirto(false, true);
		return siirto;
	}
	else {

		//Selvitetään alkuruudun koordinaatit
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
			wcout << L"No et osannut..";
		}
		//Selvitetään loppuruudun koordinaatit
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
			wcout << L"No et osannut..";
		}
		Ruutu alkuruutu(alkurivi, alkusarake);
		Ruutu loppuruutu(loppurivi, loppusarake);
		_asema->lista.clear();
		//_asema->_lauta[alkurivi][alkusarake]->annaSiirrot(_asema->lista,alkuruutu, *_asema, vari);
		_asema->annaLaillisetSiirrot(_asema->lista);
		_asema->listanSiivous(_asema->lista, vari);
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
		return siirto;
	}
}
//Siirto Kayttoliittyma::annaVastustajanSiirto(Siirto siirto) {
//
//};