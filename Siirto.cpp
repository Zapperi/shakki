#include "shakki.h"



Siirto::Siirto(Ruutu alku, Ruutu loppu) {
	_alkuRuutu = alku;
	_loppuRuutu = loppu;
	_pitkalinna = false;
	_lyhytLinna = false;
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
