#include "shakki.h"


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
			//Tehd‰‰n Valkoisen lyhyt tornitus.
			_lauta[0][5] = _lauta[0][7];
			_lauta[0][7] = nullptr;
			_lauta[0][6] = _lauta[0][4];
			_lauta[0][4] = nullptr;
			_onkoValkeaKuningasLiikkunut = true;
			vkruutu.setRivi(0);
			vkruutu.setSarake(6);
		}
		else if (_siirtovuoro == 1 && !_onkoMustaKuningasLiikkunut && !_onkoMustaKTliikkunut) {
			//Tehd‰‰n mustan lyhyt tornitus.
			_lauta[7][5] = _lauta[7][7];
			_lauta[7][7] = nullptr;
			_lauta[7][6] = _lauta[7][4];
			_lauta[7][4] = nullptr;
			_onkoMustaKuningasLiikkunut = true;
			mkruutu.setRivi(7);
			mkruutu.setSarake(6);
		}
	}
	else if (siirto->onkoPitk‰linna()) {
		if (_siirtovuoro == 0 && !_onkoValkeaKuningasLiikkunut && !_onkoValkeaDTliikkunut) {
			//Tehd‰‰n Valkoisen pitk‰ tornitus.
			_lauta[0][3] = _lauta[0][0];
			_lauta[0][0] = nullptr;
			_lauta[0][2] = _lauta[0][4];
			_lauta[0][4] = nullptr;
			_onkoValkeaKuningasLiikkunut = true;
			vkruutu.setRivi(0);
			vkruutu.setSarake(2);
		}
		else if (_siirtovuoro == 1 && !_onkoMustaKuningasLiikkunut && !_onkoMustaDTliikkunut) {
			// Tehd‰‰n mustien pitk‰ tornitus.
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
	double _arvo = 0;
	double D_arvo = 9, T_arvo = 5, L_arvo = 3.5, R_arvo = 3, S_arvo = 1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			switch (_lauta[i][j]->getKoodi()) {
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
			if ((_lauta[i][j]->getKoodi() == VK && i + 1 < 8) || (_lauta[i][j]->getKoodi() == VK && i - 1 > 0)) {
				if (_lauta[i + 1][j]->getKoodi() == VT) {
					if (_vuorolkm < 11) {
						_arvo += 0.6;
					}
				}
				if (_lauta[i - 1][j]->getKoodi() == VT) {
					if (_vuorolkm < 11) {
						_arvo += 0.8;
					}
				}
			}
			if ((_lauta[i][j]->getKoodi() == MK && i + 1 < 8) || (_lauta[i][j]->getKoodi() == MK && i - 1 > 0)) {
				if (_lauta[i + 1][j]->getKoodi() == MT) {
					if (_vuorolkm < 11) {
						_arvo -= 0.6;
					}
				}
				if (_lauta[i - 1][j]->getKoodi() == MT) {
					if (_vuorolkm < 11) {
						_arvo -= 0.8;
					}
				}
			}
		}
	}

	return _arvo;

}

MinMaxPaluu Asema::minimax(int syvyys)
{
	MinMaxPaluu paluuarvo;


	// Rekursion kantatapaus 1: peli on loppu
	if (lista.size() == 0)
	{
		// *** TODO ***
		// tutki kumpi ja palauta sen mukainen arvo (tasapeli 0).
		paluuarvo.evaluointiArvo = 0;
		return paluuarvo;
	}

	// Rekursion kantatapaus 2: katkaisusyvyydess‰
	if (syvyys == 0)
	{
		paluuarvo.evaluointiArvo = evaluoi();
		return paluuarvo;
	}

	// Rekursioaskel: kokeillaan jokaista laillista siirtoa s
	// (alustetaan paluuarvo huonoimmaksi mahdolliseksi).
	paluuarvo.evaluointiArvo = (getSiirtovuoro() == 0 ? -1000000 : 100000);
	for (auto s : lista)
	{
		// Seuraaja-asema (tehd‰‰n nykyisess‰ asemassa siirto s).
		Asema uusi_asema = *this;
		uusi_asema.paivitaAsema(&s);

		// Rekursiivinen kutsu.
		MinMaxPaluu arvo = uusi_asema.minimax(syvyys - 1);

		// Tutkitaan ollaan lˆydetty uusi paras siirto.
		if
			(
			(getSiirtovuoro() == 0 && arvo.evaluointiArvo > paluuarvo.evaluointiArvo) ||
				(getSiirtovuoro() == 1 && arvo.evaluointiArvo < paluuarvo.evaluointiArvo)
				)
		{
			// Lˆydettiin uusi paras siirto.
			paluuarvo.evaluointiArvo = arvo.evaluointiArvo;
			paluuarvo.parasSiirto = arvo.parasSiirto;
		}
	}
	return paluuarvo;
}

