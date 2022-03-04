#include "Client.h"

//Client overloaded constructor to initialize client name and PodArray pointer.
Client::Client(const string& name)
{
  //initializing name of client and, PodArray pointer
  this->name = name;
  pointer = new PodArray;
}

//Destructor to delete PodArray pointer to ensure no memory leaks occur
Client::~Client()
{
  delete pointer;
}

//Download function, which will download a podcast from the network.
void Client::download(Network* network, const string& podcast)
{
  //Podcast pointer used to traverse podcasts in the network.
  Podcast* pod;

  //if the network successfully downloads the podcast from the network, then add the podcast to the client's PodArray.
  if(network->download(this->name, podcast,&pod))
  {
    cout<<"\nDownload Successful.\n";

    //add the podcast to the PodArray pointer using the copy constructor.
    pointer->addPodcast(new Podcast(*pod));
  }

  //If the download doesn't work than an error message is outputted.
  else
  {
    cout<<"\nError Downloading Podcast From Network";
  }

}

//Stream function, which will stream a specific episode from a podcast in the network
void Client::stream(Network* network,const string& podcast, int episode)
{
  //Episode pointer used to traverse episodes in the podcast from the network
  Episode* ep;

  //if the network successfully streams the episode, then output the contents of the episode.
  if(network->stream(this->name, podcast, episode, &ep))
  {
    cout<<"\nStream Successful.\n";
    ep->play();
  }

}

//playLocal function, which will play an episode locally.
void Client::playLocal(const string& podcast, int episode)
{
  //podcast and episode pointer used to traverse their respective arrays.
  Podcast* pod;
  Episode* ep;

  //if the podcast exists then check if the episode exist in that podcast, and output the episode if it exists.
  if(pointer->getPodcast(podcast,&pod))
  {
    //check if the epsiode exists in the podcast
    if(pod->getEpisode(episode, &ep))
    {
      //outputing details of the episode
      ep->play();
    }
  }

}

//print method used to print client info.
void Client::print()
{
  //printing client name.
  cout<<this->name;

  //printing info of podcasts.
  pointer->print();
}
