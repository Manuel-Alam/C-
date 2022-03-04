#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "Network.h"

using namespace std;

//Client class.
class Client
{

	public:
		//Constructor used to initialize member variables of client class.
		Client(const string& name);

		//Destructor used to delete member variables and prevent memory leaks.
		~Client();

		//Download function used to download a podcast from the network.
		void download(Network* network, const string& podcast);

		//Stream function used to stream a podcast and episode from the network.
		void stream(Network* network,const string& podcast, int episode);

		//playLocal function used to play an episode locally from the network
		void playLocal(const string& podcast, int episode);

		//print function used to print the member variables from the cleitn.
		void print();

	private:
		//member variables.

		//client name
		string name;

		//store podcasts.
		PodArray* pointer;

};
#endif
