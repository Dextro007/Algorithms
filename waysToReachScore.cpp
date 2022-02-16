#include<iostream>
#define ll long long int 

ll count(ll n){
	ll table[n+1];
	memset(table, 0, sizeof(table));
	ll i;

	table[0] = 1;

	for(i=3; i<=n;  i++){
		table[i] = table[i] + table[i-3];
	}

	for(i = 5; i<= n; i++){
		table[i] = table[i] + table[i-5];
	}
	for(i = 10; i<=n; i++){
		table[i] = table[i] + table[i-10];
	}

	return table[n];
}

