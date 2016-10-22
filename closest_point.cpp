#include <cstdlib> 
#include <fstream> 
#include <iostream> 
#include <vector> 
#include <algorithm>    // std::sort
#include <math.h>  
#include <sstream>
#include<time.h>

using namespace std;

class Point {
	public:
		Point(float x, float y):x_(x), y_(y){
		}
	static bool OrderByX(const Point& left, const Point& right) {  
    return left.x_ < right.x_;  
  	}
	static bool OrderByY(const Point& left, const Point& right) {  
    return left.y_ < right.y_;  	  
	}
		
	float x_;
	float y_;
};

float Distance(const Point& left, const Point& right){
	return sqrt(pow(left.x_-right.x_,2)+pow(left.y_-right.y_,2));
}



float NearestPoints( vector<Point>& points){
//	cout <<"\n Size "<< points.size();

	if (points.size() > 2){
		// 按X轴排序 
		sort(points.begin(),points.end(), Point::OrderByX);
		
		vector<Point> left_points;
		vector<Point> right_points;
		vector<Point> middle_points;
		// 按X轴分成两组 
		int middle = points.size()/2-1;
		for (int i=0;i<points.size();i++){
			if (i <= middle){
				left_points.push_back(points[i]);

			}else{
				right_points.push_back(points[i]);
			}
		}
//		cout <<"\n L Size "<< left_points.size();
//		cout <<"\n R Size "<< right_points.size();
		
		// 分别计算两组内的最小距离 
		float left_min_dis = NearestPoints(left_points);
		float right_min_dis = NearestPoints(right_points);
		float min_dis = left_min_dis < right_min_dis?left_min_dis:right_min_dis;
//		cout <<"\n l min_dis "<< left_min_dis;
//		cout <<"\n r min_dis "<< right_min_dis;
//		cout <<"\n min_dis "<< min_dis;

		// 寻找中间组 
		float middle_x = float( points[middle].x_ + points[middle+1].x_ )/2 ;
		sort(points.begin(),points.end(), Point::OrderByY);
		for (int i=0;i<points.size();i++){
			if (fabs(points[i].x_-middle_x)< min_dis){
				middle_points.push_back(points[i]);
			}
		}
		// 在中间组内查找 
		int middle_size = middle_points.size();
		
		for (int i=0;i<(middle_size-1);i++){
			int next = (middle_size-1)<(i+8)?(middle_size-1):(i+8);
//			cout <<"\n ss "<< next;
			for (int j=i+1;j<=next;j++){
				float dis_temp = Distance(middle_points[i],middle_points[j]);
				if (dis_temp<min_dis){
					min_dis = dis_temp;
				}
			}
			 
			
		} 
		return min_dis	;	
		
	}
	else if(points.size()==2) {
		return Distance(points[0],points[1]);
		
	}else{
		return 10000;
	}
	
	
}


float NearestPointsBruce( vector<Point>& points){
	
	float 	dis_temp;
	float min_dis = 1000;
	int n = points.size();

	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			dis_temp = Distance(points[i],points[j]);
			if (dis_temp < min_dis){
				min_dis = dis_temp;
			}
		}
	
	
	}
	return min_dis;
}




int main()
{
float min_dis1, min_dis2;
ifstream fin( "C:\\Users\\Jerry\\Desktop\\data2.txt ",ios::in); 

vector<Point> points;
//char line[1024]={0};
//while(fin.getline(line, sizeof(line))) {
//	stringstream word(line);
//	float x;
//	float y;
//	word>>x;
//	word>>y;
//	
//	cout<<"("<<x<< "," <<y <<"):"; 
//
//	points.push_back(Point(x,y));
//
//}
srand(time(0));
for (int i=0;i<100000;i++){
	float x = rand();
	float y = rand();
	points.push_back(Point(x,y));
}


time_t start,finish;

// Part 1
start=time(NULL);

min_dis1 = NearestPoints(points);

finish=time(NULL);

cout<<"\n DIS1 "<<min_dis1	;
cout<<"\n The during time is:"<<difftime(finish,start)<<" seconds\n";
// Part 2	

start=time(NULL);

min_dis2 = NearestPointsBruce(points);
	
//	
finish=time(NULL);
//

cout<<"\n DIS2 "<<min_dis2	;
cout<<"\n The during time is:"<<difftime(finish,start)<<" seconds\n"	;
	
return 0;
}
