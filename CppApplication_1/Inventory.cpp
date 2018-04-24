/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventory.cpp
 * Author: Noo
 * 
 * Created on 28 March 2018, 11:51
 */

#include "Inventory.h"
#include<list>
#include<iterator>
using namespace std;
Inventory::Inventory() {
    list<StockItem> inventory;
}


void Inventory::insert(StockItem item)
{
    inventory.push_back(item);
}
void Inventory:: printList()
{
    inventory.sort();
    cout<<"Size: "<<inventory.size()<<endl;
    list<StockItem>::iterator i = inventory.begin();
    while(i != inventory.end())
    {
        StockItem& s = *i;
        s.printItem();
        i++;
    }
}




