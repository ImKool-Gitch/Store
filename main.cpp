#include <iostream>
#include <vector>

class Product {
public:
	std::string name;
	unsigned price;
	Product(std::string name_p, unsigned price_p) {
		name = name_p;
		price = price_p;
	}
};

class Store {
private:
	std::vector <Product>products;
public:
	Store();
	void print_all_products();
	void add_product();
	void remove_product();
	unsigned return_value(std::string product_name);
	bool IsProductPresent(std::string product_name);
};

class User {
private:
	class Cart {
	private:
		unsigned total_cost;
		std::vector <std::string>cart;
	public:
		bool IsProductPresent(std::string product_name);
		bool add_product(std::string product_name, const Store store);
		bool remove_product(std::string product_name, const Store store);
		void display_contents();
		void check_out();
		bool isEmpty();
		unsigned return_tot_cost();
		Cart() {
			total_cost = 0;
		}
	};
	std::string name;
	std::string email;
	std::string shipping_address;
	std::string payment_info;
public:
	User();
	Cart current_cart;
	void display_info();
};


///////////////////////////////////////////

//MAIN FUNCTION

int main() {
	User user;
	Store store;
	unsigned option;
	unsigned secret_option;
	bool quit = false;
	bool secret_quit = false;
	std::string name_of_product_to_find;
	std::string name_of_product_to_add;
	std::string name_of_product_to_remove;

	std::cout << std::endl << "Welcome to the Store 1.0 " << std::endl;
	std::cout << "Enter an option from the menu: " << std::endl;
	std::cout << "1.Print the products in the store" << std::endl;
	std::cout << "2.Check if a product is present in your cart" << std::endl;
	std::cout << "3.Add a product in your cart" << std::endl;
	std::cout << "4.Remove a product in your cart" << std::endl;
	std::cout << "5.Display the contents in you cart" << std::endl;
	std::cout << "6.Check out" << std::endl;
	std::cout << "7.Check if your cart is empty or no" << std::endl;
	std::cout << "8.Print the info of the current account" << std::endl;
	std::cout << "9.Print the menu options" << std::endl;
	std::cout << "10.Exit" << std::endl;
	while (!quit) {
		std::cout << ":... ";
		std::cin >> option;
		switch (option) {
		case 1:
			store.print_all_products();
			break;
		case 2:
			std::cout << "Enter product name: ";
			std::cin >> name_of_product_to_find;
			if (!user.current_cart.IsProductPresent(name_of_product_to_find))
				std::cout << "Product is not present" << std::endl;
			else
				std::cout << "Product is present" << std::endl;
			name_of_product_to_find = "";
			break;
		case 3:
			std::cout << "Enter the name of the product you want to add in your cart: ";
			std::cin >> name_of_product_to_add;
			if (!user.current_cart.add_product(name_of_product_to_add, store))
				std::cout << "Product doesnt exist in the store" << std::endl;
			else
				std::cout << "Product was successfully added" << std::endl;
			name_of_product_to_add = "";
			break;
		case 4:
			std::cout << "Enter the name of the product you want to remove from your cart: ";
			std::cin >> name_of_product_to_remove;
			if (!user.current_cart.remove_product(name_of_product_to_remove, store))
				std::cout << "Product was not present in the cart" << std::endl;
			else
				std::cout << "Product successfully removed" << std::endl;
			name_of_product_to_remove = "";
			break;
		case 5:
			std::cout << "The contents of the cart are: " << std::endl;
			user.current_cart.display_contents();
			break;
		case 6:
			user.current_cart.check_out();
			break;
		case 7:
			if (!user.current_cart.isEmpty())
				std::cout << "Cart is not empty" << std::endl;
			else
				std::cout << "Cart is empty" << std::endl;
			break;
		case 8:
			user.display_info();
			break;
		case 9:
			std::cout << "1.Print the products in the store" << std::endl;
			std::cout << "2.Check if a product is present in your cart" << std::endl;
			std::cout << "3.Add a product in your cart" << std::endl;
			std::cout << "4.Remove a product in your cart" << std::endl;
			std::cout << "5.Display the contents in you cart" << std::endl;
			std::cout << "6.Check out" << std::endl;
			std::cout << "7.Check if your cart is empty or no" << std::endl;
			std::cout << "8.Print the info of the current account" << std::endl;
			std::cout << "9.Print the menu options" << std::endl;
			std::cout << "10.Exit" << std::endl;
			break;
		case 10:
			quit = true;
			break;
		case 69:
			std::cout << "Welcome to the secret admin panel !" << std::endl;
			std::cout << "Enter an option from the secret menu: " << std::endl;
			std::cout << "1.Add a product in the store" << std::endl;
			std::cout << "2.Remove a product in the store" << std::endl;
			std::cout << "3.Exit" << std::endl;
			while (!secret_quit) {
				std::cout << ":... ";
				std::cin >> secret_option;
				switch (secret_option) {
				case 1:
					store.add_product();
					break;
				case 2:
					store.remove_product();
					break;
				case 3:
					secret_quit = true;
					break;
				default:
					std::cout << "Option doesnt exist" << std::endl;
				}
			}
			secret_quit = false;
			break;
		default:
			std::cout << "Option doesnt exist" << std::endl;
		}
	}
	return 0;
}

