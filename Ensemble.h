/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( Ensemble_H )
#define Ensemble_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
#define CARD_MAX 5
enum crduEstInclus {NON_INCLUSION, INCLUSION_LARGE, INCLUSION_STRICTE};
enum crduAjouter {DEJA_PRESENT, PLEIN, AJOUTE};
//------------------------------------------------------------------ Types


//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
// Gestion d'une collection d'entier, avec réajustement automatique ou à
// la demande. Cette collection d'entier peut s'apparenter à un ensemble
// mathématique.
//
//------------------------------------------------------------------------

class Ensemble
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	void Afficher ( void );
    // Mode d'emploi :
    //
    // Contrat :
    //
	
	bool EstEgal (const Ensemble & unEnsemble) const; 
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    crduEstInclus EstInclus( const Ensemble & unEnsemble ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    crduAjouter Ajouter ( int aAjouter );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    unsigned int Ajuster ( int delta );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    bool Retirer (int element); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    unsigned int Retirer (const Ensemble & unEnsemble); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    int Reunir ( const Ensemble & unEnsemble );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
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

    Ensemble ( unsigned int cardMax = CARD_MAX );
    // Mode d'emploi :
    // Aucun, un simple constructeur
    // Contrat :
    //

    Ensemble (int t[ ], unsigned int nbElements);
    // Mode d'emploi :
    // Passage par paramètre d'un tableau ainsi que du nombre d'éléments pour créer notre ensemble
    // Contrat :
    //

    virtual ~Ensemble ( );
    // Mode d'emploi :
    // Détruit le tableau représentant l'ensemble avant de détruire l'objet lui-même
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
void triEnsembleCroissant(void);
//----------------------------------------------------- Attributs protégés
unsigned int cardMax;
unsigned int cardActuelle;
int * ensemble; 
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // Ensemble_H

