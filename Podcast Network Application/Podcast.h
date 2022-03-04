#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Episode.h"

using namespace std;

//podcast class.
class Podcast
{
  public:
    //overloaded constructor used to initialize member variables of podcast object.
    Podcast(string title, string host);

    //copy constructor used to create a copy of the passed podcast object.
    Podcast(Podcast&);

    //destructor used to delete member variables and prevent memory leaks.
    ~Podcast();

    //getters used to retrieve member variables.
    const string& getTitle();
    const string& getHost();
    int getNumEpisodes();

    //addEpisode adds an episode object to the episodePointers array.
    bool addEpisode(string title, string content);

    //getEpisode checks if the episode exists and stores the episode.
    bool getEpisode(int index, Episode** ep);

    //checks if the title of a podcast is longer than another podcast.
    bool lessThan(Podcast& pod);

    void print();

  private:
    //member variables.
    string title;
    string host;
    Episode **episodePointers;
    int numEps;

};

#endif