MinMaxPaluu Asema::maxi(int syvyys) {
	Ruutu kuninkaanRuutu;
	double arvo;
	Asema uusiAsema;
	Siirto parasSiirto;
	MinMaxPaluu paluu;
	// Tarkasta onko matti tai patti, jos on niin poistu asap, matti -100000, patti 0
	if (lista.size() == 0) {
		//selvit‰ kuninkaan ruutu
		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				if (this->_lauta[x][y] != NULL) {
					if (this->_lauta[x][y]->getKoodi() == VK) {
						kuninkaanRuutu.setSarake(x);
						kuninkaanRuutu.setRivi(y);
					}
				}
			}
		}
		//matti
		if (this->onkoRuutuTurvallinen(&kuninkaanRuutu, 1)) {
			paluu.evaluointiArvo = -1000000;
			return paluu;
		}
		//patti
		if (!this->onkoRuutuTurvallinen(&kuninkaanRuutu, 1)) {
			paluu.evaluointiArvo = 0;
			return paluu;
		}
	}
	// Jos ei ole matti tai patti niin k‰y pelipuuta l‰pi rekursiivisesti
	if (syvyys == 0) { // rekursion kanta
		paluu.evaluointiArvo = this->evaluoi();
		return 	paluu;
	}
	double maximi = -100000; // iso arvo jotta varmasti paranee
	for (auto s : lista) {
		uusiAsema = *this;
		uusiAsema.paivitaAsema(&s);
		arvo = uusiAsema.mini(syvyys - 1).evaluointiArvo;
		if (arvo > maximi) {
			maximi = arvo;
			parasSiirto = s;
		}
	}
	paluu.evaluointiArvo = maximi;
	paluu.parasSiirto = parasSiirto;
	return paluu;
}

MinMaxPaluu Asema::mini(int syvyys) {
	std::list<Siirto> lista;
	Ruutu kuninkaanRuutu;
	this->annaLaillisetSiirrot(lista);
	double arvo;
	Asema uusiAsema;
	Siirto parasSiirto;
	MinMaxPaluu paluu;
	// Tarkasta onko matti tai patti, jos on niin poistu asap, matti -100000, patti 0
	if (lista.size() == 0) {
		//selvit‰ kuninkaan ruutu
		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				if (this->_lauta[x][y] != NULL) {
					if (this->_lauta[x][y]->getKoodi() == MK) {
						kuninkaanRuutu.setSarake(x);
						kuninkaanRuutu.setRivi(y);
					}
				}
			}
		}
		//matti
		if (this->onkoRuutuTurvallinen(&kuninkaanRuutu, 0)) {
			paluu.evaluointiArvo = 1000000;
			return paluu;
		}
		//patti
		if (!this->onkoRuutuTurvallinen(&kuninkaanRuutu, 0)) {
			paluu.evaluointiArvo = 0;
			return paluu;
		}
	}
	// Jos ei ole matti tai patti niin k‰y pelipuuta l‰pi rekursiivisesti
	if (syvyys == 0) { // rekursion kanta
		paluu.evaluointiArvo = this->evaluoi();
		//paluu.parasSiirto = MITƒ
		return 	paluu;
	}
	double minimi = 100000; // iso arvo jotta varmasti paranee
	for (auto s : lista) {
		uusiAsema = *this;
		uusiAsema.paivitaAsema(&s);
		arvo = uusiAsema.maxi(syvyys - 1).evaluointiArvo;
		if (arvo < minimi) {
			minimi = arvo;
			parasSiirto = s;
		}
	}
	paluu.evaluointiArvo = minimi;
	paluu.parasSiirto = parasSiirto;
	return paluu;
}

