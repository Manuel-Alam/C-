#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <iostream>
#include <string>

using namespace std;

//Subscriber class.
class Subscriber
{
  public:

    //overloaded constructor to initialize a Subscriber object's member variables
    Subscriber(string name, string creditcard);

    //check if a Subscriber objects name matches a string.
    bool matches(const string& name);

    //print the Subscriber object and it's member variables.
    void print();

  private:
    //member variables.
    string name;
    string creditcard;

};

#endif
