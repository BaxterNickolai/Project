#include <iostream>
#include "Invoice.h"
int main(){

{
    Invoice invoice("ABCD");
invoice.addServiceCost(10);
if (invoice.getDollarsOwed() != 10) {
    std::cout << "Test 1 failed!" << std::endl;
}
}

{
Invoice invoice("ABCD");
invoice.addServiceCost(1);
if (invoice.getDollarsOwed() != 1) {
    std::cout << "Test 2 failed!" << std::endl;
}
}

{
Invoice invoice("ABCD");
if (invoice.getInvoiceCode() != "ABCD") {
    std::cout << "Test 3 failed!" << std::endl;
}
}

{
Invoice invoice("ABCD");
invoice.addServiceCost(10);
invoice.applyDiscount(0.3);
if (invoice.getDollarsOwed() != 7) {
    std::cout << "Test 4 failed!" << std::endl;
}
}

{
Invoice invoice("ABCD");
invoice.addServiceCost(10);
invoice.applyDiscount(1);
if (invoice.getDollarsOwed() != 0) {
    std::cout << "Test 5 failed!" << std::endl;
}
}

{
Invoice invoice("ABCD");
invoice.addServiceCost(10);
if (invoice.computeTax() != 1) {
    std::cout << "Test 6 failed!" << std::endl; 
}
}

{
Invoice invoice("ABCD");
if (invoice.isValidInvoiceCode(invoice.invoiceCode) == false) {
    std::cout << "Test 7 failed!" << std::endl;
}
}

{
Invoice invoice("ABcd");
if (invoice.isValidInvoiceCode(invoice.invoiceCode) != false) {
    std::cout << "Test 8 failed!" << std::endl;
}
}

}