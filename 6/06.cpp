#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std; 

class Pnt{
	public:
	float x, y;
	Pnt(){
	}
	Pnt(float _x, float _y){
		x = _x;
		y = _y;
	}
};

class Edge{
	public:
	Pnt p1;
	Pnt p2;
	float k, b;
	int flag;
	
	Edge(Pnt _p1, Pnt _p2){
		p1 = _p1;
		p2 = _p2;
		if(p1.x == p2.x){
			flag = 1;
		}
		else{
			flag = 0;
			k = (p1.y - p2.y) / (p1.x - p2.x);
			b = p1.y - k*p1.x;
		}	
	}
};

vector<Pnt> points;
vector<Edge> polygon;

bool judge(float x, float y){
	int pnt_r = 0, pnt_l = 0;
	float tpx;
	
	for(int m = 0; m < polygon.size(); m++){
		tpx = x;
//		cout << "m是"<< m << endl; 
		if((polygon[m].p1.y - y)*(polygon[m].p2.y - y) > 0){
//			cout <<"不相交"<< endl; 
			continue;	
		} 
		if(polygon[m].k* x+ polygon[m].b == y){
//			cout << "点在线上"<< endl; 
			return true;	
		} 
		if(polygon[m].flag == 1){
			tpx = polygon[m].p1.x;
//			cout << "垂直，横坐标为"<< tpx<< endl; 
		} 
		else{
			tpx  = (y - polygon[m].b)/ polygon[m].k;
//			cout << "计算tpx"<< tpx<< endl;	
		} 
		if(tpx > x) pnt_r ++;
		else if(tpx < x) pnt_l ++;	
	}
	
//	cout << "   "<< pnt_r << "   "<<pnt_l<<endl;
	if(pnt_r %2 == 1 && pnt_l %2 == 1) return true;
	else return false;
}


void init(){    
    FILE* fp1;
    fp1 = fopen("input_question_6_polygon", "r");
	char str[100];
	int x, y;
	
    while (fscanf(fp1, "%s", str) != EOF){
    	x = atoi(str);
    	fscanf(fp1, "%s", str);  
		y = atoi(str);	
        points.push_back(Pnt(x, y));
    }
    fclose(fp1);

	for(int i = 0; i < points.size()-1; i ++){
		polygon.push_back(Edge(points[i], points[i+1]));
	}
	polygon.push_back(Edge( points[points.size()-1],  points[0]));
	
}

 
int main(){
	
	init();
	FILE* fp2, *fpout;
    fp2 = fopen("input_question_6_points", "r");
    fpout  = fopen("output_question_6", "w");
    
	char str2[100];
	int x, y;
	
    while (fscanf(fp2, "%s", str2) != EOF){
    	x = atoi(str2);
    	fscanf(fp2, "%s", str2);  
		y = atoi(str2);	
		fprintf(fpout, "%d %d ", x, y);
		
		bool b = judge(x, y);
		
		if(!b) fprintf(fpout,"outside\n");
		else fprintf(fpout,"inside\n");   
    }
    
    
    
    
    
}
