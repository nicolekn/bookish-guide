/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StockProgram.cpp
 * Author: Noo
 *
 * Created on 28 March 2018, 11:52
 */

#include <cstdlib>
#include "StockItem.h"
#include "Inventory.h"
#include<iostream>
#include <fstream>
#include<sstream>
#include <string>
#include <cstring>
#include <algorithm> 
using namespace std;

/*
 * 
 */
bool comp(int a, int b)
{
    return (a < b);
}
int main(int argc, char** argv) {
    Inventory inventory_list;
    int resistor_count=0, capacitor_count=0, transistor_count=0, diode_count=0, ic_count=0,over_ten=0,NPN=0;
    ifstream infile;
    infile.open("inventory.txt");
    if (!infile) {
	cout << "Unable to open file";
	exit(1); // terminate with error
    }
    while(infile)
    {
        string type;
        string code;
        string stock_string;
        string price_string;
        int stock;
        int price;
        string extra;
        
        getline(infile,type, ',');
        getline(infile, code, ',');
        getline(infile,stock_string, ',');
        getline(infile,price_string,',');
        getline(infile,extra);
        
        stringstream s(stock_string);
        s>>stock;
        
        stringstream s2(price_string);
        s2>>price;
        cout<<type<<", "<<code<<", "<<stock<<", "<<price<<", "<< extra<<endl;
        
        if(type=="resistor")
        {
                Resistor item(type,code,stock,price,extra);
                inventory_list.insert(item);
                //cout<< "added resistor"<<endl;
                resistor_count++;
                if(price>10)
                {
                    over_ten++;
                }
        }
        else if (type  =="capacitor")
        {
                Capacitor item(type,code,stock,price,extra);
                inventory_list.insert(item);
                //cout<< "added capac"<<endl;
                capacitor_count++;
                if(price>10)
                {
                    over_ten++;
                }
        }
        else if(type == "transistor")
        {
                Transistor item(type,code,stock,price,extra);
                inventory_list.insert(item);
                //cout<< "added transistor"<<endl;
                transistor_count++;
                if(price>10)
                {
                    over_ten++;
                }
                cout<<extra<<endl;
                if (extra==" NPN")
                {
                    NPN++;
                }
        }
        else if (type =="diode")
        {
                Diode item(type,code,stock,price);
                inventory_list.insert(item);
                //cout<< "added diode"<<endl;
                diode_count++;
                if(price>10)
                {
                    over_ten++;
                }
        }
        else if (type == "IC")
        {
                IntegratedCircuit item(type,code,stock,price,extra);
                inventory_list.insert(item);
                //cout<< "added IC"<<endl;
                ic_count++;
                if(price>10)
                {
                    over_ten++;
                }
        }
        else
                cout<<"invalid type"<<endl;
        
    
        
    
    }
    inventory_list.printList();
    int largest_count=max({resistor_count, capacitor_count, transistor_count, diode_count, ic_count},comp);
    if(resistor_count==largest_count)
    {
        cout<<"There are the most resistors in stock with "<<resistor_count<<" resistors"<<endl;
    }
    if(capacitor_count==largest_count)
    {
        cout<<"There are the most capacitors in stock"<<capacitor_count<<" capacitors"<<endl;
    }
    if(transistor_count==largest_count)
    {
        cout<<"There are the most transistors in stock"<<transistor_count<<" transistors"<<endl;
    }
    if(diode_count==largest_count)
    {
        cout<<"There are the most diodes in stock"<<diode_count<<" diodes"<<endl;
    }
    if(ic_count==largest_count)
    {
        cout<<"There are the most integrated circuits in stock"<<ic_count<<" integrated circuits"<<endl;
    }
    
    cout<<"There are "<<over_ten<<" components with a price above 10p in stock."<<endl;
    cout<<"There are "<<NPN<< " NPN transistors in stock";
    return 0;
}

