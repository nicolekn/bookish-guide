/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "StockItem.h"
#include<string>
#include<iostream>

using namespace std;

StockItem::StockItem() {
}

StockItem::StockItem(string new_type,string new_code,int new_number_in_stock,int new_price)
{
    type = new_type;
    code=new_code;
    number_in_stock=new_number_in_stock;
    price=new_price;
}

string StockItem::getType() const
{
    return type;
}

string StockItem::getCode() const
{
    return code;
}

int StockItem::getStock() const
{
    return number_in_stock;
}

int StockItem::getPrice() const
{
    return price;
}

void StockItem::printItem()
{
    cout<<type<<", "<< code << ", "<< number_in_stock<< ", "<< price<< " "<< endl;
}


