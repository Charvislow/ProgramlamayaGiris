//****************************************************//
//		Student Name:	Mehmet Fatih Yýldýz			  //
//		Student Number:	B201202013					  //
//****************************************************//
#include <iostream>
using namespace std;

const int SIZE = 10;			//Size of array

enum categories { food, drink, junk, stationary };		//enum for product categories

struct product {			//Struct for define product members

	string name;
	int id;
	double price;
	double tax;
	categories categ;
};

void addProducts(product& prod) {			//Function ,which returns values, for adding new products to array

	cout << "PRODUCT NAME    : ";			//Defining product names
	cin >> prod.name;

	cout << "PRODUCT ID      : ";			//Defining product ID
	cin >> prod.id;

	cout << "PRODUCT PRICE   : ";			//Defining product price
	cin >> prod.price;

	int prodType;
	cout << "PRODUCT TYPE    : [FOOD => 1, DRINK => 2, JUNK => 3, STATIONARY => 4] ";
	cin >> prodType;
	prod.categ = static_cast<categories>(prodType - 1);		//Defining product category by using enum 
}

void printProducts(product prod) {			//Function for printing products to the screen

	cout << "PRODUCT NAME        : " << prod.name << endl;
	cout << "PRODUCT ID          : " << prod.id << endl;
	cout << "PRODUCT PRICE       : " << prod.price << endl;
	cout << "PRODUCT TYPE        : ";

	switch (prod.categ) {			//decides categories

	case 0:cout << "FOOD" << endl; break;
	case 1:cout << "DRINK" << endl; break;
	case 2:cout << "JUNK" << endl; break;
	case 3:cout << "STATIONARY" << endl; break;
	}

	switch (prod.categ) {			//calculates taxes

	case 0:prod.tax = (prod.price * 3) / 100; break;
	case 1:prod.tax = (prod.price * 5) / 100; break;
	case 2:prod.tax = (prod.price * 18) / 100; break;
	case 3:prod.tax = (prod.price * 8) / 100; break;
	}

	cout << "TAX		    : " << prod.tax;
	cout << "\n----------------------------------\n";
}

int main()
{
	product products[SIZE];			//10 sizes array for the products

	products[0].name = "BREAD";						//First 4 elemnts of the array
	products[0].id = 1;
	products[0].price = 4;
	products[0].categ = static_cast<categories>(0);

	products[1].name = "AYRAN";
	products[1].id = 2;
	products[1].price = 4;
	products[1].categ = static_cast<categories>(1);

	products[2].name = "CHIPS";
	products[2].id = 3;
	products[2].price = 9;
	products[2].categ = static_cast<categories>(2);

	products[3].name = "PENCIL";
	products[3].id = 4;
	products[3].price = 20;
	products[3].categ = static_cast<categories>(3);

	int nextProducts = 5;			//Variable for the next product numbers
	int currentProducts = 4;		//Variable for the current product numbers

	while (nextProducts < SIZE + 2) {		//While loop for main steps

		cout << "----------------------------------\n" << "-----------PRODUCT LIST-----------\n" << "----------------------------------\n";

		for (int j = 0; j < currentProducts; j++) {		//For loop is calling print function
			printProducts(products[j]);
		}

		char ans;		//Char for the answer
		cout << "DO YOU WANT TO ADD NEW PRODUCT [Y/N]: ";
		cin >> ans; cout << endl;

		if (ans == 'Y') {		//If answer is Y
			if (nextProducts == 11) {						//If nextProduct variable equals to 11 (which means currentProducts variable equals to 10, which means array is full)
				cout << "CAPACITY IS FULL" << endl;			// program gives a message and stop
				system("pause");
			}

			else {
				for (currentProducts; currentProducts < nextProducts; currentProducts++) {			//If nextProducts variable is smaller than 11
					addProducts(products[currentProducts]);											//program calls addProduct function and increased currentProduct
				}																					//value by one
				nextProducts++;			//After for loop nextProducts value increases by one.
				continue;
			}
		}

		else {
			system("pause");		//If answer does not Y then system stops
		}
		break;
	}
	return 0;
}