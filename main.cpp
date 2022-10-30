#include <iostream>
#include <map>
#include <string>
#include <sstream>// переделать - не по тз

bool is_phone_number(std::string number);

void search_name(std::map<std::string, std::string>& myMap, std::string key);

bool search_number(std::map<std::string, std::string>& myMap, std::string value);

void add(std::map<std::string, std::string>& myMap, std::string key, std::string value);

void print_map(std::map<std::string, std::string>& myMap);

int main() {
  std::cout << "22.1 Phonebook\n";

  std::map<std::string, std::string> Phonebook = {{"69-70-30", "Ivanov" },
                                                  {"77-77-77", "Ivanov" },
                                                  {"70-70-70", "S.J.Connor"}};

  std::string request, phone_number = "", name = "";
  std::cout << "Enter your request: ";
  std::getline(std::cin, request);
  std::stringstream data(request);
  data >> phone_number >> name;//std::cin или getline()

  if(!is_phone_number(phone_number)){
    name = phone_number;
    if(!search_number(Phonebook, name))
        std::cout << "There is no user with this name";
  } else if(name == ""){
    search_name(Phonebook, phone_number);
  } else {
      add(Phonebook, phone_number, name);
  }

  std::cout << std::endl << "Check yor phonebook? y/n: ";
  std::string answer;
  std::cin >> answer;
  if(answer == "y") print_map(Phonebook);

}


//поиск по ключу
void search_name(std::map<std::string, std::string>& myMap, std::string key){
  std::map<std::string, std::string>::iterator it = myMap.find(key);
  if(it != myMap.end()){//или nullptr?
    std::cout << it->second << std::endl;
  } else {
    std::cout <<  "There is no user with this phone number" << std::endl;
  }
}
//поиск по значению
bool search_number(std::map<std::string, std::string>& myMap, std::string value){
    bool searched = false;
    for(std::map<std::string, std::string>::iterator it = myMap.begin(); it!= myMap.end(); ++it){
        if(it->second == value){
            searched = true;
            std::cout << it->first << " ";
        }
    }
    return searched;
}

//вставка в map
void add(std::map<std::string, std::string>& myMap, std::string key, std::string value){
   myMap.insert(std::pair<std::string, std::string>(key, value));
  //нужно проверить, произошла ли вставка?
}


bool is_phone_number(std::string number){
  for(int i = 0; i < number.length(); i++){
    if((number[i] >= '0' && number[i] <= '9') || number[i] == '-') return true;
  }
  return false;
}
void print_map(std::map<std::string, std::string>& myMap){
    for(std::map<std::string, std::string>::iterator it = myMap.begin(); it!= myMap.end(); ++it){
        std::cout << it->first << " " << it->second << std::endl;
    }
}