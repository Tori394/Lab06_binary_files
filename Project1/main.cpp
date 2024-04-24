#include <iostream>
#include "ProductManager.h"
using namespace std;

int main()
{
	ProductManager spis;
	spis.addProduct(Product(1, "Ksiazka", 10.50));
	spis.addProduct(Product(2, "Jojo", 2.99));
	spis.addProduct(Product(3, "Czekolada", 7.75));
	spis.addProduct(Product(4, "Buty", 89.90));
	spis.displayProducts();
	cout << endl;
	spis.removeProduct(5);
	spis.addProduct(Product(1, "Komiks", 6.50));
	spis.saveToFile("dane");
	spis.removeProduct(1);
	spis.removeProduct(2);
	spis.removeProduct(3);
	spis.removeProduct(4);
	spis.addProduct(Product(1, "Komiks", 6.50));
	spis.displayProducts();
	cout << endl;
	spis.saveToFile("dane2");
	spis.loadFromFile("dane");
	cout << endl;
	spis.displayProducts();
	cout << endl;
	spis.loadFromFile("dane2");
	cout << endl;
	spis.displayProducts();
}


/*
ID: 1(int)
Nazwa: Ksiazka(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)
Cena: 10.5(double)
ID: 2(int)
Nazwa: Jojo(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)
Cena: 2.99(double)
ID: 3(int)
Nazwa: Czekolada(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)
Cena: 7.75(double)
ID: 4(int)
Nazwa: Buty(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)
Cena: 89.9(double)

Blad - zle ID. Takiego ID nie ma w bazie danych
Blad - zle ID. Takie ID jest juz zarejestrowane
ID: 1(int)
Nazwa: Komiks(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)
Cena: 6.5(double)

Uwaga, jesli nie zapisales akutalnych danych zostana one utracone.
Chcesz kontunuowac?     tak - 1    nie - 0
1

ID: 1(int)
Nazwa: Ksiazka(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)
Cena: 10.5(double)
ID: 2(int)
Nazwa: Jojo(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)
Cena: 2.99(double)
ID: 3(int)
Nazwa: Czekolada(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)
Cena: 7.75(double)
ID: 4(int)
Nazwa: Buty(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)
Cena: 89.9(double)

Uwaga, jesli nie zapisales akutalnych danych zostana one utracone.
Chcesz kontunuowac?     tak - 1    nie - 0
1

ID: 1(int)
Nazwa: Komiks(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)
Cena: 6.5(double)
*/