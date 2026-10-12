#pragma once //헤더가드
#include <iostream>

namespace HanYoonseo2649055
{
    class book
    {
    //private:
        int id;     
        int price;  //price: 0~50000 won
        void testID() //id: 1~1000
        {
            if(id < 1 || id > 1000)
            {
                std::cout << "Invalid book id\n";
                std::exit(1);
            }
        }
        void testPrice() //price: 0~50000 won
        {
            if(price < 0 || price > 50000)
            {
                std::cout << "Invalid book price\n";
                std::exit(1);
            }
        }
    public:
        book(int d = 1, int p = 0):id{d}, price{p}
        {
            testID(); testPrice();
        }

        void input()
        {
            std::cout << "Enter book id: ";
            std::cin >> id; testID();
            std::cout << "Enter book price: ";
            std::cin >> price; testPrice();
        }
        friend std::istream& operator>>(std::istream& is, book& b)
        {//book b; std::cout << "Enter book id price: ";std::cin >>b;
            // is >> b.id >>b.price; b.testID(); b.testPrice();
        //book b; std::cin >> b;
            std::cout << "Enter book id: ";
            is >> b.id; b.testID();
            std::cout << "Enter book price: ";
            is >> b.price; b.testPrice();
            return is;
        }
        void setID(int d){id = d; testID();}
        void setPrice(int p){price = p; testPrice();}
        void print() const
        {
            std::cout << id << "," << price <<"won\n";
        }
        friend std::ostream& operator<<(std::ostream& os, const book& b)
        {
            os << b.id << "," << b.price << "won\n";
            return os;
        }
        int getID() const {return id;}
        int getPrice() const {return price;}
        book operator++(){return book{id, price++};}
        book operator++(int)
        {
            book temp{id, price};
            price++;
            return temp;
            //return book{id, price++};
        }
        friend bool operator==(const book& b1, const book& b2)
        {
            return b1.id == b2.id && b1.price == b2.price;
        }
        friend int operator+(const book& b1, const book& b2)
        {
            return b1.price + b2.price;
        }

    };
} 
 


//friend std::istream& operator>>(std::istream& is, book& b)
//        {
//            return is;
//        }
//        friend std::ostream& operator<<(std::ostream& os, const book& b){return os;}
