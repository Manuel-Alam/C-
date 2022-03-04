#include "Podcast.h"

//Overloaded constructor to initialize all the member variables of a podcast object.
Podcast::Podcast(string title, string host)
{
	this->title = title;
	this->host = host;
	numEps = 0;
	episodePointers = new Episode*[MAX_EPS];

}

//copy constructor used to make a deep copy of a podcast object.
Podcast::Podcast(Podcast& pa)
{
	//copy the member variables.
	this->title = pa.title;
	this->host = pa.host;

	//set the size of the episode pointer array
	episodePointers = new Episode*[MAX_EPS];

	//add each episode to the copy.
	for (int i =0 ; i < pa.numEps; i++)
	{
		episodePointers[i] = new Episode(*pa.episodePointers[i]);
	}

	//set the number of episodes equal for the copy.
	numEps = pa.numEps;

}

//getter that returns that number of episodes.
int Podcast::getNumEpisodes()
{
	return numEps;
}

//destructor that deletes the episodePointers array and prevents memory leaks.
Podcast::~Podcast()
{
	//for loop to delete each element.
	for(int i =0; i<numEps;i++)
	{
		delete episodePointers[i];
	}

	//delete the array.
	delete [] episodePointers;

}

//getter for title member variable.
const string& Podcast::getTitle()
{
	return title;
}

//getter for host member variable.
const string& Podcast::getHost()
{
	return host;
}

//addEpisode function adds an episode to the episodePointers and returns checks if was successful.
bool Podcast::addEpisode(string title, string content)
{

	//if the number of episodes is greater than or equal to the max episodes then return false.
	if(numEps >= MAX_EPS)
	{
		return false;
	}

	//add new object to the episodePointers array.
	episodePointers[numEps++] = new Episode(this->title, numEps, title,content);

	//return true since new episode was added.
	return true;

}

//getEpisode retrieves the episode from the podcast and checks if it was successful or not.
bool Podcast::getEpisode(int index, Episode** ep)
{
	//if the index is valid then store the episode pointer and return true.
	if(index >= 0 && index <numEps)
	{
		//store the episode in the double pointer.
		*ep = episodePointers[index];

		//return true since episode was found.
		return true;
	}
	return false;
}

//lessThan function used to check if the title of the passed podcast is lexographically less than the current podcast.
bool Podcast::lessThan(Podcast& pod)
{
	//if the current title is greater than return true.
	if(this->title < pod.title)
	{
		return true;
	}

	//return false if current title is less than passed title.
	return false;
}

//print function used to print member variables of a podcast.
void Podcast::print()
{
	cout<<"\nTitle: "<< title;
	cout<<"\nHost: "<<host;
	cout<<"\nEpisodes: "<<numEps<<"\n";

	/*
	for(int i =0;i<numEps;i++)
	{
		episodePointers[i]->print();
	}
	*/
}
