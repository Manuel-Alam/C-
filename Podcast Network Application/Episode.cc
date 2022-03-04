#include "Episode.h"

//Episode overloaded constructor used to initialize the member variables of an episode object.
Episode::Episode(const string& podcast, int number, const string& name, const string& content)
{
	//initializing all the member variables of episode object.
	this->podcast = podcast;
	this->number = number;
	this->name = name;
	this->content = content;
}

//Episode default constructor used to initialize default values for an episode object.
Episode::Episode()
{
	podcast = "N/A";
	number = 0;
	name = "N/A";
	content = "N/A";
}

//Play function used to output the member variables of an episode object.
void Episode::play()
{
	cout<< "\nPodcast: "<<podcast;
	cout<< "\nEpisode: "<<name<< " \nEpisode Number: "<<number;
	cout<<"\nContent: "<<content<<"\n";
}

//Print function used to call an episode and print its values.
void Episode::print()
{
	play();
}
