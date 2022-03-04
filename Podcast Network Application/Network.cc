#include "Network.h"

//Network overloaded constructor used to initialize values of a network object.
Network::Network(string name)
{
  //initialize the member variables for a network object.
  this->name = name;
  pointer = new PodArray;
  numSubs = 0;

}

//Destructor used to delete the subscribers store in the static pointer array to prevent memeroy leaks.
Network::~Network()
{

  //for loop to delete each subscriber object in the pointer array.
  for(int i = 0; i < numSubs;i++)
	{
		delete subscriberPointers[i];
	}

  //deleting podarray to prevent memory leaks.
  delete pointer;

}

//getPodcast function checks if the PodArray contains the specific podcast and returns true or false.
bool Network::getPodcast(const string& title, Podcast** pod)
{
  //return whether the podcast exist or not
  return pointer->getPodcast(title,pod);
}

//addPodcast function usede to add a podcast to the network object.
bool Network::addPodcast(const string& title, const string& host)
{
  //return true or false regarding if the podcast was added successfully.
  return pointer->addPodcast(new Podcast(title, host));
}

//removePodcast function used to remove a podcast from a network object.
bool Network::removePodcast(const string& podcast)
{
  //podcast pointer used to traverse podarray.
  Podcast* pod;

  //store the condition for whether the podcast was removed successfull or not.
  bool removePod = pointer->removePodcast(podcast,&pod);

  //delete the podcast after.
  delete pod;

  //return true or false depending on the removal of the podcast.
  return removePod;
}

//addEpisode function used to add an episode  to the network object.
bool Network::addEpisode(const string& podcast, const string& title, const string& content)
{
  //podcast pointer used to traverse podarray.
  Podcast* pod;

  //if the podcast exist in podarray then return wheteher the episode was successfully added to the podcast.
  if(pointer->getPodcast(podcast,&pod))
  {
    //return true or false depending on success of adding an episode to podscast.
    return pod->addEpisode(title, content);
  }

  //return false if the podcast doesnt exist.
  return false;
}

//addSubscriber used to add a subscriber to network object.
bool Network::addSubscriber(const string& name, const string& creditcard)
{
  //if the number of subscribers is greater than or equal to the max subs dont add it.
  if(numSubs >= MAX_SUBS)
  {
    //return false since subscriber wasnt added.
    return false;
  }

  //add the subscriber to the subscriberpointers array.
  subscriberPointers[numSubs++] = new Subscriber(name,creditcard);

  //return true since subscriber was successfully added.
  return true;
}

//Download function used to download a podcast with network object.
bool Network::download(const string& subscriber, const string& podcast,Podcast** p)
{

  //check if the subscriber and podcast exists.
  bool hasSub = hasSubscriber(subscriber);
  bool hasPodcast = pointer->getPodcast(podcast,p);

  //if the subscriber doesn't exist then output error message and return false.
  if(hasSub == false)
  {
    cout<<"\nNo Such Subscriber";

    return false;

  }

  //if the podcast doesnt exist then output error message and return false.
  if(hasPodcast == false)
  {
    cout<<"\nNo Such Podcast";

    return false;

  }

  //return true if both the subscriber and podcast exist
  return true;

}

//stream function used to stream a podcast from a network object.
bool Network::stream(const string& subscriber, const string& podcast, int episode, Episode** ep)
{

  //podcast pointer used to traverse the podcasts.
  Podcast* pod;

  //if the podcast is not downloadable then return false.
  if(download(subscriber, podcast,&pod) == false)
  {
    //return false.
    return false;
  }

  //check if the episode exist in the podcast.
  bool hasEpisode = pod->getEpisode(episode,ep);

  //if the episode doesnt exist then return false and output error message.
  if(hasEpisode == false)
  {
    cout<<"\nNo Such Episode.";
    return false;
  }

  //return true if the podcast, subscriber, and episode exist.
  return true;

}

//hasSubscriber function used to check if network object has a specific subscriber.
bool Network::hasSubscriber(const string& name)
{
  //for loop to iterate through subscriberPointers array.
  for(int i = 0; i < numSubs;i++)
  {
    //if a subscriber's name in the array matches the name being looked for return true.
    if(subscriberPointers[i]->matches(name))
    {
      return true;
    }
  }

  //if the subscriber doesnt exist return false.
  return false;
}

//print function used to print the member variables of a network object.
void Network::print()
{
  //print the podcasts from the podarray.
  pointer->print();

  //print all the subscribers from subscriberPointers array.
  for(int i = 0; i < numSubs;i++)
  {
    subscriberPointers[i]->print();
  }
}
