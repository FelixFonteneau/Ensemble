/*************************************************************************
Ensemble  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( Ensemble_H )
#define Ensemble_H

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes
#define CARD_MAX 5
enum crduAjouter { DEJA_PRESENT, PLEIN, AJOUTE };
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Ensemble>
// Gestion d'une collection d'entier, avec r�ajustement automatique ou �
// la demande. Cette collection d'entier peut s'apparenter � un ensemble
// math�matique.
//
//------------------------------------------------------------------------

class Ensemble
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	void Afficher(void);
	// type M�thode ( liste des param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool EstEgal(const Ensemble & unEnsemble) const;
	// type M�thode ( liste des param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	crduAjouter Ajouter ( int aAjouter );
	// type M�thode ( liste des param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------- Surcharge d'op�rateurs
	//   Ensemble & operator = ( const Ensemble & unEnsemble );
	// Mode d'emploi :
	//
	// Contrat :
	//


	//-------------------------------------------- Constructeurs - destructeur
	// Ensemble ( const Ensemble & unEnsemble );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Ensemble(unsigned int cardMax = CARD_MAX);
	// Mode d'emploi :
	// Aucun, un simple constructeur
	// Contrat :
	//

	Ensemble(int t[], unsigned int nbElements);
	// Mode d'emploi :
	// Passage par param�tre d'un tableau ainsi que du nombre d'�l�ments pour cr�er notre ensemble
	// Contrat :
	//

	virtual ~Ensemble();
	// Mode d'emploi :
	// D�truit le tableau repr�sentant l'ensemble avant de d�truire l'objet lui-m�me
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es
	void triEnsembleCroissant(void);
	//----------------------------------------------------- Attributs prot�g�s
	unsigned int cardMax;
	unsigned int cardActuelle;
	int * ensemble;
};

//-------------------------------- Autres d�finitions d�pendantes de <Ensemble>

#endif // Ensemble_H