void Asema::annaLaillisetSiirrot(list<Siirto>& lista) {
	int vari = this->getSiirtovuoro();

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//Ei kysele tyhjilt‰ ruuduilta nappulan nime‰
			if (this->_lauta[i][j] == nullptr) {
				continue;
			}
			if (this->_lauta[i][j]->getVari() != vari) {
				continue;
			}
			this->_lauta[i][j]->annaSiirrot(lista, Ruutu(i, j), *this, vari); // myˆh‰inen sidonta!
		}
	}
	//Lis‰t‰‰n listaan tornituksien liikkeet
	if (vari == 0) {
		//valkean lyhyt linna
		if (!this->getOnkoValkeaKuningasLiikkunut() && !this->getOnkoValkeaKTliikkunut()
			&& onkoRuutuTurvallinen(this, &Ruutu(4, 0), !vari)
			&& onkoRuutuTurvallinen(this, &Ruutu(5, 0), !vari) && onkoRuutuTurvallinen(this, &Ruutu(6, 0), !vari)
			&& this->_lauta[5][0] == NULL && this->_lauta[6][0] == NULL) {
			//p‰ivitet‰‰n listaan lyhytlinna
			lista.push_back(Siirto(true, false)); // lis‰t‰‰n listaan lyhyt linna
		}
		//valkean pitk‰ linna
		if (!this->getOnkoValkeaKuningasLiikkunut() && !this->getOnkoValkeaDTliikkunut()
			&& onkoRuutuTurvallinen(this, &Ruutu(4, 0), !vari)
			&& onkoRuutuTurvallinen(this, &Ruutu(3, 0), !vari) && onkoRuutuTurvallinen(this, &Ruutu(3, 0), !vari)
			&& this->_lauta[3][0] == NULL && this->_lauta[2][0] == NULL) {
			//p‰ivitet‰‰n listaan lyhytlinna
			lista.push_back(Siirto(false, true)); // lis‰t‰‰n listaan lyhyt linna
		}
	}
	else{
		//mustan lyhyt linna
		if (!this->getOnkoMustaKuningasLiikkunut() && !this->getOnkoMustaKTliikkunut()
			&& onkoRuutuTurvallinen(this, &Ruutu(4, 7), !vari)
			&& onkoRuutuTurvallinen(this, &Ruutu(5, 7), !vari) && onkoRuutuTurvallinen(this, &Ruutu(6, 7), !vari)
			&& this->_lauta[5][7] == NULL && this->_lauta[6][7] == NULL) {
			//p‰ivitet‰‰n listaan lyhytlinna
			lista.push_back(Siirto(true, false)); // lis‰t‰‰n listaan lyhyt linna
		}
		//mustan pitk‰ linna
		if (!this->getOnkoMustaKuningasLiikkunut() && !this->getOnkoMustaDTliikkunut()
			&& onkoRuutuTurvallinen(this, &Ruutu(4, 7), !vari)
			&& onkoRuutuTurvallinen(this, &Ruutu(3, 7), !vari) && onkoRuutuTurvallinen(this, &Ruutu(2, 7), !vari)
			&& this->_lauta[3][7] == NULL && this->_lauta[2][7] == NULL) {
			//p‰ivitet‰‰n listaan lyhytlinna
			lista.push_back(Siirto(false, true)); // lis‰t‰‰n listaan lyhyt linna
		}
	}

}

