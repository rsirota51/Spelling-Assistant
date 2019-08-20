//Robert Sirota rsirota

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>


void name(std::map<std::string, int>& m, std::string& s1){
  std::string ans;
  for(std::map<std::string,int>::iterator itmap = m.begin(); itmap != m.end(); itmap++){
    if(itmap->first.find(s1) != std::string::npos){
      ans = itmap->first;
    }
    else if(s1.find(itmap->first) != std::string::npos){
      ans = itmap->first;
    }
    if(itmap->first.length()-s1.length() == 1){ // Input Less
      for(int x = 0; x < (int)s1.size(); x++){
        if(s1.at(x) != itmap->first.at(x)){
          if(itmap->first.substr(x + 1).find(s1.substr(x)) != std::string::npos){
            if(ans.empty() == false){
              if(itmap->second > m[ans]){
                ans = itmap->first;
              }
            }
            else{
              ans = itmap->first;
            }
          }
          else{
            break;
          }
        }
       }
      }
    else if(s1.length()-itmap->first.length() == 1){ // Input More
      for(int x = 0; x < (int)itmap->first.size(); x++){
        if(s1.at(x) != itmap->first.at(x)){
          if(s1.substr(x + 1).find(itmap->first.substr(x)) != std::string::npos){
            if(ans.empty() == false){
              if(itmap->second > m[ans]){
                ans = itmap->first;
              }
            }
            else{
              ans = itmap->first;
            }
          }
          else{
            break;
          }
        }
      }
    }
    else if(itmap->first.length() == s1.length()){ // Input Same
      for(int x = 0; x < (int)itmap->first.size(); x++){
        if(s1.at(x) != itmap->first.at(x)){
          if(s1.substr(x + 1).find(itmap->first.substr(x + 1)) != std::string::npos){
            if(ans.empty() == false){
              if(itmap->second > m[ans]){
                ans = itmap->first;
              }
            }
            else{
              ans = itmap->first;
            }
          }
          else{
            break;
          }
        }
      }
    }
  }
  if(ans.empty() == true){
    std::cout << "-" << "\n";
    m.insert(std::pair<std::string,int>(s1,1));
  }
  else{
    std::cout << ans << " " << m[ans] << "\n";
  }
}

int main(int argc, char* argv[]){
  std::string s;
  std::vector<std::string> invec;
  std::map<std::string, int> dictmap;
  std::ifstream f(argv[1]);
  while(getline(f, s)){
    std::string s1;
    s1 = s.substr(0, s.find(" "));
    int i = std::stoi(s.substr(s.find(" ") + 1));
    dictmap.insert(std::pair<std::string,int>(s1, i));
  }
  while(std::cin >> s){
    invec.push_back(s);
  }

  for(int x = 0; x < (int)invec.size(); ++x){
    if(dictmap.find(invec[x]) != dictmap.end()){
      std::cout << invec.at(x) << " " << dictmap[invec.at(x)]++ << "\n";
      //dictmap.find(invec[x])->second++;
    }
    else{
      name(dictmap,invec[x]);
    }
  }
  return 0;
}
