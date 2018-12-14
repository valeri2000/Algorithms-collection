#include <iostream>
#include <vector>

using namespace std;

const int RECIPIES=170641;

int main() {
	vector<int> v;
	v.push_back(3), v.push_back(7);

	int elf1=0, elf2=1;

	for(; (int)v.size()<RECIPIES+10;) {
		int csum=v[elf1]+v[elf2];
		if(csum<10) v.push_back(csum);
		else v.push_back(csum/10), v.push_back(csum%10);

		elf1+=(v[elf1]+1);
		elf1%=(int)v.size();
		elf2+=(v[elf2]+1);
		elf2%=(int)v.size();

		//for(auto i:v) cout<<i<<" ";
		//cout<<"| elf1="<<elf1<<", elf2="<<elf2<<'\n';
	}

	for(int i=RECIPIES; i<=RECIPIES+9; ++i) cout<<v[i];
	cout<<'\n';
	return 0;
}