/**
 * @file Ensemble.hpp
 * @author DENMAT Marion et DE SAUVECANNE Lois
 * @brief Dans ce fichier nous définissons la classe Ensemble implémentée en chaînage simple sans doublons. Nous y déclarons toutes les méthodes de la classe. Y est définit également le type Type qui est par défaut une chaine de caractères.
**/

#ifndef ENSEMBLECHAIN_HPP
#define ENSEMBLECHAIN_HPP

#include <string>

/******************************************************************************/
// classe Ensemble générique, paramétrée par le type Type à utiliser pour
// représenter les coordonnées (par défaut : string) 
// Hypothèses sur le type Type : 
//    - admettre l'envoi dans un flux de sortie (opérateur <<)
template < typename Type = std::string >
class Ensemble {

	private : 
	
		struct Maillon{
		
			Type contenu;
			Maillon* suiv;
			Maillon(Type s,Maillon* ss):contenu(s),suiv(ss){}
		};
		
		Maillon* tete;
		int nb;
		
	public :
	
		Ensemble();
		~Ensemble();
		bool est_vide();
		bool contient(Type mot);
		void ajoute(Type mot);
		void retire(Type mot);
		std::string contenu();
		Ensemble<Type> intersection(Ensemble<Type>,Ensemble<Type>);
		Ensemble<Type> unionEns(Ensemble<Type>,Ensemble<Type>);
		Ensemble<Type> difference(Ensemble<Type>,Ensemble<Type>);
};

#include "EnsembleChain.tpp" // définition des méthodes directement incluses dans le .hpp pour les classes génériques
/******************************************************************************/
#endif