void lisaaSotilaanKorotukset(Siirto* siirto, list<Siirto>& lista, Asema* asema) {
	if (siirto->getLoppuruutu().getRivi() == 7) {
		// valkea korottaa
		siirto->_nappulanKorotus = asema->vd;
		lista.push_back(*siirto);

		Siirto torniksi = *siirto;
		torniksi._nappulanKorotus = asema->vt;
		lista.push_back(torniksi);

		Siirto lahetiksi = *siirto;
		lahetiksi._nappulanKorotus = asema->vl;
		lista.push_back(lahetiksi);

		Siirto ratsuksi = *siirto;
		ratsuksi._nappulanKorotus = asema->vr;
		lista.push_back(ratsuksi);
	}
	else if (siirto->getLoppuruutu().getRivi() == 0) {
		// musta korottaa
		siirto->_nappulanKorotus = asema->md;
		lista.push_back(*siirto);

		Siirto torniksi = *siirto;
		torniksi._nappulanKorotus = asema->mt;
		lista.push_back(torniksi);

		Siirto lahetiksi = *siirto;
		lahetiksi._nappulanKorotus = asema->ml;
		lista.push_back(lahetiksi);

		Siirto ratsuksi = *siirto;
		ratsuksi._nappulanKorotus = asema->mr;
		lista.push_back(ratsuksi);
	}
}

bool Asema::onkoRuutuTurvallinen(Asema *tempAsema, Ruutu* kunkkuRuutu, int vastustajanVari) {
	list<Siirto> vastustajanSiirrot;
	//V‰reitt‰in k‰yd‰‰n l‰pi kaikki ruudut ja niiss‰ olevan nappulan siirrot ker‰t‰‰n vastustajan siirtolistaan
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tempAsema->_lauta[i][j] == NULL) {
				continue;
			}
			if (tempAsema->_lauta[i][j]->getVari() == vastustajanVari)
				tempAsema->_lauta[i][j]->annaSiirrot(vastustajanSiirrot, Ruutu(i, j), *tempAsema, vastustajanVari);
		}
	}
	// Katsoo onko lis‰tyiss‰ siirroissa ruutu jossa sijaitsee kuningas.
	bool ruutuOk = true;
	for (auto vsiirto : vastustajanSiirrot)
	{
		if (kunkkuRuutu->getSarake() == vsiirto.getLoppuruutu().getSarake() && kunkkuRuutu->getRivi() == vsiirto.getLoppuruutu().getRivi()) {
			ruutuOk = false;
			break;
		}
	}
	return ruutuOk;
}

bool Asema::onkoRuutuTurvallinen(Ruutu* kunkkuRuutu, int vastustajanVari) {
	list<Siirto> vastustajanSiirrot;
	//V‰reitt‰in k‰yd‰‰n l‰pi kaikki ruudut ja niiss‰ olevan nappulan siirrot ker‰t‰‰n vastustajan siirtolistaan
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->_lauta[i][j] == NULL) {
				continue;
			}
			if (this->_lauta[i][j]->getVari() == vastustajanVari)
				this->_lauta[i][j]->annaSiirrot(vastustajanSiirrot, Ruutu(i, j), *this, vastustajanVari);
		}
	}
	// Katsoo onko lis‰tyiss‰ siirroissa ruutu jossa sijaitsee kuningas.
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
	Asema tempAsema;
	if (pelaajaVari == 0) {
		for (auto siirto : lista) {
			//luodaan testiasema, jossa tehd‰‰n siirto ja tarkistetaan mahd. vaara shakkitilanne.
			tempAsema = *this;
			tempAsema.paivitaAsema(&siirto);
			//Jos pelaaja on valkoinen (0), k‰y l‰pi onko kuninkaan ruutu uhattu.
			if (tempAsema.onkoRuutuTurvallinen(&tempAsema, &tempAsema.vkruutu, 1))
				tempList.push_back(siirto);
		}
	}
	else {
		for (auto siirto : lista) {
			tempAsema = *this;
			tempAsema.paivitaAsema(&siirto);
			if (tempAsema.onkoRuutuTurvallinen(&tempAsema, &tempAsema.mkruutu, 0))
				tempList.push_back(siirto);
		}
	}
	lista.clear();
	lista = tempList;
}