#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include"protien.h"
#define MAXLENGTH 1000
#define TURN_PRODUCT 0.75e-4
#define ALPHA_CUT 100
#define BETA_CUT 100
#define TURN_CUT 0.75e-4
using namespace std;
struct protien_data{
	int code;
	int p_alpha;
	int p_beta;
	int p_turn;
	float bend[4];
	int alpha_class;
	int beta_class;
	int p4_alpha;
	int p4_beta;
	int p4_turn;
	float turn_prod;
}sequence[MAXLENGTH];
char infile[128], outfile[128], prot_name[64];


void get_probability(int);
void tetra_ave(int);
void print(int);
main(){
		p_data p[20];
	p[9].set('A', 142, 139, 83, 79, 66, 0.06, 0.076, 0.035, 0.058, 'H', 'H', 'i', 'i', 0, 0, 0);
	p[1].set('R', 98, 100, 93, 94, 95, 0.070, 0.106, 0.099, 0.085, 'i', 'H', 'i', 'i', 0, 0, 0);
	p[2].set('N', 67, 78, 89, 66, 156, 0.161, 0.083, 0.191, 0.091, 'b', 'i', 'i', 'b', 0, 0, 0);
	p[3].set('D', 101, 106, 54, 66, 146, 0.147, 0.110, 0.179, 0.081, 'I', 'h', 'B', 'b', 0, 0, 0);
	p[4].set('C', 70, 95, 119, 107, 119, 0.149, 0.050, 0.117, 0.128, 'i', 'i', 'h', 'h', 0, 0, 0);
	p[5].set('Q', 111, 112, 110, 100, 98, 0.074, 0.098, 0.037, 0.098, 'h', 'h', 'h', 'I', 0, 0, 0);
	p[6].set('E', 151, 144, 37, 51, 74, 0.056, 0.060, 0.077, 0.064, 'H', 'H', 'B', 'b', 0, 0, 0);
	p[7].set('G', 57, 64, 75, 87, 156, 0.102, 0.085, 0.190, 0.152, 'B', 'B', 'b', 'i', 0, 0, 0);
	p[8].set('H', 100, 112, 87, 83, 95, 0.140, 0.047, 0.093, 0.054, 'I', 'h', 'i', 'i', 0, 0, 0);
	p[0].set('I', 108, 99, 160, 157, 47, 0.043, 0.034, 0.013, 0.056, 'h', 'i', 'H', 'H', 0, 0, 0);
	p[10].set('L', 121, 130, 130, 117, 59, 0.061, 0.025, 0.036, 0.070, 'H', 'H', 'H', 'h', 0, 0, 0);
	p[11].set('K', 116, 121, 74, 73, 101, 0.055, 0.115, 0.072, 0.095, 'h', 'h', 'b', 'b', 0, 0, 0);
	p[12].set('M', 145, 132, 105, 101, 60, 0.068, 0.082, 0.014, 0.055, 'H', 'H', 'h', 'I', 0, 0, 0);
	p[13].set('F', 113, 111, 138, 123, 60, 0.059, 0.041, 0.065, 0.065, 'h', 'h', 'h', 'h', 0, 0, 0);
	p[14].set('P', 57, 55, 55, 62, 152, 0.102, 0.301, 0.034, 0.068, 'B', 'B', 'B', 'B', 0, 0, 0);
	p[15].set('S', 77, 72, 75, 94, 143, 0.120, 0.139, 0.125, 0.106, 'i', 'B', 'B', 'i', 0, 0, 0);
	p[16].set('T', 83, 78, 119, 133, 96, 0.086, 0.108, 0.065, 0.079, 'i', 'i', 'h', 'h', 0, 0, 0);
	p[17].set('W', 108, 103, 137,124, 96, 0.077, 0.013, 0.064, 0.167, 'h', 'I', 'h', 'h', 0, 0, 0);
	p[18].set('Y', 69, 73, 147,131, 114, 0.082, 0.065, 0.114, 0.125, 'b', 'b', 'H', 'h', 0, 0, 0);
	p[19].set('V', 106, 97, 170, 164, 50, 0.062, 0.048, 0.028, 0.053, 'H', 'i', 'H', 'H', 0, 0, 0);
	BST b;
	for(int i=0;i<20;i++)
	{
		b.insert(&p[i]);
	}

	int c,length = 0;
	char seq[]= "ATSTKKLHKEPATLIKAIDGDTVKLMYKGQPMTFRLLLVDTPETKHPKKGVEK";
	char ans[6];
	cout<<"ENTER PROTIEN NAME:\n";
	cin>>prot_name;
	cout<<"enter sequence:\n";
//	seq = "ATSTKKLHKEPATLIKAIDGDTVKLMYKGQPMTFRLLLVDTPETKHPKKGVEK";
	length = strlen(seq);
	for(int i=0; i<length; i++)
		sequence[i].code = toupper(seq[i]);
		
	get_probability(length);
	tetra_ave(length);
	print( length);
}

