/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef INVENTORY_H
#define INVENTORY_H
#include "StockItem.h"
#include<list>
#include<iterator>
using namespace std;
class Inventory {
public:
    
    Inventory();

    void insert(StockItem item);
    void printList();

private:
    list<StockItem> inventory;
};

#endif /* INVENTORY_H */

