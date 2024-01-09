#include <string>
#include <utility>
#include <iostream>

using std::string;
using std::pair;
using std::cout;
using std::endl;

class OTP {

private:
    string alphabet;
    string key;

public:
    OTP(string key, string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
        this->alphabet = alphabet;
        this->key = key;
        cout << "alphabet:" << alphabet << endl;
        cout << "key:" << key << endl;
    }

private:
    bool contains(char needle, string haystack) {
        //cout << "contains(" << needle << ", " << haystack << ")" << endl;
        bool retval = false;
        if (haystack.find(needle) != string::npos) {
            retval = true;
        }
        //cout << " retval:" << retval << endl;
        return retval;
    }

    bool all_valid_letters(string in_str) {
        //cout << "all_valid_letters(" << in_str << ")" << endl;
        bool retval = true;
        for (int i = 0; i < in_str.length(); i++) {
            if (!contains(in_str[i], alphabet)) {
                retval = false;
                break;
            }
        }
        //cout << " retval:" << retval << endl;
        return retval;
    }

    int indexOf(char c, string s) {
        int retval = -1;
        for (int i=0; i < s.length(); i++) {
            if (s[i] == c) {
                retval = i;
                break;
            }
        }
        return(retval);
    }

public:
    pair<string, string> encode(string in_str) {
        cout << "encode(" << in_str << ")" << endl;
        string encoded = "";
        if (in_str.length() > key.length()) {
            return pair<string, string>("Text to encode must be shorter or the same length as the key.", "");
        }
        if (!all_valid_letters(in_str)) {
            return pair<string, string>("The string to encode has letters that are not in the alphabet.", "");
        }
        if (!all_valid_letters(key)) {
            return pair<string, string>("The key has letters that are not in the alphabet.", "");
        }
        string a;
        string b;
        a = in_str;
        b = key;
        //for (int i = 0; i < in_str.length(); i++) {
            //a += alphabet[indexOf(in_str[i], alphabet)];
            //b += alphabet[indexOf(key[i], alphabet)];
        //}
        cout << "a:" << a << endl;
        cout << "b:" << b << endl;
        for (int i = 0; i < in_str.length(); i++) {
            encoded += alphabet[(a[i] + b[i]) % alphabet.length()];
        }
        return pair<string, string>("", encoded);
    }

    pair<string, string> decode(string in_str) {
        cout << "decode(" << in_str << ")" << endl;
        string decoded = "";
        if (in_str.length() > key.length()) {
            return pair<string, string>("Text to decode must be shorter or the same length as the key.", "");
        }
        if (!all_valid_letters(in_str)) {
            return pair<string, string>("The encoded string has letters that are not in the alphabet.", "");
        }
        if (!all_valid_letters(key)) {
            return pair<string, string>("The key has letters that are not in the alphabet.", "");
        }
        string a;
        string b;
        a = key;
        b = in_str;
        cout << "a:" << a << endl;
        cout << "b:" << b << endl;
        int x = 0;
        for (int i = 0; i < in_str.length(); i++) {
            int c = a[i] - b[i];
            x = 0;
            if (c < 0) {
                x = alphabet.length() + c;
            } else {
                x = c % alphabet.length();
            }
            decoded += alphabet[x];
        }
        return pair<string, string>("", decoded);
    }
};
