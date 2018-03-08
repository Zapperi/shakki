#include "shakki.h"

//_.--~~SYVÄ AJATUS~~--._

wstring Vsotilas = L" \u2659 ";
wstring Vkuningas = L" \u2654 ";
wstring Vdaami = L" \u2655 ";
wstring Vtorni = L" \u2656 ";
wstring Vlahetti = L" \u2657 ";
wstring Vratsu = L" \u2658 ";
wstring Msotilas = L" \u265F ";
wstring Mkuningas = L" \u265A ";
wstring Mdaami = L" \u265B ";
wstring Mtorni = L" \u265C ";
wstring Mlahetti = L" \u265D ";
wstring Mratsu = L" \u265E ";
Nappula* Asema::vs = new Sotilas(Vsotilas, 0, VS);
Nappula* Asema::vk = new Kuningas(Vkuningas, 0, VK);
Nappula* Asema::vd = new Daami(Vdaami, 0, VD);
Nappula* Asema::vl = new Lahetti(Vlahetti, 0, VL);
Nappula* Asema::vt = new Torni(Vtorni, 0, VT);
Nappula* Asema::vr = new Ratsu(Vratsu, 0, VR);
Nappula* Asema::ms = new Sotilas(Msotilas, 1, MS);
Nappula* Asema::mk = new Kuningas(Mkuningas, 1, MK);
Nappula* Asema::md = new Daami(Mdaami, 1, MD);
Nappula* Asema::mt = new Torni(Mtorni, 1, MT);
Nappula* Asema::ml = new Lahetti(Mlahetti, 1, ML);
Nappula* Asema::mr = new Ratsu(Mratsu, 1, MR);

//_.--~~SYVÄ AJATUS~~--._


int main()
{
	string syote;
	bool peli_jatkuu = true;
	_setmode(_fileno(stdout), _O_U16TEXT);
	Kayttoliittyma liittyma;
	liittyma._asema->setSiirtovuoro(0);
	while (peli_jatkuu) {
		system("cls");
		liittyma.piirraLauta();
		//Debuggaus, tulostaa sen hetkisen siirtymälistan
		for (auto v : liittyma._asema->lista)
			wcout << "R:" << v.getLoppuruutu().getRivi() << " S:" << v.getLoppuruutu().getSarake() << L"\n";
		if (liittyma._asema->getSiirtovuoro() == 0) {
			wcout << L"valkoisen vuoro. Anna siirto: \n";
			getline(cin, syote);
			Siirto* uusisiirto = new Siirto(liittyma.kasittely(syote, 0));
			liittyma._asema->paivitaAsema(uusisiirto);
			delete uusisiirto;
			liittyma._asema->setSiirtovuoro(1);
		}
		else  {
			MinMaxPaluu paluu;
			if (liittyma._asema->getSiirtovuoro() == 0) {
				paluu = liittyma._asema->maxi(3);
			}
			else {
				paluu = liittyma._asema->mini(3); 
			}
			Siirto* uusisiirto = new Siirto(paluu.parasSiirto);
			liittyma._asema->paivitaAsema(uusisiirto);
			delete uusisiirto;
			liittyma._asema->setSiirtovuoro(0);
		}
	}
	return 0;
}
