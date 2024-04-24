#include "ProductManager.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include "MyExceptions.h"
using namespace std;

ProductManager::~ProductManager()
{
	m_products.clear();
	m_products.shrink_to_fit();
}

void ProductManager::addProduct(const Product& product)
{
	try
	{
		for (int i = 0; i < m_products.size(); i++)
		{
			if (m_products[i].m_id == product.m_id)
				throw WrongIDException ();
		}
	}
	catch (const exception& e)
	{	
		cout << e.what() << ". Takie ID jest juz zarejestrowane\n";
		return;
	}
	m_products.push_back(product);
	return;
}

void ProductManager::removeProduct(int id)
{
	try 
	{
		int index = -1;
		for (int i = 0; i < m_products.size(); i++) 
		{
			if (m_products[i].m_id == id) 
			{
				index = i;
				break;
			}
		}
		if (index == -1) {
			throw WrongIDException();
	}
	m_products.erase(m_products.begin() + index);
}
catch (const exception& e) {
	cout << e.what() << ". Takiego ID nie ma w bazie danych\n";
	return;
}
}

void ProductManager::displayProducts()
{
	for (int i = 0; i < m_products.size(); i++)
	{
		cout << "ID: " << m_products[i].m_id<<"("<<typeid(m_products[i].m_id).name() << ")\nNazwa: " << m_products[i].m_name << "(" << typeid(m_products[i].m_name).name() << ")\nCena: " << m_products[i].m_price << "(" << typeid(m_products[i].m_price).name() << ")\n";
	}
	//nie do koñca rozumiem czy o to chodzi³o w sprawdzaniu typów, ale nie widze innego sposobu na który mia³abym go u¿yæ w tej funkcji
	return;
}

void ProductManager::saveToFile(const string& filename)
{
	fstream zapisz(filename, ios::binary | ios::out);
	try
	{
		if (!zapisz)
			throw FileException();
	}
	catch (const exception& e)
	{
		cout << e.what();
		zapisz.close();
		return;
	}
	for (int i = 0; i < m_products.size(); i++)
	{
		zapisz.write(reinterpret_cast<char*>(&m_products[i].m_id), sizeof(int));
		int dlugosc = m_products[i].m_name.length();
		zapisz.write(reinterpret_cast<const char*>(&dlugosc), sizeof(int));
		zapisz.write(m_products[i].m_name.c_str(), dlugosc);
		zapisz.write(reinterpret_cast<char*>(&m_products[i].m_price), sizeof(double));
	}
	zapisz.close();
}

void ProductManager::loadFromFile(const string& filename)
{
	cout << "Uwaga, jesli nie zapisales akutalnych danych zostana one utracone.\nChcesz kontunuowac?     tak - 1    nie - 0\n";
	bool decyzja;
	cin >> decyzja;
	if (decyzja)
	{
		fstream zaladuj(filename, ios::binary | ios::in);
		try 
		{
			if (!zaladuj)
				throw FileException();
		}
		catch (const exception& e)
		{
			cout << e.what();
			zaladuj.close();
			return;
		}
		m_products.clear();
		while (true)
		{
			int id;
			zaladuj.read(reinterpret_cast<char*>(&id), sizeof(int));
			if (!zaladuj)
			{ 
				break;
			}
			int dl;
			zaladuj.read(reinterpret_cast<char*>(&dl), sizeof(int));
			char* buffer = new char[dl + 1];
			zaladuj.read(buffer, dl);
			buffer[dl] = '\0'; 
			string name(buffer);
			delete[] buffer;
			double price;
			zaladuj.read(reinterpret_cast<char*>(&price), sizeof(double));
			Product a(id, name, price);
			m_products.push_back(a);
		}
		zaladuj.close();
	}
	else
		return;
}