//END OF MAIN FUNCTION

///////////////////////////////////////////


//Start of Store class methods definitions

Store::Store() {
	products.emplace_back("Milk", 20);
	products.emplace_back("Eggs", 50);
	products.emplace_back("Bread", 10);
}

void Store::print_all_products() {
	for (Product i : products) {
		std::cout << "---------------------------------------------------------" << std::endl;
		std::cout << "Name: " << i.name << std::endl << "Price: " << i.price << '$' << std::endl;
		std::cout << "---------------------------------------------------------" << std::endl;
	}
}

void Store::add_product() {
	std::string product_name; 
	unsigned price;
	std::cout << "Enter name of product: ";
	std::cin >> product_name;
	for (Product i : products) {
		if (i.name == product_name) {
			std::cout << "Product is already in the store" << std::endl;
			return;
		}
	}
	std::cout << "Enter price of product: ";
	std::cin >> price;
	Product temp_product(product_name, price);
	products.push_back(temp_product);
}

void Store::remove_product() {
	std::string product_name;
	std::cout << "Enter name of product to remove: ";
	std::cin >> product_name;
	for (auto it = products.begin(); it < products.end(); ++it) {
		if (it->name == product_name) {
			products.erase(it);
			std::cout << "Product removed" << std::endl;
			return;
		}
	}
	std::cout << "Product was not found" << std::endl;
}

unsigned Store::return_value(std::string product_name) {
	for (Product i : products) {
		if (i.name == product_name)
			return i.price;
	}
}

bool Store::IsProductPresent(std::string product_name) {
	for (Product i : products) {
		if (i.name == product_name)
			return true;
	}
	return false;
}

//End of Store class methods definitions



//Start of Cart class methods definitions

bool User::Cart::IsProductPresent(std::string product_name) {
	for (std::string i : cart) {
		if (i == product_name)
			return true;
	}
	return false;
}

bool User::Cart::add_product(std::string product_name, Store store) {
	if (!store.IsProductPresent(product_name))
		return false;
	cart.push_back(product_name);
	total_cost += store.return_value(product_name);
	return true;
}

bool User::Cart::remove_product(std::string product_name, Store store) {
	if (!IsProductPresent(product_name))
		return false;
	auto it = cart.begin();
	unsigned str_i = 0;
	unsigned it_i = 0;
	for (std::string temp_i : cart) {
		if (temp_i == product_name)
			break;
		++str_i;
	}
	for (; it_i <= str_i; ++it)
		++it_i;
	total_cost -= store.return_value(product_name);
	cart.erase(it);
	return true;
}

void User::Cart::display_contents() {
	if (cart.empty()) {
		std::cout << "Cart is empty" << std::endl;
		return;
	}
	for (std::string i : cart)
		std::cout << i << std::endl;
}

void User::Cart::check_out() {
	std::cout << "Checking out ...." << std::endl;
	if (cart.empty()) {
		std::cout << "Cannot check out on an empty cart" << std::endl;
		return;
	}
	cart.clear();
	total_cost = 0;
}

bool User::Cart::isEmpty() {
	return cart.empty();
}

unsigned User::Cart::return_tot_cost() {
	return total_cost;
}

//End of Cart class methods definitions


//Start of User class methods definitions

User::User() {
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter email: ";
	std::cin >> email;
	std::cout << "Enter shipping address: ";
	std::cin >> shipping_address;
	std::cout << "Enter payment info: ";
	std::cin >> payment_info;
}

void User::display_info() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Email: " << email << std::endl;
	std::cout << "Shipping address: " << shipping_address << std::endl;
	std::cout << "Payment information: " << payment_info << std::endl;
	std::cout << "Total cost: " << current_cart.return_tot_cost() << '$' << std::endl;
}

//End of User class methods definitions
