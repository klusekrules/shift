#pragma once
#include "ZmianaSymbol.h"
#include "ZmianaParametr.h"
#include "ZmianaFabryka.h"

namespace SZmi{
	/**
	* \brief Klasa reprezentuj�ca zmian� liniow�.
	*
	* Spos�b dzia�ania metody wyliczajacej:
	*	- Warto�� atrybutu mno�ona jest przez wsp�czynik pobrany z parametru i to mno�one jest przez poziom przekazany w parametrze. ( wartosc * parametr_ * poziom )
	* \author Daniel Wojdak
	* \version 1
	* \date 11-07-2013
	*/
	class ZMIANA_API ZmianaLiniowaIlosciowa :
		public ZmianaInterfejs,
		virtual public SLog::LoggerInterface
	{
	private:
		static const STyp::Identyfikator identyfikator_; /// Identyfikator klasy przekazywany do fabryki.

		/**
		* Metoda tworz�ca obiekt a podstawie w�z�a.
		* \param[in] wezel - W�ze� na podstawie kt�rego tworzony jest obiekt.
		* \return Wska�nika na obiekt utworzonej zmiany.
		*/
		static ZmianaInterfejs* TworzZmianaLiniowaIlosciowa(XmlBO::ElementWezla wezel);

		ZmianaParametr parametr_; /// Wsp�czynnik o jaki zmienia si� warto�� atrybutu.

	public:

		/**
		* Metoda rejestruj�ca klas� w fabryce.
		* \param[in] fabryka - Referencja do globalnej fabryki.
		* \return Metoda zwraca warto�� true, je�eli uda si� zarejestrowa� klas�. Je�eli wyst�pi� b��d zwr�cona jest warto�� false.
		* \sa ZmianaFabryka
		*/
		static bool RejestrujZmianaLiniowaIlosciowa(ZmianaFabryka &fabryka);

		/**
		* Metoda wyliczaj�ca warto��.
		* Spos�b dzia�ania metod policzWartosc klasy zmiana agregacja:
		*	- Warto�� atrybutu mno�ona jest przez wsp�czynik pobrany z parametru i to mno�one jest przez poziom przekazany w parametrze. ( wartosc * parametr_ * poziom )
		* \param[in] wartosc - podstawowa warto�� parametru, dla k�trego b�dzie wyliczana modyfikacja warto�ci.
		* \param[in] poziom - poziom obiektu, dla kt�rego b�dzie wyliczana modyfikacja warto�ci.
		* \param[in] identyfikatorPlanety - identyfikator planety, na kt�rej znajduje si� obiekt.
		* \return Przeliczona warto�� atryutu.
		*/
		STyp::Wartosc policzWartosc(const STyp::Wartosc& wartosc, const STyp::Poziom& poziom, const STyp::Identyfikator& identyfikatorPlanety)const override;

		/**
		* Metoda tworzy kopi� obiektu.
		* \return Wska�nik do kopii obiektu.
		* \warning Zwr�cony wska�nik musi zostac zwolniony operatorem delete.
		*/
		ZmianaLiniowaIlosciowa* Kopia()const override;

		/**
		* Konstruktor obiektu na podstawie w�z�a XML.
		* \param[in] wezel - Wezel drzewa xml.
		* \pre W�ze� musi zawiera� nast�puj�c� struktur�
		* \code {.xml}
		*	<Zmiana id="n">
		*		<Param wspolczynnik="3.0"/>
		*	</Zmiana>
		* \endcode
		*/
		explicit ZmianaLiniowaIlosciowa(XmlBO::ElementWezla wezel);

		/**
		* Destruktor
		*/
		virtual ~ZmianaLiniowaIlosciowa() = default;

		/**
		* Metoda tworz�ca napis zawieraj�cy opis obiektu.
		* \return Opis obiektu.
		*/
		std::string napis() const override;

	};
}
