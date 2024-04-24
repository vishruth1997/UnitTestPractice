#include "Password.h"
#include <string>
#include <cctype>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using namespace std;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
Password::Password(){
  pass_history.push_back("ChicoCA-95929");
}

int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  if(phrase.length()==0){
    return 0;
  }
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}
// bool Password::has_mixed_case(string phrase){
//   bool is_upperCase = false;
//   bool is_lowerCase = false;
//   for (char ch : phrase) {
//       if(islower(ch)){
//         is_lowerCase = true;
//       }
//       if(isupper(ch)){
//         is_upperCase = true;
//       }
//   }
//   if(is_lowerCase && is_upperCase){
//     return true;
//   }
//   else{
//     return false;
//   }
// }

// Implementation A

// bool Password::has_mixed_case(string str)
// {
//   bool has_lower = false;
//   bool has_upper = false;
//   for (char ch : str)
//   {
//     if (std::islower(ch))
//     {
//       has_lower = true;
//     }
//     else if (std::isupper(ch))
//     {
//       has_upper = true;
//     }
//   }
//   return has_lower && has_upper;
// }
// Implementation B
// bool Password::has_mixed_case(string str)
// {
//   int count_lower = 0;
//   for (int i = 0; i < str.length(); i++)
//   {
//     if (str[i] >= 'a' && str[i] <= 'z')
//     {
//       count_lower++;
//     }
//   }
//   return count_lower > 0 && count_lower < str.length();
// }
// Implementation C
// bool Password::has_mixed_case(string str)
// {
//   bool lower = false;
//   bool upper = false;
//   for (int i = 0; i < str.length(); i++)
//   {
//     if (str[i] >= 'a' && str[i] <= 'z')
//     {
//       lower = true;
//     }
//     else if (str[i] >= 'A' && str[i] <= 'Z')
//     {
//       upper = true;
//     }
//   }
//   return upper && lower;
// }
// Implementation D
// #include <cctype>
// bool Password::has_mixed_case(string str)
// {
//   bool is_lower = false;
//   bool is_upper = false;
//   for (char c : str)
//   {
//     if (std::islower(c))
//     {
//       is_lower = true;
//     }
//     else
//     {
//       is_upper = true;
//     }
//   }
//   return is_lower && is_upper;
// }
// Implementation E
bool Password::has_mixed_case(string str)
{
  bool found = false;
  for(char c : str){
    if( !found && c >= 'A' && c <= 'Z' ){
      found = true;
    }
    else if( found && c >= 'a' && c <= 'z'){
      return true;
    }
  }
  return false;
}
void Password::set(string new_pass){
    // Check if the new password meets all criteria
  if (new_pass.length() >= 8 && new_pass.length() <= 20 &&
      count(new_pass.begin(), new_pass.end(), new_pass[0]) <= 3 &&
      any_of(new_pass.begin(), new_pass.end(), ::isupper) &&
      any_of(new_pass.begin(), new_pass.end(), ::islower) &&
      find(pass_history.begin(), pass_history.end(), new_pass) == pass_history.end()) {
      pass_history.push_back(new_pass);
      cout << "Password successfully updated." << endl;
  } else {
      cout << "Password does not meet the criteria or is a previous password." << endl;
  }

}
bool Password::authenticate(string input_pass){
    // Check if a password has been set
  if (pass_history.empty()) {
      cout << "No password has been set yet." << endl;
      return false;
  }

  // Check if the input password matches the latest password in history
  string latest_pass = pass_history.back();
  if (input_pass == latest_pass) {
      cout << "Authentication successful." << endl;
      return true;
  } else {
      cout << "Authentication failed: Incorrect password." << endl;
      return false;
  }
}