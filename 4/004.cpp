#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <string>
/*
Queue is a kind of data structure, which contains a series of items arranged always in the order they entered the queue.
There are two kind of basic options for a queue:
Push an element into the back of the queue. 
Pop the oldest item from the top of the queue and return it's value
There's already in C++STL a queue container.
*/

//4-connectivity
using namespace std; 


class pnt{
	public:
	int i, j;
	pnt(){
	}
	pnt(int _i, int _j){
		i = _i;
		j = _j;
	}
}; 

int M = 10, N = 20;
int ** Matrx;
queue<pnt> Que;
int Num = 1;//连通块个数 
//ifstream fs1;
ofstream fs2;

void init(){	//处理输入 

//	string input;
//	char c;
	Matrx = new int *[M];
	for(int i = 0; i < M; i ++){
		Matrx[i] = new int[N];

/*		getline(fs1 ,input);
		istringstream buffer(input);
		buffer >>A[0]>>A[1]>>A[2]>>A[3]>>A[4]>>A[5]
			   >>A[6]>>A[7]>>A[8]>>A[9]>>A[10]
			   >>A[11]>>A[12]>>A[13]>>A[14]>>A[15]
			   >>A[16]>>A[17]>>A[18]>>A[19];	*/
		
		for(int j = 0; j < N; j ++){
			cin >> Matrx[i][j];
			if(Matrx[i][j] == 1) Matrx[i][j] = -100;
		}
	}
}

void BFS(int i, int j){
	Que.push(pnt(i, j));
	Matrx[i][j] = Num;
	
	while(!Que.empty()){
		pnt c = Que.front();
		Que.pop();
		
		if( (c.j-1)>= 0 && Matrx[c.i][c.j-1] == -100){//上联通
			Matrx[c.i][c.j-1] = Num;
			Que.push(pnt(c.i, c.j-1));	 
		}
			
		if( (c.j+1)< N && Matrx[c.i][c.j+1] == -100){//下联通
			Matrx[c.i][c.j+1] = Num;
			Que.push(pnt(c.i, c.j+1));	 
		}	
		
		if( (c.i-1)>= 0 && Matrx[c.i-1][c.j] == -100){//左联通
			Matrx[c.i-1][c.j] = Num;
			Que.push(pnt(c.i-1, c.j));	 
		}	
		
		if( (c.i+1)< M && Matrx[c.i+1][c.j] == -100){//右联通
			Matrx[c.i+1][c.j] = Num;
			Que.push(pnt(c.i+1, c.j));	 
		}	
	}
	Num ++; 
}

void count(){
	for(int i = 0; i < M; i ++){
		for(int j = 0; j < N; j ++){
			if(Matrx[i][j] == -100){
				BFS(i, j);						
			}
		}
	}
}

void print(){
	for(int i = 0; i < M; i ++){
		for(int j = 0; j < N; j ++){
			fs2 << Matrx[i][j] << " ";
		}
		fs2 << endl;
	}
}


int main(){
	
//	fs1.open("input_question_4.txt");
	fs2.open("output_question_4.txt");
	
	init();
	count();
	print();
	
//	fs1.open("input_question_4.txt");
	fs2.open("output_question_4.txt");
}




