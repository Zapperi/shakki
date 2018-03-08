#include"shakki.h"

//-----VÄLIAIKAISET FUNKTIOT JA KAIKKEE ROSKAA JA SÖPÖÖ PASKAA--------




//void LaillisetSiirrot::lisaaSotilaanKorotukset(Siirto* siirto, std::list<Siirto>& lista, Asema* asema) {
//	if (siirto->getLoppuruutu().getRivi() == 7) {
//		// valkea korottaa
//		siirto->miksikorotetaan = asema->vd;
//		lista.push_back(*siirto);
//
//		Siirto torniksi = *siirto;
//		torniksi.miksikorotetaan = asema->vt;
//		lista.push_back(torniksi);
//
//		Siirto lahetiksi = *siirto;
//		lahetiksi.miksikorotetaan = asema->vl;
//		lista.push_back(lahetiksi);
//
//		Siirto ratsuksi = *siirto;
//		ratsuksi.miksikorotetaan = asema->vr;
//		lista.push_back(ratsuksi);
//	}
//	else if (siirto->getLoppuruutu().getRivi() == 0) {
//		// musta korottaa
//		siirto->miksikorotetaan = asema->md;
//		lista.push_back(*siirto);
//
//		Siirto torniksi = *siirto;
//		torniksi.miksikorotetaan = asema->mt;
//		lista.push_back(torniksi);
//
//		Siirto lahetiksi = *siirto;
//		lahetiksi.miksikorotetaan = asema->ml;
//		lista.push_back(lahetiksi);
//
//		Siirto ratsuksi = *siirto;
//		ratsuksi.miksikorotetaan = asema->mr;
//		lista.push_back(ratsuksi);
//	}
//}