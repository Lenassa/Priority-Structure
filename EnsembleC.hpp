/**
 * @file EnsembleC.cpp
 * @author DENMAT Marion et DE SAUVECANNE Lois
 * @brief 
**/

#include <string>

/******************************************************************************/
// classe Ensemble générique, paramétrée par le type Type à utiliser pour
// représenter les coordonnées (par défaut : string) 
// Hypothèses sur le type Type : 
//    - être transtypable en string
//    - admettre l'opération de concaténation (opérateur +)
//    - admettre l'envoi dans un flux de sortie (opérateur <<)

class EnsembleC {

	private : 
	
		struct Maillon{
		
			std::string contenu;
			Maillon* suiv;
			Maillon(std::string s,Maillon* ss):contenu(s),suiv(ss){}
		};
		
		Maillon* tete;
		int nb;
		
	public :
	
		EnsembleC();
		~EnsembleC();
		bool est_vide();
		bool contient(std::string mot);
		void ajoute(std::string mot);
		void retire(std::string mot);
		std::string contenu();
};
