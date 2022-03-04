#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <string>
#include "PodArray.h"
#include "Subscriber.h"
#include "defs.h"

using namespace std;

//Network class
class Network
{

	public:

		//overloaded constructor used to initialize member variables of network object.
		Network(string name);

		//destructor used to delete memeber variables from network object and prevent memory leaks.
		~Network();

		//getters used to return wheter finding the podcast or subscriber were successful.
		bool getPodcast(const string& title, Podcast** podcast);
		bool getSubscriber(const string& name, Subscriber** subscriber);

		//addpodcast used to add a podcast to the array and return true or false if it was successful.
		bool addPodcast(const string& title, const string& host);

		//removepodcast used to remove a podcast from the array and check whether is was successful or not.
		bool removePodcast(const string& podcast);

		//addEpisode used to add an episode to the network object and check if it was successful or not.
		bool addEpisode(const string& podcast, const string& title, const string& content);

		//addSubscriber used to add a subscriber to the network object and check if it was successful or not.
		bool addSubscriber(const string& name, const string& creditcard);

		//download used to download a podcast to the network object.
		bool download(const string& subscriber, const string& podcast,Podcast**);

		//stream used to stream a podcast from the network object.
		bool stream(const string& subscriber, const string& podcast, int episode, Episode** ep);

		//hasSubscriber used to check if subscriber exist in network object.
		bool hasSubscriber(const string& name);

		//print function used to print member variables of a network object.
		void print();

	private:
		//member variables 
		string name;
		PodArray* pointer;
		Subscriber* subscriberPointers[MAX_SUBS];
		int numSubs;
};
#endif
