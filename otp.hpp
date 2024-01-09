#include <string>
#include <utility>

using std::string;
using std::pair;

class OTP {

private:
    string alphabet;
    string key;

public:
    OTP(string key, string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
        this->alphabet = alphabet;
        this->key = key;
    }

private:
    bool contains(char needle, string haystack) {
        bool retval = false;
        if (haystack.find(needle) != string::npos) {
            retval = true;
        }
        return retval;
    }

    bool all_valid_letters(string in_str) {
        bool retval = true;
        for (int i = 0; i < in_str.length(); i++) {
            if (!contains(in_str[i], alphabet)) {
                retval = false;
                break;
            }
        }
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
        string a = in_str;
        string b = key;
        for (int i = 0; i < in_str.length(); i++) {
            encoded += alphabet[(a[i] + b[i]) % alphabet.length()];
        }
        return pair<string, string>("", encoded);
    }

    pair<string, string> decode(string in_str) {
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
        string a = key;
        string b = in_str;
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
