#include <iostream>
#include <queue>

using namespace std;

void addCharToString(const char c, string *newStrings) {
    string tmp = newStrings[0];
    int i, strLength = tmp.length();
    if (tmp.empty())
        return;
    for (i=0; i < strLength; i++) {
        newStrings[i] = tmp;
        newStrings[i].insert(newStrings[i].begin()+i,c);
    }
    tmp.push_back(c);
    newStrings[i] = tmp;
}
int main()
{
   queue<string> q;
   string empty, msg = "Worl";
   int i, progress = 0;
//   char firstChar = msg[progress]; 
//   string start(&firstChar);
   string start(1, msg[progress]);
   progress++;
   
   q.push(start);
   q.push(empty);
   while (progress < msg.length()) {
       string words[msg.length()+1] {empty};
       do {
           words[0] = q.front();
           q.pop();
           addCharToString(msg[progress], words);
           for (i = 0; !words[i].empty(); i++) {
               q.push(words[i]);
           }
       } while (!words[0].empty());
       q.push(empty);
       progress++;
   }

   while(!(empty = q.front()).empty()) {
        q.pop();
        cout << empty << endl;
   }
   
   return 0;
}

