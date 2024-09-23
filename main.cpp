//main.cpp file
//Sharma, Kalpit
//ksharma12
#include<iostream>  
#include "video.h"  //including video.h header file
#include "vlist.h"  //including video.h header file
using namespace std;
void read_input(Vlist &vlist) {
    string command;
    while (getline(cin, command)) {
       if (command == "insert") { // calling insert command
            string title, url, comment;
            float length;
            int rating;
            getline(cin, title);   // Read title
            getline(cin, url);     // Read URL
            getline(cin, comment); // Read comment
            cin >> length; 
            cin >> rating;
            cin.ignore(); // Ignore the remaining newline
            Video* video = new Video(title, url, comment, length, rating); //creating a new video object
            vlist.insert(video);
            }
        else if (command == "print") {
            vlist.print(); // calling print from vlist
            }
        else if (command == "length") {
            cout << vlist.length() << endl;  // calling length from vlist
            }
        else if (command == "lookup") {
            string title;
            getline(cin, title);
            vlist.lookup(title);   // calling lookup from vlist
        }
        else if (command == "remove") {
            string title;
            getline(cin, title);
            vlist.remove(title);    // calling remove from vlist
        }
        else {
            cerr << "<" << command << "> is not a legal command, giving up." << endl;   // calling error for illegal command
            exit(1);
        }
    }

}
int main(){
    Vlist vlist; // creating the vlist object
    read_input(vlist); 
    
    return 0;
}
