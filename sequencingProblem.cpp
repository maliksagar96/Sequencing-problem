/*
To run this code copy past the following commands in linux terminal one by one 
1st command  --> g++ sequencingProblem.cpp -o main.out
2nd command --> ./main.out

The program will ask you 3 things 
1) 1st sequence 
2) 2nd Sequence
3) If you want to print all the possible sequences or not

PLEASE 	ENTER BOTH THE SEQUENCES IN CAPS.
For example you want sequence 1 to be GC then GC should be in caps and not gc.

IF YOU WANT TO PRINT OUT ALL THE POSSIBLE COMBINATIONS OF 
SEQUENCES THEN WHEN 3RD INPUT IS ASKED PLEASE ENTER 1 ELSE ENTER 0. 

*/

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

void printSeq(vector<int> &vec1, vector<int> &vec2) {
	int count = 1;
	for(int i = 0;i<vec1.size();i++) {
		for(int j=0;j<vec2.size();j++){
			cout<<"Seq#"<<count<<endl;
			cout<<vec1[i]<<endl;
			cout<<vec2[j]<<endl;
			count++;
		}
	}
}

vector<int> combs(vector<int> &vec1, vector<int> &vec2) {
	int count = 0;
	vector<int> dd;		//doubleDecker vector
	for(int i = 0;i<vec1.size();i++) {
		for(int j=0;j<vec2.size();j++){
			dd.insert(dd.begin() + count,vec1[i]);
			dd.insert(dd.begin() + count+1,vec2[j]);
			count = count + 2;
		}
	}
	return dd;
}

void printVector(vector<int> &vec) {
	
	for(int i = 0;i<vec.size();i++) {
		 cout<<vec[i]<<endl;
	 }
 }

