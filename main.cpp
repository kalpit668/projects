#include <iostream>
#include <algorithm> //this is used for swap
using namespace std;
// including the header file 
#include "video.h"
//calling the main function
int main() {
//declaring the input for sorting method    
string sort;
getline(cin, sort);
if (sort != "rating" && sort != "length" && sort != "title") {
        cerr << sort << " is not a legal sorting method, giving up." <<endl;
        return 1;
    }

    // cout<<sort<<endl;
const int MAX = 100;
// Declare and initialize an array of pointers to Video objects.
Video * videos[MAX]={NULL};
//declaring the video attributes for input
string title; 
string url; 
string comment; 
float length; 
int rating;

int video_count = 0;
//taking the inputs
while (getline(cin, title))
{
    if (video_count == 100)
    {
        cerr<<"Too many videos, giving up."<<endl;
        return 1;
    }
    getline(cin, url);
    getline(cin, comment);
    cin>>length;
    cin>>rating;
    cin.ignore();
    videos[video_count] = new Video(title, url, comment, length, rating);
    video_count=video_count+1;
}
//bubble sorting the video objects accoding to sorting method
for (int last = video_count - 1; last > 0; last--) {
        for (int cur = 0; cur < last; cur++) {
           if (videos[cur]->compare(videos[cur+1], sort)) {
                swap(videos[cur], videos[cur+1]);
            }
        }
    }
//print statementfor sorted list
for (int i = 0; i < video_count; ++i)
{
    videos[i]->print();
}
//removing all the files from heap
for (int i = 0; i < video_count; i++)
{
    delete videos[i];
}
}