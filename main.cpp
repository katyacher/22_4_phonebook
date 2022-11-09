#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

bool is_phone_number(std::string number);

void name_search(std::map<std::string, std::string>& myMap, std::string key);
void phone_search(std::map<std::string, std::vector<std::string>>& myMap, std::string key);
void print_map(std::map<std::string, std::vector<std::string>>& myMap);

int main() {
    std::cout << "22.1 Phonebook\n";

    std::map<std::string, std::string> Num_key_phonebook = {{"69-70-30", "Ivanov" },
                                                            {"77-77-77", "Ivanov" },
                                                            {"70-70-70", "S.J.Connor"}};

    std::map<std::string, std::vector<std::string>> Name_key_phonebook = {{"Ivanov" , {"69-70-30", "77-77-77" }},
                                                                   {"S.J.Connor", {"70-70-70"}}};

    std::string request, first_word = "", second_word = "";
    std::cout << "Enter your request: ";
    std::getline(std::cin, request);
    std::stringstream data(request);
    data >> first_word >> second_word;

    if(!is_phone_number(first_word)){
        phone_search(Name_key_phonebook, first_word);
    } else if(second_word == ""){
        name_search(Num_key_phonebook, first_word);
    } else {
        std::pair<std::map<std::string, std::string>::iterator,bool> ret;
        ret = Num_key_phonebook.insert(std::pair<std::string, std::string>(first_word, second_word));
        if( ret.second == false){
            std::cout << "This phone number is already in the phonebook";
            std::cout << " with a name " << ret.first->second << std::endl;
        } else{
            Name_key_phonebook[second_word].push_back(first_word);
            std::cout << "User added successfully." << std::endl;
        }
    }
    std::cout << "Phonebook (name_key): " << std::endl;
    print_map(Name_key_phonebook);
    return 0;
}


bool is_phone_number(std::string number){
    for(int i = 0; i < number.length(); i++){
        if((number[i] < '0' || number[i] > '9') && number[i] != '-') return false;
    }
    return true;
}


void phone_search(std::map<std::string, std::vector<std::string>>& myMap, std::string key){
    std::map<std::string, std::vector<std::string>>::iterator it = myMap.find(key);
    if(it != myMap.end()){
        for(auto& value: it->second){
            std::cout << value << " ";
        }
    } else {
        std::cout <<  "There is no user with this phone number" << std::endl;
    }
}
void name_search(std::map<std::string, std::string>& myMap, std::string key){
    std::map<std::string, std::string>::iterator it = myMap.find(key);
    if(it != myMap.end()){
        std::cout << it->second << std::endl;
    } else {
        std::cout <<  "There is no user with this phone number" << std::endl;
    }
}
 void print_map(std::map<std::string, std::vector<std::string>>& myMap){
     std::map<std::string, std::vector<std::string>>::iterator it;
     for (it = myMap.begin(); it != myMap.end(); ++it)
     {
         std::cout << it->first << ": ";
         for(auto& item: it->second){
             std::cout << item << " ";
         }
         std::cout << std::endl;
     }
}