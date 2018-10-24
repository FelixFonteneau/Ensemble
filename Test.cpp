#include <stdio.h>
#include <iostream>
#include "Test.h"
#include "Ensemble.h"

using namespace std;


void testPart10(void)
{
	int salut[5] = {1,2,3,4,5};
	int salut2[10] = {2,3,4};
	int salut3[5] = {3,4,5,6,7};
	int salut4[5] = {1,2,3,4,6};
	int salut5[6] = {6,10,11,12,8,9};
	int salut6[10];
	int salut7[0];
	Ensemble a(salut,5);
	Ensemble aA(salut,5);
	Ensemble aAA(salut,5);
	Ensemble aAAA(salut,5);

	Ensemble salutB(salut2,3);
	Ensemble salutC(salut3,5);
	Ensemble salutD(salut4,5);
	Ensemble salutE(salut5,6);
	Ensemble salutF(10);
	Ensemble ensVd(4);

	Ensemble salutG(salut7,0);

//premier cas deux ensemble vide
	ensVd.Afficher();
	cout << ensVd.Intersection(salutF) << "retour Intersection"  << endl;
	ensVd.Afficher();

//ensemble non vide avec ensemble vide
		a.Afficher();
		cout << "retour Intersection" << a.Intersection(salutF) << "retour Intersection"  << endl;
		a.Afficher();

		salutF.Afficher();
		cout << "retour Intersection" << salutF.Intersection(aA) << "retour Intersection"  << endl;
		salutF.Afficher();

		aA.Afficher();
		cout << "retour Intersection" << aA.Intersection(salutE) << "retour Intersection"  << endl;
		aA.Afficher();

		aAA.Afficher();
		salutB.Afficher();
		cout << "retour Intersection" << aAA.Intersection(salutB) << "retour Intersection"  << endl;
		aAA.Afficher();

		aAAA.Afficher();
		cout << "retour Intersection" << aAAA.Intersection(aAAA) << "retour Intersection"  << endl;
		aAAA.Afficher();


}


int main(void)
{
/*	int salut[5] = {1,2,3,4,5};
	int salut2[10] = {2};
	int salut3[5] = {1,2,3,4,6};
	int salut4[5] = {1,2,3,4,6};
	int salut5[6] = {6,10,11,12,8,9};
	int salut6[10];
	int salut7[0];
	Ensemble a(salut,5);
	Ensemble salutB(salut2,4);
	Ensemble salutC(salut3,5);
	Ensemble salutD(salut4,5);
	Ensemble salutE(salut5,6);
	Ensemble salutF(10);
	Ensemble salutG(salut7,0); */

	//cout << a.EstEgal(salutB) << "DEVRAIT ETRE FAUX" << endl;
	//cout << a.EstEgal(salutC) << "DEVRAIT ETRE VRAI" << endl;
	//cout << salutD.EstEgal(a)<< "DEVRAIT ETRE FAUX" << endl;
	//cout << salutE.EstEgal(salutF)<< "DEVRAIT ETRE VRAI" << endl;

	//cout<< a.EstInclus(salutC) << "DEVRAIT ETRE 50" << endl;
//	cout<< a.EstInclus(salutB) << "DEVRAIT ETRE 40" << endl;
//	cout<< a.EstInclus(salutE) << "DEVRAIT ETRE 60" << endl;
	//a.Afficher();
	//cout<< a.Retirer(salutC) << "DEVRAIT ETRE 1,3,4" << endl;
	//a.Afficher();
//	salutC.Afficher();
	//salutE.Afficher();
//	cout<< salutE.Retirer(salutD) << "DEVRAIT ETRE 1" << endl;
	//salutE.Afficher();

//		salutF.Afficher();
	//	cout<< salutF.Retirer(salutG) << "ICI PUTAINNNN DEVRAIT ETRE 0" << endl;
		//salutF.Afficher();

/*	a.Afficher();
	salutE.Afficher();

	cout << "Intersection la" << salutE.Intersection(a) << endl;
	salutE.Afficher();
	salutB.Afficher();
	cout << "Intersection B F ici " << salutB.Intersection(salutF) << endl;
	salutB.Afficher();

	cout << "Intersection F G  " << salutG.Intersection(salutG) << endl;
	salutG.Afficher();


	salutD.Afficher();

	cout << "Intersection DD  " << salutD.Intersection(salutF) << endl;
	salutD.Afficher(); */
	//cout << salutC.Reunir(salutE) << " : Reunir "<< endl;
	//salutC.Afficher();

	testPart10();
	return 0;
}
