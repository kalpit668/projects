//main.cpp file
//Sharma, Kalpit
//ksharma12
#include "vlist.h" 
#include<iostream>
#include<string>
using namespace std;
//Destructor function
Vlist::~Vlist() {
    Node* current = m_head;
    while (current) {
        Node* next = current->m_next;
        delete current->m_video;
        delete current;
        current = next;
    }
}
//function to check if the list already has an object with the same title
bool Vlist::contains(const string &title) {
    Node *current = m_head; // Start at the head of the linked list
    while (current != nullptr) {
        if (current->m_video->get_title() == title) {
            return true;  // Title already exists
        }
        current = current->m_next;  // Move to the next node
    }
    return false;  // Title not found
}
// inserting a video object in the list
void Vlist::insert(Video* video) {
    Node* newNode = new Node{video, nullptr};
    if (contains(video->get_title())) { // checking the presence of title
        cerr << "Could not insert video <" << video->get_title() << ">, already in list." << endl;
        delete video;  // Since we're not inserting, delete the video to avoid a memory leak
        return;
    }
    else if (!m_head || video->get_title() < m_head->m_video->get_title()) { // comparing at he head
        newNode->m_next = m_head;
        m_head = newNode;
    } else {        // comparing for the rest of the linked list
        Node* current = m_head;
        while (current->m_next && current->m_next->m_video->get_title() < video->get_title()) {
            current = current->m_next;
        }
        newNode->m_next = current->m_next;
        current->m_next = newNode;
    }
}
// print the entire list
void Vlist::print() const {
    Node* current = m_head;
    while (current!=nullptr) {
        current->m_video->print();
        current = current->m_next;
    }
}
//lookup for the video object using title
void Vlist::lookup(const string& title) const{
    Node* current = m_head;
    while (current!=nullptr) {
        if (current->m_video->get_title() == title) {
            current->m_video->print();
            return;
        }
        current = current->m_next;
    }
    cerr << "Title <" << title << "> not in list." << endl;
}
// remove the video object using title
void Vlist::remove(const string& title) {
    Node* current = m_head;
    Node* prev = nullptr;
    while (current!=nullptr) {
        if (current->m_video->get_title() == title) {
            if (prev) {
                prev->m_next = current->m_next;
            } else {
                m_head = current->m_next;
            }
            delete current->m_video;
            delete current;
            return;
        }
        prev = current;
        current = current->m_next;
    }
    cerr << "Title <" << title << "> not in list, could not delete." << endl;
}
// finding the length of the list
int Vlist::length() const{
    int count = 0;
    Node* current = m_head;
    while (current!=nullptr) {
        count++;
        current = current->m_next;
    }
    return count;
}
