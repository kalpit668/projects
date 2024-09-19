
#include <iostream>
#include <string>
#include "video.h"
using namespace std; 

// Add class contructor here...
Video::Video(string title, string url, string comment, float length, int rating){
    this->m_title=title;
    this->m_url=url;
    this->m_comment=comment;
    this->m_length=length;
    this->m_rating=rating;

}
bool Video::compareRatings(Video *otherVideo) {
    return otherVideo->m_rating > this->m_rating;
}

bool Video::compareLengths(Video *otherVideo) {
    return otherVideo->m_length < this->m_length;
}

bool:: Video::compareTitles(Video *otherVideo) {
    return otherVideo->m_title < this->m_title;
}

bool Video::compare(Video *otherVideo, string sort) {
    if (sort == "rating") {
        return compareRatings(otherVideo);
    } else if (sort == "length") {
        return compareLengths(otherVideo);
    } else if (sort == "title") {
        return compareTitles(otherVideo);
    }
    return false;
}


void Video::print()
{
  // the code for the print function goes here
    cout<<m_title<<", ";
    cout<<m_url<<", ";
    cout<<m_comment<<", ";
    cout<<m_length<<", ";;
    for (int i = 0; i < m_rating; i++)
    {
        cout<<"*";
    }
    // cout<<m_rating<<endl;;
    cout<<endl;
    
}