char d_base[5];

void get_probability(int length){
	int dbase = 2,j;
	do{
		cout<<"Use database or 29 protcinr (Chou & Fasman '78)--> enter 0\n";
		cout<<"Use database or 64 proteins (Chou '79)--> enter 1\n";
		cin>>dbase;
	} while (dbase > 1);
	
	
	for( int i =0,j=0; i< length; i++){
		while((sequence[i].code != data[j].c) && j < 20)
			j++;
		
		if(j == 20){
			cout<<"Illegal data point # "<<i<<" is "<<sequence[i].code;
			exit(1);
		}
		
		sequence[i].p_alpha = data[j].p_a[dbase];
		sequence[i].p_beta = data[j].p_b[dbase];
		sequence[i].p_turn = data[j].p_t;
		
		for(int k=0; k<=3; k++)
			sequence[i].bend[k] = data[j].b[k];
			
		sequence[i].alpha_class = data[j].a_class[dbase];
		sequence[i].beta_class = data[j].b_class[dbase];
		
		j = 0;
	}
}

void tetra_ave(int length){
	int aSum, bSum, tSum;
	float tprod;
	
	for(int i=1; i<length-3; i++){
		aSum = bSum = tSum = 0;
		
		tprod = 1;
		for(int j=0; j<=3; j++){
			
			aSum += sequence[i+j].p_alpha;
			bSum += sequence[i+j].p_beta;
			tSum += sequence[i+j].p_turn;
			tprod *= sequence[i+j].bend[j];
		}
		
		sequence[i].p4_alpha = aSum/4;
		sequence[i].p4_beta = bSum/4;
		sequence[i].p4_turn = tSum/4;
		sequence[i].turn_prod = tprod;
	}
}

void print(int length){
	cout<<"chau fasman algorithm\n\n";
	cout<<"protien name: "<<prot_name<<endl;
	cout<<"\t\tPa\tPb\tPt\t<Pa>\t<Pb>\t<Pt>\t\n\n\n";
	
	
	for(int i=0; i<length ; i++){
		cout<<i+1 <<"\t";
		printf("%c",toupper(sequence[i].code));
		cout<<"\t"<<sequence[i].p_alpha<<"\t"<<sequence[i].p_beta<<"\t"<<sequence[i].p_turn<<"\t";
//		printf("%c\t%c",sequence[i].alpha_class,sequence[i].beta_class);
		cout<<"\t"<<sequence[i].p4_alpha<<"\t";
		if(sequence[i].p4_alpha >= ALPHA_CUT)
			cout<<'*';
		else
			cout<<'_';
//		cout<<"\t"<<sequence[i].p4_beta<<" ";
		if(sequence[i].p4_beta >= BETA_CUT)
			cout<<'*';
		else
			cout<<'_';
//		cout<<" "<<sequence[i].p4_turn;
//		cout<<" "<<sequence[i].turn_prod<<"   ";
		if(sequence[i].turn_prod >= TURN_CUT)
			cout<<'*';
		else
			cout<<'_';
		cout<<endl;
	}
}




















