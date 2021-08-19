#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>

using namespace std;

vector<int> permVec;
vector<int> finalSeq1;
vector<int> finalSeq2;


int permCount = 0;
void permute(vector<int> arr, int start, int end) {
	
    if (start == end) {
		int sz = arr.size();
		string str1; 
		for(int i = 0;i<sz;i++) {
			//cout<<arr[i];
			str1 = str1 + to_string(arr[i]); 
		}
		stringstream toInt(str1);
		int x =  0;
		toInt>>x;
		permVec.insert(permVec.end(), x);
		permCount++;
	}
    else
    {
        for (int i = start; i <= end; i++)
        { 
            swap(arr[start], arr[i]);
 
            permute(arr, start+1, end);
        }
    }
}
 
 void printVector(vector<int> &vec) {
	
	for(int i = 0;i<vec.size();i++) {
		 cout<<vec[i]<<endl;
	 }
 }

void printBool(vector<bool> &vec) {
	
	for(int i = 0;i<vec.size();i++) {
		 cout<<vec[i]<<endl;
	 }
 }


bool checkValid(int p, int q, int sz) {
	int rem1, rem2;
	for(int i=0;i<sz;i++) {
		rem1 = p % 10;
		rem2 = q % 10;
			if(rem1 == 9 && rem2 == 9) {
				return false;
			}
		p = p/10;
		q = q/10;
	}
	return true;
}

void validCombs(vector<int> &vec1, vector<int> &vec2) {
			int valSeq = 0;
			for(int i = 0;i<vec1.size();i++) {
				for(int j = 0;j<vec2.size();j++) {
					if(checkValid(vec1[i], vec2[j], vec1.size() + vec2.size())) {
						finalSeq1.insert(finalSeq1.end(), vec1[i]);			//storing final values of sequences 
						finalSeq2.insert(finalSeq2.end(), vec2[j]);
						cout<<"Valid Sequence#"<<valSeq<<endl;
						cout<<vec1[i]<<"\n"<<vec2[j]<<endl;
						valSeq++;
					}
				}
			}
}

int removeDigit(int num, int rmplace) {
	int num1 = num;
	int divisor = pow(10,rmplace);
	int rem = pow(10,rmplace - 1);
	
	num = num/(divisor);
	num = num * divisor /10;
	num = num + num1%rem;
	
	cout<<"Req # = "<<num<<endl;
	return num;
	
}

int countDigit(int n) {
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

vector<int> correcting(int vec1, int vec2) {
	vector<int> retVec;
	vector<bool> spaceFlags1, spaceFlags2; 
	int rem1, rem2;
	int sz = countDigit(vec1[0]);
	cout<<"Size of Bool array="<<sz<<endl;
	for(int i = 0;i<sz;i++) {
		spaceFlags1.insert(spaceFlags1.begin() + i, false);
		spaceFlags2.insert(spaceFlags2.begin() + i, false);
	}
	
	
		for(int j=0;j<sz;j++) {
				rem1 = vec1 % 10;
				rem2 = vec2 % 10;
				cout<<"Vec1 = "<<i<<"--"<<vec1[i]<<endl;
				cout<<"Vec2 = "<<i<<"--"<<vec2[i]<<endl;
				cout<<"Rem1 = "<<i<<"--"<<rem1<<endl;
				cout<<"Rem2 = "<<i<<"--"<<rem2<<endl;
				
				
					if(rem1 == 9 && rem2 == 9) {
						spaceFlags1[j] = true;
						spaceFlags2[j] = true;
						cout<<"Value of i in IF = "<<j<<endl;
					}
				vec1 = vec1/10;
				vec2 = vec2/10;
			}
		cout<<"SpaceFlags1 = "<<endl;
		printBool(spaceFlags1);
		cout<<"SpaceFlags2 = "<<endl;
		printBool(spaceFlags2);
		
		for(i = 0;i<sz;i++) {
			
		}
	
	
}

void delSpaces(vector<int> &vec1, vector<int> &vec2) {
	vector<int> seqvec1, seqvec2;
	
	
	
}

int main() {

	vector<int> combSeq1;			// Will contain all possible combinations of sequence1
	vector<int> combSeq2;			// Will contain all possible combinations of sequence2
	vector<int> sequence1 = {29999};
	vector<int> sequence2 = {19989};
	/*
	int n = sequence1.size();				//Size of 1st sequence 
	int m = sequence2.size();				//Size of 2nd sequence
	
	for(int i = n;i<m+n;i++) {
		sequence1.insert(sequence1.begin() + i,9);
	}
	
	for(int i = m;i<m+n;i++) {
		sequence2.insert(sequence2.begin() + i,9);
	}
	
	n = sequence1.size();
	m = sequence2.size();
	
	permute(sequence1, 0, n-1);
	
	
	sort(permVec.begin(), permVec.end());
	vector<int>::iterator ip;
	ip = unique(permVec.begin(), permVec.begin() + permVec.size());
	permVec.resize(distance(permVec.begin(), ip));
	combSeq1 = permVec;

	permVec.clear();	
	permute(sequence2, 0, n-1);
	
	sort(permVec.begin(), permVec.end());
	vector<int>::iterator iq;
	iq = unique(permVec.begin(), permVec.begin() + permVec.size());
	permVec.resize(distance(permVec.begin(), iq));
	combSeq2 = permVec;
	*/
//	cout<<"Seq1 = "<<endl;
//	printVector(combSeq1);
//	cout<<"Seq2="<<endl;
//	printVector(combSeq2);
//	validCombs(combSeq1, combSeq2);
	delSpaces(sequence1, sequence2);
	
	return 0;
}



