//1910 remove all occurrences of a substring in a string
#include<iostream>
#include<string>
using namespace std;

    void removeOccurrences(string &s, string part) {


        while( s.find(part) != string::npos){
            //npos not present then erase the part 
            s.erase( s.find(part) , part.length() );
            //s.find(part) -->retunr starting index of part
        }

        
    }
int main(){
    string str = "anjan das anjan das";
    string substr = "da";
    removeOccurrences(str,substr);
    cout<<str;

}