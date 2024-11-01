#include <iostream>
#include <list>
using namespace std;

class Product{
public:
    string productName;
    float productPrice;
    int productQuantity;

    Product(string name, float price, int quantity) {
        productName = name;
        productQuantity = quantity;
        productPrice = price;
    }
};

list<Product> products;

Product* find_product(string productName) {
    for (Product& product : products) {
        if(product.productName == productName) {
            return &product;
        }
    }

    return nullptr;
}

void create_product() {
    cout << "Enter product name:";
    string productName;
    cin >> productName;

    Product* findProduct = find_product(productName);
    if(findProduct != nullptr) {
        cout << "This product already exist! Maybe, you should try to add quantity.";
        return;
    }

    float productPrice;
    do {
        cout << "Enter product price: ";
        cin >> productPrice;

        if(productPrice <= 0){
            cout << "Product price can't be <= 0. Enter price again: ";
        }
    }
    while(productPrice <= 0);

    int quantity;
    do {
        cout << "Enter products quantity: ";
        cin >> quantity;

        if(quantity <= 0){
            cout << "Products quantity can't be <= 0. Enter quantity again: ";
        }
    } while (quantity <= 0);

    Product product = Product(productName, productPrice, quantity);
    products.push_back(product);
}

void remove_product() {
    cout << "Enter product name: ";
    string productName;
    cin >> productName;

    Product* product = find_product(productName);
    if(product == nullptr) {
        cout << "This product doesn't exist!";
        return;
    }

    for (auto it = products.begin(); it != products.end(); it++) {
        if (it->productName == productName) {
            products.erase(it);
            cout << "Product removed successfully!";
            return;
        }
    }
}

void set_new_quantity() {
    cout << "Enter product name: ";
    string productName;
    cin >> productName;

    Product* product = find_product(productName);
    if(product == nullptr) {
        cout << "This product doesn't exist!";
        return;
    }

    cout << "Current quantity: " << product->productQuantity << "\nEnter NEW quantity";
    int newQuantity;
    do {
        cin >> newQuantity;

        if (newQuantity < 0) {
            cout << "Product quantity can't be < 0. Enter quantity again: ";
        }
    } while (newQuantity < 0);

    product->productQuantity = newQuantity;
}

void show_all_products() {
    for (Product product : products) {
        cout << "=====================\n";
        cout << "Product name: " << product.productName << endl;
        cout << "Quantity: " << product.productQuantity << endl;
        cout << "Price: " << product.productPrice << endl;
        cout << "=====================\n\n";
    }
}

void products_price() {
    float price = 0;
    for (Product product : products) {
        price += product.productPrice * (float)product.productQuantity;
    }

    cout << "Final price of all products: " << price;
}

int main() {
    int choice;

    while(true) {
        cout << "\n1 - Create product \n2 - Remove product "
                "\n3 - Set new product quantity \n4 - Show all products "
                "\n5 - Calculate all products products price\n";

        cin >> choice;

        switch (choice) {
            case 1:
                create_product();
                break;

            case 2:
                remove_product();
                break;

            case 3:
                set_new_quantity();
                break;

            case 4:
                show_all_products();
                break;

            case 5:
                products_price();
                break;

            default:
                cout << "Wrong number";
                break;
        }
    }
}
