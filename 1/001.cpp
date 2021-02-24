#include <iostream>
#include <fstream>
using namespace std;

unsigned long long M, N, total;//N-1个，最大为M	 
unsigned long long S, t1, t2;
unsigned long long T;
ofstream fs;

int init(){
	cin >> M >> N >> total;
	T =  total;
	total -= (M+1)*M/2;
}

int count(){
	S = total/(N-1);	
	if(S > M) return -1;
	t2 = total - S*(N-1);	//值为S+1有t2个
	t1 = N-1-t2;			//值为S有t1个 	
	return 0;
}

int print(){
	fs << T << " ";
	for(int i = 0; i < S-1; i ++){
		fs << "D"; 
	}
	for(int i = 0; i < t1; i ++){
		fs << "R";
	}
	fs << "D";
	for (int i = 0; i < t2; i ++){
		fs << "R";
	}
	unsigned long long k = M-1-S;
	for(int i = 0; i < k; i ++){
		fs << "D";
	}
	fs << endl;
}


int main(){
	fs.open("output_question_1.txt");
	for(int i = 0; i< 6; i ++){
		init();
		int k = count();
		if(k == 0)print();
		else{
			fs << T << endl;	
		}
		if(i == 3) fs<< endl;		
	}	
	fs.close();
}
