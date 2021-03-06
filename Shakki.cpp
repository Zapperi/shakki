#include "shakki.h"

//_.--~~SYVÄ AJATUS~~--._

wstring Vsotilas = L" \u2659";
wstring Vkuningas = L" \u2654";
wstring Vdaami = L" \u2655";
wstring Vtorni = L" \u2656";
wstring Vlahetti = L" \u2657";
wstring Vratsu = L" \u2658";
wstring Msotilas = L" \u265F";
wstring Mkuningas = L" \u265A";
wstring Mdaami = L" \u265B";
wstring Mtorni = L" \u265C";
wstring Mlahetti = L" \u265D";
wstring Mratsu = L" \u265E";
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
	liittyma.annaVastustajanVari();
	liittyma.piirraLauta();
	while (peli_jatkuu) {	
		//Debuggaus, tulostaa sen hetkisen siirtymälistan
		/*for (auto v : liittyma._asema->lista)
			wcout << "R:" << v.getLoppuruutu().getRivi() << " S:" << v.getLoppuruutu().getSarake() << L"\n";*/
		if (liittyma._asema->getSiirtovuoro() == 0) {
			//Jos botti pelaa valkoisilla..
			if (liittyma.vastustajanVari != 0) {
				MinMaxPaluu paluu;
				liittyma._asema->lista.clear();
				liittyma._asema->annaLaillisetSiirrot(liittyma._asema->lista);
				liittyma._asema->listanSiivous(liittyma._asema->lista, 0);
				paluu = liittyma._asema->maxi(2);
				system("cls");
				Siirto* parassiirto = new Siirto(paluu.parasSiirto);
				if (parassiirto->getAlkuruutu() == liittyma._asema->vkruutu)
					liittyma._asema->vkruutu = parassiirto->getLoppuruutu();
				liittyma._asema->_lauta[parassiirto->getAlkuruutu().getRivi()][parassiirto->getAlkuruutu().getSarake()]->Onkoliikutettu = true;
				wcout << L"Valkoisen paras siirto on:\n";
				wcout << L"\nAlku S: " << parassiirto->getAlkuruutu().getSarake() + 1 << " R:" << parassiirto->getAlkuruutu().getRivi() + 1 << endl;
				wcout << L"\nLoppu S: " << parassiirto->getLoppuruutu().getSarake() + 1 << " R:" << parassiirto->getLoppuruutu().getRivi() + 1 << endl;
				liittyma._asema->paivitaAsema(parassiirto);
				delete parassiirto;
				liittyma._asema->setSiirtovuoro(1);
				liittyma.piirraLauta();
				continue;
			}	
			//Jos Pelaaja pelaa valkoisilla..
			wcout << L"valkoisen vuoro. Anna siirto: \n";
			getline(cin, syote);
			Siirto* uusisiirto = new Siirto(liittyma.kasittely(syote, 0));
			liittyma._asema->paivitaAsema(uusisiirto);
			if (uusisiirto->getLoppuruutu() == liittyma._asema->mkruutu) {
				peli_jatkuu = false;
				wcout << L"\nPELI LOPPUI!\nVALKOINEN ON VOITTAJA, HUZZAH!\n";
			}
			delete uusisiirto;
			liittyma._asema->setSiirtovuoro(1);
			liittyma.piirraLauta();
		}
		else  {
			//Jos botti pelaa mustilla..
			if (liittyma.vastustajanVari != 1) {
				MinMaxPaluu paluu;
				liittyma._asema->lista.clear();
				liittyma._asema->annaLaillisetSiirrot(liittyma._asema->lista);
				liittyma._asema->listanSiivous(liittyma._asema->lista, 1);
				paluu = liittyma._asema->mini(2);
				system("cls");
				Siirto* parassiirto = new Siirto(paluu.parasSiirto);
				if (parassiirto->getAlkuruutu() == liittyma._asema->mkruutu)
					liittyma._asema->mkruutu = parassiirto->getLoppuruutu();
				liittyma._asema->_lauta[parassiirto->getAlkuruutu().getRivi()][parassiirto->getAlkuruutu().getSarake()]->Onkoliikutettu = true;
				wcout << L"Mustan paras siirto on:\n";
				wcout << L"\nAlku S: " << parassiirto->getAlkuruutu().getSarake() + 1 << " R:" << parassiirto->getAlkuruutu().getRivi() + 1 << endl;
				wcout << L"\nLoppu S: " << parassiirto->getLoppuruutu().getSarake() + 1 << " R:" << parassiirto->getLoppuruutu().getRivi() + 1 << endl;
				liittyma._asema->paivitaAsema(parassiirto);
				delete parassiirto;
				liittyma._asema->setSiirtovuoro(0);
				liittyma.piirraLauta();
				continue;
			}
			//Jos Pelaaja pelaa mustilla..
			wcout << L"Mustan vuoro. Anna siirto: \n";
			getline(cin, syote);
			Siirto* uusisiirto = new Siirto(liittyma.kasittely(syote, 1));
			liittyma._asema->paivitaAsema(uusisiirto);
			if (uusisiirto->getLoppuruutu() == liittyma._asema->vkruutu) {
				peli_jatkuu = false;
				wcout << L"\nPELI LOPPUI!\nMUSTA ON VOITTAJA, HUZZAH!\n";
			}			
			delete uusisiirto;
			liittyma._asema->setSiirtovuoro(0);
			liittyma.piirraLauta();
		}
	}
	return 0;
}
