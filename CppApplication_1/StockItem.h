/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<string>
#include <cstdlib>
#include<iostream>
#ifndef STOCKITEM_H
#define STOCKITEM_H
using namespace std;
class StockItem {
protected:
    string type;
    string code;
    int number_in_stock;
    double price;
public:
    StockItem();
    StockItem(string type, string code,int number_in_stock,int price);
    string getType() const;

    string getCode() const;

    int getStock() const;
    
    int getPrice()const; 
    
    virtual void printItem();
    
    bool operator < (const StockItem item) const
    {
        return price < item.price;
    }
};


class Resistor: public StockItem
{
private:
    string resistance;
public:
    Resistor(string type, string code,int number_in_stock,int price, string this_resistance)
        :StockItem(type, code,number_in_stock,price),
        resistance(this_resistance)
        {}
        string getResistance()
        {
            return resistance;
        }
        void printItem()
        {
            cout<<type<<", "<< code << ", "<< number_in_stock<< ", "<< price<< ", "<< resistance<< endl;
        }
};

class Transistor: public StockItem
{
private:
    string trans_type;
public:
    Transistor(string type, string code,int number_in_stock,int price, string trans_type)
    :StockItem(type, code, number_in_stock, price),
            trans_type(trans_type)
    {}
    
    string getTransType()
    {
        return trans_type;
    }
    
    void printItem()
        {
            cout<<type<<", "<< code << ", "<< number_in_stock<< ", "<< price<< ", "<< trans_type<< endl;
        }
};

class Capacitor: public StockItem
{
private:
    string capacitance;
public:
    Capacitor(string type, string code,int number_in_stock,int price, string capacitance)
    :StockItem(type, code, number_in_stock, price),
            capacitance(capacitance)
    {}
    string getCapacitance()
    {
        return capacitance;
    }
    
    void printItem()
        {
            cout<<type<<", "<< code << ", "<< number_in_stock<< ", "<< price<< ", "<< capacitance<< endl;
        }
};


class Diode: public StockItem
{
public:
    Diode(string type, string code,int number_in_stock,int price)
    :StockItem(type, code, number_in_stock, price)
    {}
    
    void printItem()
        {
            cout<<type<<", "<< code << ", "<< number_in_stock<< ", "<< price<< " "<< endl;
        }
};
class IntegratedCircuit: public StockItem
{
private:
    string description;
public:
    IntegratedCircuit(string type, string code,int number_in_stock,int price, string desc)
    :StockItem(type, code, number_in_stock, price),
            description(desc)
    {}
    string getDescription()
    {
        return description;
    }
    
    void printItem()
        {
            cout<<type<<", "<< code << ", "<< number_in_stock<< ", "<< price<< ", "<< description<< endl;
        }
};
#endif /* STOCKITEM_H */

