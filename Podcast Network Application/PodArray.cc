
#include "PodArray.h"

//default constructor used to initialize default values to PodArray object.
PodArray::PodArray()
{
	numPods = 0;
	podcasts = new Podcast*[MAX_PODS];
}

//copy constructor used to make deep copy of PodArray object.
PodArray::PodArray(PodArray& pa)
{
	//create a new PodArray object.
	podcasts = new Podcast*[MAX_PODS];

	//add each podcast from the PodArray to the new copy.
	for (int i =0 ; i < pa.numPods; ++i)
	{
		podcasts[i] = new Podcast(*pa.podcasts[i]);
	}

	//set the number of pods equal to the copy.
	numPods = pa.numPods;

}

//destructor used to delete each podcast object from the podcast array
PodArray::~PodArray()
{
	//for loop to iterate and delete each podcast.
	for(int i =0; i<numPods;i++)
	{
		delete podcasts[i];
	}

	//deleting podcast aray.
	delete [] podcasts;

}

//addPodcast function used to add a podcast to the PodArray object.
bool PodArray::addPodcast(Podcast* p)
{
	//if thhe number of pods is greater than or equal to the max then return false.
	if (numPods >= MAX_PODS) return false;

	//iterate through the podcast array starting at the end
	for (int i = numPods; i > 0; --i)
	{
		//if the podcast being added is less than the second last element then set it equal to that position.
		if (p->lessThan(*podcasts[i-1]))
		{
			podcasts[i] = podcasts[i-1];
		}
		//otherwise sett the current index equal to the new podcast.
		else
		{
			//add the new podcast to the end of the array
			podcasts[i] = p;

			//increment number of podcasts.
			++numPods;

			//return true sincee podcast was added successfully.
			return true;
		}
	}
	//if the array is empty add the new podcast at the start.
	podcasts[0] = p;

	//increment number of podcasts.
	++numPods;

	//return true sincee podcast was added successfully.
	return true;
}

//removePodcast used to remove podcast from PodArray object.
bool PodArray::removePodcast(const string& title, Podcast** pod)
{
		int index = 0;
    //we want to find the index of the element to remove
    while(title != podcasts[index]->getTitle()&& index < numPods)
		{
        ++index;
    }

    //did we fall off the end of the array?
    if (index == numPods) return false;

    //we have found what we wanted to remove,
    //assign the output value
    *pod = podcasts[index];

    //copy everything after index left one position
    while (index < numPods - 1)
		{
        podcasts[index] = podcasts[index + 1];
        ++index;
    }
    --numPods;

		//return true if podcast was removed successfully.
    return true;
}

//getPodcast used to get a specific podcast from PodArray object.
bool PodArray::getPodcast(const string& title, Podcast** pod)
{
	//iterate through the podcasts array and check if any of the titles match the parameters.
	for(int i = 0; i < numPods;i++)
	{
		//if a match is found store the podcast and return true.
		if(podcasts[i]->getTitle() == title)
		{
			*pod = podcasts[i];

			return true;
		}
	}

	//return false if no matching podcast was found.
	return false;
}

//check if the podcasts array is full.
bool PodArray::isFull(){
	return numPods >= MAX_PODS;
}

//check the size of the podcast array.
int PodArray::size(){
	return numPods;
}

//print out the member variables of each podcasts.
void PodArray::print(){
	for (int i = 0; i < numPods; ++i){
		podcasts[i]->print();
	}
}
