#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);


int hashvalue (char c){
    /*the hash value is calculated using ASCII values in a such a way that a = 0 and z will be 25, so that an hashtable     can be constructed with low space complexity  */
    return int(c)- 'a';
}

string twoStrings(string s1, string s2) {
    auto * s1_letters = new string[26];
    auto* s2_letters = new string[26];

    for (int i =0 ; i <26 ; i++){
        /*All the values in the hash table is innitially set to "No letter", this is done to avoid errors when comparing
        the values later. */
        s1_letters[i] = "No letter";
        s2_letters[i] = "No letter";
    }

    bool found  = false;   //a flag to denote whether we found a substring
    for (char c : s1){
        int value = hashvalue(c);
        s1_letters[value]= c;
    }

    for (char c : s2){
        int value = hashvalue(c);
        s2_letters[value]= c;
    }

    for (int i = 0 ; i <26 ; i++){
        if (s1_letters[i] != "No letter" and s2_letters[i] != "No letter" and s1_letters[i]== s2_letters[i]){
            found = true;
            break;
        }
    }

    if (found){
        return "YES";
    }
    else return "NO";
}

int main(){
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);
        cout << result << "\n";
    }
    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );
    return s;
}
