//class jahid
#include<cctype>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string>
#include<cstring>
#include<fstream>
typedef long double LD;
using namespace std;
class jahid{
public:
long double factorial(long double);
int even(long int);
void delay(double);
long double max(int,long double x[]);
void put_matrix(char* l,int N,long double x[]);
void put_matrix(char*,int,int,long double x[][1024]);
int get_matrix_m(char*);
int get_matrix_n(char*);
void get_matrix(char*,int,int,long double x[][1024]);
void get_matrix(char*,int,long double x[]);
void sort(int M,int N,long double x[][1024]);
void sort(int N,long double x[]);
long double max(int M,int N,long double x[][1024]);
int copy_file(char* l,char* m);
int cut_file(char* l,char* m);
void copy_matrix(int M,int N,LD x1[][1024],LD x2[][1024]);
void copy_matrix(int N,LD x1[],LD x2[]);
void add_matrix(int M,int N,LD x1[][1024],LD x2[][1024],LD x3[][1024]);
void add_matrix(int N,LD x1[],LD x2[],LD x3[]);
void scalar_matrix(int M,int N,LD x1[][1024],LD k);
void scalar_matrix(int N,LD x1[],LD k);
void multiply_matrix(int M,int N,LD x1[][1024],int P,int Q,LD x2[][1024],LD x3[][1024]);
void multiply_matrix(int N,LD x1[],LD x2[],LD x3[]);};

long double jahid::factorial(long double x){
long double z=1;
while(x!=0){z=z*x--;}
return z;
}

int jahid::even(long int x){int a;
	if(x%2==0){a=1;}
	else {a=0;}
	return a;
	}

void jahid::delay(double x){double a,b;
a=clock()/CLOCKS_PER_SEC;
b=0;
while((b-a)<x){b=clock()/CLOCKS_PER_SEC;}
  }

long double jahid::max(int n,long double x[]){
	  long double a=x[0];
	  for(int i=0;i<n;i++){a=(x[i]>a)?x[i]:a;}
	  return a;}

void jahid::put_matrix(char* l,int M,int N,long double x[][1024]){fstream file;
	file.open(l,ios::out);
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			file<<x[i][j]<<" ";
			}
		file<<"\n";file.flush();
		}
file.close();
	}


void jahid::put_matrix(char* l,int N,long double x[]){fstream file;
	file.open(l,ios::out);
	for(int i=0;i<N;i++){file<<x[i]<<" ";file.flush();}
file.close();
	}



int jahid::get_matrix_n(char* l){
	int a=0;
	fstream file;
	file.open(l,ios::in);
	 while((char)file.get()!='\n'){a++;}
	file.close();
	return (int)ceil((double)a/2);
	}


int jahid::get_matrix_m(char* l){
	int a=0;long double b;
	fstream file;
	file.open(l,ios::in);
	while(!file.eof()){file>>b;a++;}
	file.close();
	return (a-1)/get_matrix_n(l);}


void jahid::get_matrix(char* l,int M,int N,long double x[][1024]){
fstream file;
file.open(l,ios::in);
	for(int i=0;i<M;i++){
	for(int j=0;j<N;j++){
	file>>x[i][j];}}
	file.close();}

void jahid::sort(int M,int N,long double x[][1024]){long double t;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){
		        for(int p=0;p<N;p++){if(x[i][j]<x[k][p]){t=x[i][j];x[i][j]=x[k][p];x[k][p]=t;}}}}}}


void jahid::sort(int N,long double x[]){long double t;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){if(x[i]<x[j]){t=x[i];x[i]=x[j];x[j]=t;}}}}


long double jahid::max(int M,int N,long double x[][1024]){
	long double a=x[0][0];
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			a=(x[i][j]>a)?x[i][j]:a;}}
return a;}


void jahid::get_matrix(char* l,int N,long double x[]){
	fstream file;
	file.open(l,ios::in);
	for(int i=0;i<N;i++){file>>x[i];}
	file.close();}


int jahid::copy_file(char* l,char* m){int a=1,b=0;char c;
if(l!=m){
	fstream file1,file2;
	file1.open(l,ios::binary|ios::in);
	if(file1.good()){file2.open(m,ios::binary|ios::out);
	if(!file2){a=0;}
	else{
	file1.seekg(0,ios::beg);
	file2.seekp(0,ios::beg);
	while(file1.good()&&file2.good()){
		file1.read(&c,1);
		file2.write(&c,1);
		b++;
		file1.seekg(b);file2.seekp(b);}
		file1.close();file2.close();}}
		else{a=-1;}}
return a;}


int jahid::cut_file(char* l,char* m){int a=1,b=0;char c;
if(l!=m){
	fstream file1,file2;
	file1.open(l,ios::binary|ios::in);
	
	if(file1.good()){file2.open(m,ios::binary|ios::out);
	if(!file2){a=0;}
	else{
	file1.seekg(0,ios::beg);
	file2.seekp(0,ios::beg);
	while(file1.good()&&file2.good()){
		file1.read(&c,1);
		file2.write(&c,1);
		b++;
		file1.seekg(b);file2.seekp(b);}
		file1.close();file2.close();
		file1.open(l,ios::in);file2.open(m,ios::in);
		if(file1.good()&&file2.good()&&a==1){remove(l);}
		file2.close();}}
		else{a=-1;}}
return a;}


void jahid::copy_matrix(int M,int N,LD x1[][1024],LD x2[][1024]){
	for(int i=0;i<M;i++){for(int j=0;j<N;j++){x2[i][j]=x1[i][j];}}}


void jahid::copy_matrix(int N,LD x1[],LD x2[]){
	for(int i=0;i<N;i++){x2[i]=x1[i];}}
	

void jahid::add_matrix(int M,int N,LD x1[][1024],LD x2[][1024],LD x3[][1024]){
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			x3[i][j]=x2[i][j]+x1[i][j];}}}
	
	
	
void jahid::add_matrix(int N,LD x1[],LD x2[],LD x3[]){
	for(int j=0;j<N;j++){
			x3[j]=x2[j]+x1[j];}}
	
	
void jahid::scalar_matrix(int M,int N,LD x1[][1024],LD k){
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			x1[i][j]=k*x1[i][j];}}}
	
	
	
void jahid::scalar_matrix(int N,LD x1[],LD k){
	for(int j=0;j<N;j++){
			x1[j]=k*x1[j];}}
	
	
void jahid::multiply_matrix(int M,int N,LD x1[][1024],int P,int Q,LD x2[][1024],LD x3[][1024]){
#if(N==P)
	{
	for(int i=0;i<M;i++){for(int j=0;j<Q;j++){x3[i][j]=0;}}
		
	for(int i=0;i<M;i++){
		for(int j=0;j<Q;j++){
			for(int k=0;k<N;k++){
				x3[i][j]=x1[i][k]*x2[k][j]+x3[i][j];}}}}
#else
#error matrix dimension must agree(m x n,n x p)
#endif
	}
	
	
void jahid::multiply_matrix(int N,LD x1[],LD x2[],LD x3[]){
	for(int j=0;j<N;j++){
			x3[j]=x2[j]*x1[j];}}
	
	
	
	
	
