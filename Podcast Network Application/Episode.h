#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>

using namespace std;

//Episode Class
class Episode
{
  public:
    //overloaded constructor used to initialize the member variables of an episode object.
    Episode(const string& podcast, int number, const string& name, const string& content);

    //default constructor used to give default values to member variables of episode object.
    Episode();

    //functions used to output the member variables of episode objects.
    void play();
    void print();

  private:
    //member variables of an episode object.
    string name;
    string content;
    string podcast;
    int number;

};

#endif
