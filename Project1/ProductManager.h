#include <iostream>
#include <vector>
#include "Product.h"
using namespace std;

class ProductManager
{
private:
	vector<Product> m_products;

public:
	~ProductManager();

	void addProduct(const Product& product);
	void removeProduct(int id);
	void displayProducts();
	void saveToFile(const string& filename);
	void loadFromFile(const string& filename);

	friend class Product;
};

