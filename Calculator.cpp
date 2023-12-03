#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <array>
using namespace std;
int green[1000][3],red[1000][3], yellow[1000][3];
int main(){
      int starting_time_sec,starting_time_min, starting_time_h, g,r,y,stop_time, check;
      cout<<"Enter the time of starting: ";
      cin>>starting_time_h>>starting_time_min>>starting_time_sec;
      cout<<endl;
      cout<<"Enter the time of red, green and yellow lights: ";
      cin>>r>>g>>y;
      cout<<endl;
      //cout<<"Enter the time until which you want to know information: ";
      //cin>>stop_time;
      int sec_left, min_left, h_left, count=1000;
      int q = 0;
      while(count>0){
            sec_left=(starting_time_sec+r)/60;
            starting_time_sec=(starting_time_sec+r)%60;
            min_left=(starting_time_min+sec_left)/60;
            starting_time_min=(starting_time_min+sec_left)%60;
            starting_time_h=(starting_time_h+min_left);
            green[q][0]=starting_time_h; green[q][1]=starting_time_min; green[q][2]=starting_time_sec;
            //cout<<"Green light time: "<<starting_time_h<<":"<<starting_time_min<<":"<<starting_time_sec<<endl;
            
            sec_left=(starting_time_sec+g)/60;
            starting_time_sec=(starting_time_sec+g)%60;
            min_left=(starting_time_min+sec_left)/60;
            starting_time_min=(starting_time_min+sec_left)%60;
            starting_time_h=(starting_time_h+min_left);
            yellow[q][0]=starting_time_h; yellow[q][1]=starting_time_min; yellow[q][2]=starting_time_sec;
            //cout<<"Yellow light time: "<<starting_time_h<<":"<<starting_time_min<<":"<<starting_time_sec<<endl;
            
            sec_left=(starting_time_sec+y)/60;
            starting_time_sec=(starting_time_sec+y)%60;
            min_left=(starting_time_min+sec_left)/60;
            starting_time_min=(starting_time_min+sec_left)%60;
            starting_time_h=(starting_time_h+min_left);
            red[q][0]=starting_time_h; red[q][1]=starting_time_min; red[q][2]=starting_time_sec;
            //cout<<"Red light time: "<<starting_time_h<<":"<<starting_time_min<<":"<<starting_time_sec<<endl;
            count--;
            q++;
            if(starting_time_h>=24){
                  break;
            }
      } 
      /*for (int i=0;i<60;i++){
            for(int j=0;j<3;j++){
                  cout<<green[i][j]<<" ";
            }
            cout<<endl;
      } */

      std::ofstream out("Data of green light.csv");
      out<<"Hours"<<","<<"Min"<<","<<"Sec"<<"\n";
      for (auto& row : green) {
            for (auto col : row){
                  out << col <<',';
            }
      
            out << '\n';
      }

      std::ofstream wout("Data of red light.csv");
      wout<<"Hours"<<","<<"Min"<<","<<"Sec"<<"\n";
      for (auto& row : red) {
            for (auto col : row){
                  wout << col <<',';
            }
      
            wout << '\n';
      }

      std::ofstream qout("Data of yellow light.csv");
      qout<<"Hours"<<","<<"Min"<<","<<"Sec"<<"\n";
      for (auto& row : yellow) {
            for (auto col : row){
                  qout << col <<',';
            }
      
            qout << '\n';
      }
         
}