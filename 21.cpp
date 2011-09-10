#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct Card{
  Card(char card){
    switch(card){
      case 49: this->value = 1; break;
      case 50: this->value = 2; break;
      case 51: this->value = 3; break;
      case 52: this->value = 4; break;
      case 53: this->value = 5; break;
      case 54: this->value = 6; break;
      case 55: this->value = 7; break;
      case 56: this->value = 8; break;
      case 57: this->value = 9; break;
      case 65: this->value = 11; break; // A
      case 74: this->value = 10; break; // J
      case 81: this->value = 10; break; // Q
      case 75: this->value = 10; break; // K
    };
  };

  int operator()(){
    return value;
  }

  int value;

  static bool sortMe(Card card1, Card card2){
    return (card1() > card2());
  };

};

int main(){
  unsigned short inputs_count = 0;
  cin >> inputs_count;
  char inputs[100][500];

  for(int i = 0; i < inputs_count; i++){
    cin >> inputs[i];
  }

  for(int i = 0; i < inputs_count; i++){
    vector<struct Card> cards;
    vector<struct Card>::iterator iter;

    for(int j = 0; j < strlen(inputs[i]); j++){
      cards.push_back( Card(inputs[i][j]) );
    }

    sort(cards.begin(), cards.end(), Card::sortMe);
    int highest_value1 = 0;
    int highest_value2 = 0;
    int check_two = 0;

    // for(iter = cards.begin(); iter != cards.end(); iter++){
    //   if(iter->value == 11){
    //     check_two = 1;
    //     break;
    //   }
    // }

    for(iter = cards.begin(); iter != cards.end(); iter++){
      if(iter->value == 11){

        for(vector<struct Card>::iterator iter2 = cards.begin(); iter2 != cards.end(); iter2++){
          int value = iter2->value;
          if(value == 11)
            value = 1;
            
          if(highest_value2 + iter2->value > 21)
            continue;

          highest_value2 += value;
        }
        // cout << "highest 2: " << highest_value2 << endl;
      }

      if(highest_value1 + iter->value > 21)
        continue;

      highest_value1 += iter->value;
    }

    // cout << "highest 1: " << highest_value1 << endl;

    cout << ((highest_value1 > highest_value2) ? highest_value1 : highest_value2) << endl;
  }

  return 0;
}