//Brute Force or Naive String Matching algorithm. In this algorithm
#include<iostream>
#include<string>
using namespace std;

int main() {
  string str = "jumbo jumalienjumxy";
  string p = "jump";
  int i = 0, j;

  while (i <= str.length() - p.length()) {
    

    string temp = str.substr(i, p.length());//each time temp takes the part from main string 
    int flag = 0;

    for (int k = 0; k < p.length(); k++) {
      //now the temp check to the pattern
      if (temp[k] != p[k]) {
        break;
      } else {
        flag++;
      }
    }

    if (flag == p.length()) {
      cout << "Pattern found" << endl;
      return 0;
    }

    i++;
  }

  cout << "Not found" << endl;

  return 0;
  //T.n = O( (n-m) *m) = O(n*m) .n= size of str , m = size of pattern
}
