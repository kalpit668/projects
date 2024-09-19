
#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <string>
using namespace std;

class Video
{
 public:
  // public member functions go here
  Video(string title, string url, string comment, float length, int rating);
  bool compareRatings(Video *otherVideo);
  bool compareLengths(Video *otherVideo);
  bool compareTitles(Video *otherVideo);
  bool compare(Video *otherVideo, string sort);
  void print();
  
 private:
  // member variables go here
    string m_title;
    string m_url;
    string m_comment;
    float m_length;
    int m_rating;
  // member function used only by other member functions go here

};

#endif
