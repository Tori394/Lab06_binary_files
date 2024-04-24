#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
	Product(int id, string name, double price);

	friend class ProductManager;
private:
	int m_id;
	string m_name;
	double m_price;
};