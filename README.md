# FSN_ShoppingCart
## How to Run
To run this code clone the repository, then compile it. In the testing of this code I compiled using g++ using the command `g++ -Wall -Wextra -pedantic -std=c++17 *.cpp`, then just run `./a.out` to begin. The program should then show the catalog and prompt you for a product code. This is just a very minimal CLI for testing the code in rather than building a GUI.

## How it works
When you enter the product codes you want you should be presented with the price after shipping and any discounts that were applied. I created structs for the items in the catalog and cart, as well as a struct for the discount. This way the program will search for any product codes that are having sales and subsequently discount the item by the set percentage if it meets the sale quantity criteria. I also coded the shipping prices and requirements in a way that allows them to be changed or for options to be removed or added in the future. 

## Assumptions
I made the assumption that no GUI was necessary since the project was focused on the implementation of algorithms. I also made the assumption that time complexity was not an issue because the dataset was very small as well as assuming this project were made in a way that implemented a database the searches in the cases I would have used them would have most likely worked in linear time as well, such as a *where* in SQL perhaps.
