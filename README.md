#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() 
{
    string filename;
    cin>>filename;
    set<string> ans;
    ifstream file(filename); 
    string line; 
    if (file.is_open()) { 
        while (getline(file, line)) { 
            if(line.find("200")!=string::npos){
              if(line.find(".GIF")!=string::npos){
                int index=line.find(".GIF");
                int x=index;
                while(line[x]!='/'){
                  x--;
                }
                string name=line.substr(x+1,index-x-1)+".GIF";
                ans.insert(name);
              }
              if(line.find(".gif")!=string::npos){
                int index=line.find(".gif");
                int x=index;
                while(line[x]!='/'){
                  x--;
                }
                string name=line.substr(x+1,index-x-1)+".gif";
                ans.insert(name);
              }
            }
        }
        file.close();
    }
    for(auto i:ans) cout<<i<<endl;
    return 0;
}
