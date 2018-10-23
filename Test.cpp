#include <stdio.h>
#include <iostream>
#include "Test.h"
#include "Ensemble.h"

using namespace std;
int main(void)
{
	/*
	int salut[5] = { 1,2,3,4,5 };
	int salut2[4] = { 5,5,5,2 };
	int salut3[5] = { 1,2,3,4,5 };
	int salut4[5] = { 1,2,3,4,6 };
	int salut5[0];
	int salut6[0];
	Ensemble salutA(salut, 5);
	Ensemble salutB(salut2, 4);
	Ensemble salutC(salut3, 5);
	Ensemble salutD(salut4, 5);
	Ensemble salutE(salut5, 0);
	Ensemble salutF(salut6, 0);
	cout << salutA.EstEgal(salutB) << "DEVRAIT ETRE FAUX" << endl;
	cout << salutA.EstEgal(salutC) << "DEVRAIT ETRE VRAI" << endl;
	cout << salutD.EstEgal(salutA) << "DEVRAIT ETRE FAUX" << endl;
	cout << salutE.EstEgal(salutF) << "DEVRAIT ETRE VRAI" << endl; */

	int salut[5] = { 1,2,3,4,5 };
	Ensemble salutA(salut, 5);
	Ensemble vide(3);

	cout << salutA.Ajouter(9) << endl;
	cout << salutA.Ajouter(1) << endl;
	cout << vide.Ajouter(666) << endl;

	return 0;
}
