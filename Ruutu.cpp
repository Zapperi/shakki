#include "shakki.h"


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
bool Ruutu::operator== (Ruutu& rhs) const {
	return (rhs.getRivi() == this->_rivi && rhs.getSarake() == this->_sarake);
}