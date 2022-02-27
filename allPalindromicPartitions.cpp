/*
 * Here the appproach is quite simple go through string of all length 
 * and keep checking if it is palindromic or not
 * */

#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

bool checkPalindrome(string s){
	int n = s.length();
	bool flag = true;
	for(int i=0; i<n/2; i++){
		if(s[i] != s[n-1-i]){
			flag = false;
			return flag;
		}
	}
	return flag;
}

vector<vector<string>> allPalindromicPerms(string s){
	vector<vector<string s>> result;
	vector<string> s;
	

