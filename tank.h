// tank.h
#ifndef TANK_H_INCLUDED
#define TANK_H_INCLUDED

#include <iostream>
#include <list>
#include <random>

using namespace std;

class Tank:public Vehicle{
public:
    Tank(){}
    Tank(int t){Tid = t;}
    void display(){
        cout<<"Tank: ";
        Vehicle::display();
    }
    void addParts(default_random_engine* gptr){
        uniform_int_distribution<int> Pdist(1,100);
        normal_distribution <double> Ndist(3,1);   ///mean and std div
          for(int i = 1; i < 12; i++){
            int mean = (int)Ndist(*gptr);
            int p = Pdist(*gptr);
                if(p > 66){
                    bParts.push_back(mean * Tid);
                }
                else{
                    gParts.push_back(mean * Tid);
                }
        }
    }/*

    normal_distribution <double> Ndist(50,10);   ///mean and std div
    queue <int> MyInts;
    priority_queue <int> MyPQ;

    int  Ival;

    for(int i=0; i<10; i++)
    {
        Ival = (int)Ndist(*gptr);
        MyInts.push(Ival);
    }
    void displayParts(){
        cout<<"Tank: = "<<endl;
        Vehicle::display();
        Litr = Ilist.begin();
        cout<<" Accept list [ ";
        while(Litr!=Ilist.end()){
            cout<<*Litr;
            Litr++;
            if(Litr!=Ilist.end()){cout<<", ";}
            else{cout<<" ";}
        }
        cout<<" ] "<<endl;
        cout<<" Reject list [ ";
        Litr=Flist.begin();
        while(Litr!=Flist.end()){
            cout<<*Litr;
            Litr++;
            if(Litr!=Flist.end()){cout<<", ";}
            else{cout<<" ";}
        }
        cout<<" ] "<<endl<<endl;
    }
    void init(){
        Ilist.sort();
        Ilist.unique();
        Flist.sort();
        Flist.unique();
    }*/
};

#endif // TANK_H_INCLUDED
