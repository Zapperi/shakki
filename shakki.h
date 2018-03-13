#pragma once
#include<iostream>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <String>
#include <list>

//_.--~~SYVÄ AJATUS~~--._

using namespace std;
enum
{
	VT, VR, VL, VD, VK, VS,
	MT, MR, ML, MD, MK, MS
};

class Asema;
class MinMaxPaluu;
class Nappula;

class Ruutu {
public:
	Ruutu(int rivi, int sarake);
	Ruutu() {}
	~Ruutu() {}
	int getRivi();
	int getSarake();
	void setRivi(int rivi);
	void setSarake(int sarake);
	bool operator== (Ruutu& rhs)const;
private:
	int _sarake;
	int _rivi;
};

class Siirto {
public:
	Siirto(Ruutu alku, Ruutu loppu);
	Siirto() {}
	Siirto(bool lyhytLinna, bool pitkaLinna); // Poikkeussiirto linnoitusta varten
	Ruutu getAlkuruutu();
	Ruutu getLoppuruutu();
	bool onkoLyhytLinna();
	bool onkoPitkälinna();
	Nappula* _nappulanKorotus = 0;
private:
	Ruutu _alkuRuutu;
	Ruutu _loppuRuutu;
	bool _lyhytLinna = false;
	bool _pitkalinna = false;
};

class Nappula {

private:
	wstring unicode;
	int _vari; // valkea = 0, musta = 1
	int _koodi; // VT, VR, MT tms.
public:
	virtual void annaSiirrot(std::list<Siirto>& lista, Ruutu& ruutu, Asema& asema, int vari) = 0;
	bool Onkoliikutettu = false;
	Nappula(std::wstring, int, int);
	Nappula() {};
	void setKoodi(int);
	int getKoodi();
	void setUnicode(std::wstring);
	wstring getUnicode();
	void setVari(int);
	int getVari();
};

class Sotilas : public Nappula {
	using Nappula::Nappula;
	
	
private:
	
public:
	void annaSiirrot(std::list<Siirto>& lista, Ruutu& ruutu, Asema& asema, int vari);
};

class Ratsu : public Nappula {
	using Nappula::Nappula;
public:
	void annaSiirrot(std::list<Siirto>& lista, Ruutu& ruutu, Asema& asema, int vari);
};

class Lahetti : public Nappula {
	using Nappula::Nappula;
public:
	void annaSiirrot(std::list<Siirto>& lista, Ruutu& ruutu, Asema& asema, int vari);
};

class Torni : public Nappula {
	using Nappula::Nappula;
public:
	void annaSiirrot(std::list<Siirto>& lista, Ruutu& ruutu, Asema& asema, int vari);
};

class Kuningas : public Nappula {
	using Nappula::Nappula;
public:
	void annaSiirrot(std::list<Siirto>& lista, Ruutu& ruutu, Asema& asema, int vari);
};

class Daami : public Lahetti, public Torni, public Nappula {
	using Nappula::Nappula;
public:
	void annaSiirrot(std::list<Siirto>& lista, Ruutu& ruutu, Asema& asema, int vari);
};

class Asema {
public:
	static Nappula* vs;
	static Nappula* vd;
	static Nappula* vk;
	static Nappula* vl;
	static Nappula* vt;
	static Nappula* vr;
	static Nappula* ms;
	static Nappula* mk;
	static Nappula* md;
	static Nappula* ml;
	static Nappula* mt;
	static Nappula* mr;
	Asema();
	Nappula* _lauta[8][8];
	list<Siirto> lista;
	void paivitaAsema(Siirto* siirto);
	int getSiirtovuoro();
	void setSiirtovuoro(int vari);
	bool getOnkoValkeaKuningasLiikkunut();
	bool getOnkoMustaKuningasLiikkunut();
	bool getOnkoValkeaDTliikkunut();
	bool getOnkoValkeaKTliikkunut();
	bool getOnkoMustaDTliikkunut();
	bool getOnkoMustaKTliikkunut();
	Ruutu vkruutu;
	Ruutu mkruutu;
	void annaLaillisetSiirrot(list<Siirto>& lista);
	void lisaaSotilaanKorotukset(Siirto* siirto, list<Siirto>& lista, Asema* asema);
	bool onkoRuutuTurvallinen(Ruutu* kunkkuRuutu, int vastustajanVari);
	bool onkoRuutuTurvallinen(Asema *tempAsema, Ruutu* kunkkuRuutu, int vastustajanVari);
	void listanSiivous(list<Siirto>& lista, int vari);
	int _ohestaLyontiSarake = -1;
	double evaluoi();
	MinMaxPaluu maxi(int syvyys);
	MinMaxPaluu mini(int syvyys);
	MinMaxPaluu minimax(int syvyys);

private:
	int _siirtovuoro;
	int _vuorolkm;
	bool _onkoValkeaKuningasLiikkunut = false;
	bool _onkoMustaKuningasLiikkunut = false;
	bool _onkoValkeaDTliikkunut = false;
	bool _onkoValkeaKTliikkunut = false;
	bool _onkoMustaDTliikkunut = false;
	bool _onkoMustaKTliikkunut = false;
};

class Kayttoliittyma {

public:
	Kayttoliittyma(Asema* asema);
	Kayttoliittyma();
	Asema* _asema;
	void piirraLauta();
	Siirto annaVastustajanSiirto(Siirto siirto);
	Siirto kasittely(string syote, int vari);
};

class MinMaxPaluu {
public:
	double evaluointiArvo;
	Siirto parasSiirto;
};



