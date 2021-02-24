#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
int L1 = 50 , L2 = 57; 
int L_1 = 4, L_2 = 8 , L_3 = 5, L_4 = 9, L_5 = 6, L_6 = 7;

ifstream if_coord1;
ifstream if_index1;
ifstream if_coord2;
ifstream if_index2;


ofstream of_index1;
ofstream of_coord1;
ofstream of_index2;
ofstream of_coord2;


class pnt2{
	public:
	int x, y;
	pnt2(int _x, int _y){
		x = _x; 
		y = _y;
	}
};

class pnt6{
	public:
	int x1, x2, x3, x4, x5, x6;
	pnt6(int _x1, int _x2, int _x3, int _x4, int _x5, int _x6){
		x1 = _x1;
		x2 = _x2;
		x3 = _x3;
		x4 = _x4;
		x5 = _x5;
		x6 = _x6;	
	}
};


int findI2(int x1, int x2){
	return x2*L1 + x1;
}

pnt2 findCoord2(int I){
	int m = I / L1;
	int n = I - m*L1;
	return pnt2(n , m);
}

int findI6(int x1, int x2, int x3, int x4, int x5, int x6){
	int tp = 0;
	int S2 = L_1* L_2;
	int S3 = S2 * L_3;
	int S4 = S3 * L_4;
	int S5 = S4 * L_5;
	tp += x6 * S5;
	tp += x5 * S4;
	tp += x4 * S3;
	tp += x3 * S2;
	tp += x2 * L1;
	tp += x1;
	return tp;
} 

pnt6 findCoord6(int I){
	int S1 = L_1;
	int S2 = S1 * L_2;
	int S3 = S2 * L_3;
	int S4 = S3 * L_4;
	int S5 = S4 * L_5;
	
	int x6 = I / S5;
	I = I % S5;
	int x5 = I / S4;
	I = I % S4;
	int x4 = I / S3;
	I = I % S3;
	int x3 = I / S2;
	I = I % S2;
	int x2 = I / S1;
	I = I % S1;
	int x1 = I;
	
	return pnt6(x1, x2, x3, x4, x5, x6);
}

int main(){
	
	if_coord1.open("input_coordinates_7_1.txt");
	if_index1.open("input_index_7_1.txt");
	if_coord2.open("input_coordinates_7_2.txt");
	if_index2.open("input_index_7_2.txt");
	
	of_index1.open("output_index_7_1.txt");
	of_coord1.open("output_coordinates_7_1.txt");
	of_index2.open("output_index_7_2.txt");
	of_coord2.open("output_coordinates_7_2.txt");
	
	string a, b, c, d, e, f;
	int x, y, m, n, o, p;
	int index;
	pnt2 tp = pnt2(0, 0);
	pnt6 tp6 = pnt6(0,0,0,0,0,0);
	
	
	if_coord1 >> a >> b;
	of_index1 << "index" << endl;
	while(if_coord1 >> a >> b ){
		x = atoi(a.c_str());
		y = atoi(b.c_str());
		index = findI2(x, y);
		of_index1 <<index << endl;	
	}
	
	if_index1 >> a;	
	of_coord1 << "x1" << "\t"<< "x2"<< endl;
	while(if_index1 >> a){
		index = atoi(a.c_str());
		tp = findCoord2(index);
		of_coord1 << tp.x <<"\t"<< tp.y<< endl; 
	}
	
	if_coord2 >> a >> b >> c >> d >> e >> f;
	of_index2 << "index" << endl;
	while(if_coord2 >> a >> b >> c >> d >> e >> f ){
		x = atoi(a.c_str());
		y = atoi(b.c_str());
		m = atoi(c.c_str());
		n = atoi(d.c_str());
		o = atoi(e.c_str());
		p = atoi(f.c_str());
		index = findI6(x, y, m, n, o, p);
		of_index2 <<index << endl;	
	}
	
	if_index2 >> a;	
	of_coord2 << "x1" << "\t"<< "x2"<< "\t"<< "x3"<< "\t"<< "x4"<<"\t"<<"x5"<<"\t"<<"x6"<< endl;
	while(if_index2 >> a){
		index = atoi(a.c_str());
		tp6 = findCoord6(index);
		of_coord2 << tp6.x1 <<"\t"<< tp6.x2<< "\t"<< tp6.x3 <<"\t"<< tp6.x4 <<"\t"<< tp6.x5 <<"\t"<< tp6.x6 << endl; 
	}
	
	
	
	
	
	
	
	
	
	
	
/*	
	if_index1.close("input_index_7_1.txt");
	if_coord1.close("input_coordinates_7_1.txt");
	if_index2.close("input_index_7_2.txt");
	if_coord2.close("input_coordinates_7_2.txt");
	
	of_index1.close("output_index_7_1.txt");
	of_coord1.close("output_coordinates_7_1.txt");
	of_index2.close("output_index_7_2.txt");
	of_coord2.close("output_coordinates_7_2.txt");*/
	
	
} 
