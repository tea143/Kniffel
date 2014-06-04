/* 
 * File:   einerBisSechser.h
 * Author: IFI
 *
 * Created on 20. Mai 2014, 14:09
 */

#ifndef EINERBISSECHSER_H
#define	EINERBISSECHSER_H

#include "kategorie.h"

class EinerBisSechser : public Kategorie {

public:
	//Konstruktor:
	EinerBisSechser(unsigned int, std::string);
	//Destruktor:
	~EinerBisSechser();

	virtual unsigned int punkteBerechnen(const std::vector<unsigned int>&) override;
	unsigned int getGesetzteZahl() const;
	void setGesetzteZahl(unsigned int gesetzteZahl);

private:
	unsigned int gesetzteZahl;
};

#endif	/* EINERBISSECHSER_H */

