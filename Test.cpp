#include <stdio.h>
#include <iostream>
#include "Test.h"
#include "Ensemble.h"

using namespace std;
int main(void)
{
	int salut[5] = {1,2,3,4,5};
	int salut2[10] = {2};
	int salut3[5] = {1,2,3,4,6};
	int salut4[5] = {1,2,3,4,6};
	int salut5[6] = {6,10,11,12,8,9};
	int salut6[0];
	Ensemble salutA(salut,5);
	Ensemble salutB(salut2,4);
	Ensemble salutC(salut3,5);
	Ensemble salutD(salut4,5);
	Ensemble salutE(salut5,6);
	Ensemble salutF(salut6,0);
	//cout << salutA.EstEgal(salutB) << "DEVRAIT ETRE FAUX" << endl;
	//cout << salutA.EstEgal(salutC) << "DEVRAIT ETRE VRAI" << endl;
	//cout << salutD.EstEgal(salutA)<< "DEVRAIT ETRE FAUX" << endl;
	//cout << salutE.EstEgal(salutF)<< "DEVRAIT ETRE VRAI" << endl;
	
	//cout<< salutA.EstInclus(salutC) << "DEVRAIT ETRE 50" << endl; 
//	cout<< salutA.EstInclus(salutB) << "DEVRAIT ETRE 40" << endl;
//	cout<< salutA.EstInclus(salutE) << "DEVRAIT ETRE 60" << endl;
//	salutA.Afficher();
	cout<< salutA.Retirer(salutC) << "DEVRAIT ETRE 1,3,4" << endl;
	salutA.Afficher();
//	salutC.Afficher();
//	cout<< salutE.Retirer(salutD) << "DEVRAIT ETRE 1" << endl;
	salutC.Afficher();
	salutE.Afficher();

	cout << salutC.Reunir(salutE) << " : Reunir "<< endl;
	salutC.Afficher();
	return 0;
}