void permute(vector<int> arr, int start, int end) {
	
    if (start == end) {
		int sz = arr.size();
		string str1; 
		for(int i = 0;i<sz;i++) {
			//cout<<arr[i]<<endl;
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
	//printVector(permVec);
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

//contains combinations with no spaces aligned
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

int deleteFromStart(int num, int n) { 
    int d = log10(num) + 1;
    int revNewnum = 0;
    int newNum = 0;

    for (int i = 0; num != 0; i++) {
        int digit = num % 10;
        num = num / 10;
 
        if (i == (d - n)) {
            continue;      
		}
        else {
            revNewnum = (revNewnum * 10) + digit;
        }
    }
	 
    for (int i = 0; revNewnum != 0; i++) {
        newNum = (newNum * 10)
                  + (revNewnum % 10);
        revNewnum = revNewnum / 10;
    }
    
	return newNum;
	return newNum;
}
	
string numToSeq(int num){
	
	int sz = countDigit(num);
	int rem, len;
	string temp;
	string sequence;
	while(num != 0){
		rem = num%10;
		
		if(rem == 9)	  temp = "_";
		else if(rem == 1) temp = "A";
		else if(rem == 2) temp = "C";
		else if(rem == 3) temp = "G";
		else if(rem == 4) temp = "T";
		
		sequence = sequence + temp; 
		num = num/10;
	}
	len = sequence.length();
    for (int i = 0; i < len / 2; i++) {
		swap(sequence[i], sequence[len - i - 1]);
	}
        
	return sequence;
}

void printFinalSeq(vector<int> &vec, bool printFlag){
	int counter = 1;
	for(int i=0;i<vec.size()-1;i++){
		if(printFlag) {
			cout<<"Seq #"<<counter<<endl;
			cout<<numToSeq(vec[i])<<endl;
			cout<<numToSeq(vec[i+1])<<endl;
		}
		counter++;
		i++;
	}
	cout<<"The total Number of possible combinations = "<<counter-1<<endl;
}

//Correcting the sequences with spaces aligned
vector<int> correcting(int vec1, int vec2) {
	vector<int> retVec;
	vector<bool> spaceFlags1, spaceFlags2; 
	int correctInt1 = vec1;
	int correctInt2 = vec2;
	int rem1, rem2;
	int sz = countDigit(vec1);
	
	for(int i = 0;i<sz;i++) {
		spaceFlags1.insert(spaceFlags1.begin() + i, false);
		spaceFlags2.insert(spaceFlags2.begin() + i, false);
	}
	
	for(int i=0;i<sz;i++) {
			rem1 = vec1 % 10;
			rem2 = vec2 % 10;
			
				if(rem1 == 9 && rem2 == 9) {
					spaceFlags1[i] = true;
					spaceFlags2[i] = true;
					
				}
			vec1 = vec1/10;
			vec2 = vec2/10;
	}
	
	for(int i = 0;i<sz;i++) {
		
		if(spaceFlags1[i] && spaceFlags2[i]){
			correctInt1 = deleteFromStart(correctInt1, sz-i);
			correctInt2 = deleteFromStart(correctInt2, sz-i);
		}
	}
	retVec.insert(retVec.begin(), correctInt1);
	retVec.insert(retVec.end(), correctInt2);
	return retVec;
}
 
vector<int> rmAligned9(vector<int> &vec) {
	vector<int> temp,retVec;
	
	for(int i=0;i<vec.size()-1;i++) {
		temp = correcting(vec[i], vec[i+1]);
		retVec.insert(retVec.begin()+i, temp[0]);
		i++;
		retVec.insert(retVec.begin()+i, temp[1]);
		temp.clear();
	}	
	
	return retVec;
}
//to remove repeating sequences 
vector<int> correctedSeq(vector<int> &vec) {
	vector<int> temp = vec;
	vector<int> temp2;
	int pointer = 0;
	int counter = 0;
	
	for(pointer = 0;pointer<vec.size()-2;pointer++){
		for(int i = pointer+2;i<vec.size();i++) {
	
		
			if((vec[i] == vec[pointer]) && (vec[i+1] == vec[pointer+1])) {
					temp[i] = 0;
					temp[i+1] = 0;
			}
			i++;
		}
		pointer++;
	}
	
	for(int i=0;i<temp.size();i++) {
		if(temp[i] != 0) {
			temp2.insert(temp2.begin() + counter, temp[i]);
			counter++;
		}
	}
	
	return temp2;
}

vector<int> stringToVec(const string &s) {
	vector<int> temp, retVec;
	string str1;
	
	for(int i = 0;i<s.size();i++) {
		if(s[i] == 'A')       temp.insert(temp.begin() + i, 1);
		else if(s[i] == 'C')  temp.insert(temp.begin() + i, 2);
		else if(s[i] == 'G')  temp.insert(temp.begin() + i, 3);
		else if(s[i] == 'T')  temp.insert(temp.begin() + i, 4);
	
	}
	return temp;
}

int main() {
	
	string str1, str2;
	bool seqFlag;
	vector<int> sequence1, sequence2 ;
	vector<int> combSeq1;			// Will contain all possible combinations of sequence1
	vector<int> combSeq2;			// Will contain all possible combinations of sequence2
	vector<int> doubleDecker, temp;
	
	cout<<"Please enter the sequences in capital letters only"<<endl;
	cout<<"Please Enter First Sequence = ";
	cin>>str1;

	cout<<"Please Enter Second Sequence = ";
	cin>>str2;	
	
	cout<<"Do you want to print all the sequences?\n ENTER 1 to print all the the possible sequences OR ENTER 0 to just get the total number of possible combinations.\t";
	cin>>seqFlag;
	
	sequence1 = stringToVec(str1);
	sequence2 = stringToVec(str2);

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
	
	doubleDecker = combs(combSeq1, combSeq2);
	temp = rmAligned9(doubleDecker);
	
	doubleDecker.clear();	
	doubleDecker = temp;
	temp.clear();
	temp = correctedSeq(doubleDecker);
	

	doubleDecker.clear();
	doubleDecker = temp;
	printFinalSeq(doubleDecker, seqFlag);
		
	return 0;
}



