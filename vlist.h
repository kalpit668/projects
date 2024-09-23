//main.cpp file
//Sharma, Kalpit
//ksharma12
#ifndef VLIST_H
#define VLIST_H

#include "video.h"

class Vlist {
private:
  class Node {
  public:
    Video *m_video;
    Node *m_next;
    Node(Video *video, Node *next) { m_video = video; m_next = next; }
    
  };
  Node *m_head;
  public:
    Vlist() { m_head = NULL; }
    //declaration of all the methods available for the client
    bool contains(const string &title);
    void insert(Video *video);
    void print() const;
    int length() const;
    void lookup(const std::string& title) const;
    void remove(const std::string& title);
    //calling the destructor
    ~Vlist();
};
#endif
