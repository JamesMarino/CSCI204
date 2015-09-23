#include <iostream>
#include "stringSplit.h"

int main() {
    std::string str = "To create a Tokenizer object, you supply a target string (str), a string of delimiter (delim), and a Boolean flag (want_delim) indicating if delimiters in str should be returned as tokens. ";
    std::string delimiter = " ,().";
    
    MyLib::stringSplit sts(str, delimiter);
    
    sts.split(true);
    std::cout << "Tokens include delimiters:" << std::endl;
    while(sts.hasMore()) {
    	std::cout << '[' << sts.next() << ']' << std::endl;
    }
    std::cout << std::endl;
    
    sts.split(false);
    std::cout << "Tokens exclude delimiters:" << std::endl;
    while(sts.hasMore()) {
    	std::cout << '[' << sts.next() << ']' << std::endl;
    }
    std::cout << std::endl;
    
    sts.setString("AB*CDE+(RST-UV/XX)*3-X5");
    sts.setDelimiters("+-*/() ");
    
    sts.split(true);
    std::cout << "Tokens include delimiters:" << std::endl;
    while(sts.hasMore()) {
    	std::cout << '[' << sts.next() << ']' << std::endl;
    }
    std::cout << std::endl;
    
    
	sts.split(false);
    std::cout << "Tokens exclude delimiters:" << std::endl;
    while(sts.hasMore()) {
    	std::cout << '[' << sts.next() << ']' << std::endl;
    }
    std::cout << std::endl;
    
    return 1;
}
