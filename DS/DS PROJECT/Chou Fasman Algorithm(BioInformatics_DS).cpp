#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<ctype.h>
#include"protein orig.h"
#define MAXLENGTH 1000
#define TURN_PRODUCT 0.75e-4
#define ALPHA_CUT 100
#define BETA_CUT 100
#define TURN_CUT 0.75e-4
using namespace std;
struct protien_data
{
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

main()
{
	int c,length = 0;
	char seq[]= "ATSTKKLHKEPATLIKAIDGDTVKLMYKGQPMTFRLLLVDTPETKHPKKGVEK";
	char ans[6];
	cout<<"ENTER PROTIEN NAME:\n";
	cin>>prot_name;
	cout<<"enter sequence:\n";
	// seq = "ATSTKKLHKEPATLIKAIDGDTVKLMYKGQPMTFRLLLVDTPETKHPKKGVEK";
	cin>>seq;
	length = strlen(seq);
	for(int i=0; i<length; i++)
	sequence[i].code = toupper(seq[i]);
	get_probability(length);
	tetra_ave(length);
	print( length);	
}
	char d_base[5];
void get_probability(int length)
{
	int dbase = 2,j;
	do
	{
		cout<<"Use database or 29 proteins(Chou & Fasman '78)--> enter 0\n";
		cout<<"Use database or 64 proteins(Chou '79)--> enter 1\n";
		cin>>dbase;
	}while(dbase>1);
	
	for( int i =0,j=0; i< length; i++)
	{
		while((sequence[i].code != data[j].c) && j < 20)
		j++;
		 if(j == 20)
		{
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

void tetra_ave(int length)
{
	int aSum, bSum, tSum;
	float tprod;
	for(int i=1; i<length-3; i++)
	{
		aSum = bSum = tSum = 0;
		tprod = 1;
		for(int j=0; j<=3; j++)
		{
			aSum += sequence[i+j].p_alpha;
			bSum += sequence[i+j].p_beta;
			tSum += sequence[i+j].p_turn;
			tprod*= sequence[i+j].bend[j];
		 }
		sequence[i].p4_alpha = aSum/4;
		sequence[i].p4_beta = bSum/4;
		sequence[i].p4_turn = tSum/4;
		sequence[i].turn_prod = tprod;
	}
}
void print(int length){
	int alpha_count = 0;
	int beta_count = 0;
	int aliph =0;
	int bet=0;
	
	ofstream pro;
	pro.open("Protein.txt");
		pro<<"\t\t***Chau Fasman Algorithm***\n\n";
	cout<<"\t\tChau Fasman Algorithm\n\n";
	cout<<"protien name: "<<prot_name<<endl;
		pro<<"protien name: "<<prot_name<<endl;
		pro<<"\n\t\tPa\tPb\tPt\t<Pa><Pb><Pt>\t\n";
			
	cout<<"\t\tPa\tPb\tPt\t<Pa>\t<Pb>\t<Pt>\t\n\n\n";
	for(int i=0; i<length ; i++)
	{
		cout<<i+1 <<"\t";
			pro<<i+1 <<"\t";
		printf("%c",toupper(sequence[i].code));
			char x;
			x=toupper(sequence[i].code);
			pro<<x;
		cout<<"\t"<<sequence[i].p_alpha<<"\t"<<sequence[i].p_beta<<"\t"<<sequence[i].p_turn<<"\t";
		cout<<"\t"<<sequence[i].p4_alpha<<"\t";
			pro<<"\t"<<sequence[i].p_alpha<<"\t"<<sequence[i].p_beta<<"\t"<<sequence[i].p_turn<<"\t";
			pro<<"\t"<<sequence[i].p4_alpha<<"\t";
	
		if(sequence[i].p4_alpha >= ALPHA_CUT){
			cout<<'*';
				pro<<"*";
			aliph ++;
		}
		else{
				cout<<'_';
					pro<<'_';
				if(aliph > alpha_count)
					alpha_count = aliph;		
				aliph = 0;		
		}

		if(sequence[i].p4_beta >= BETA_CUT)
		{
			cout<<'*';
				pro<<'*';
			bet ++;
		}
		else
		{
			cout<<'_';
				pro<<'_';
			if(bet > beta_count)
			beta_count = bet;
			bet = 0;		
		}

		if(sequence[i].turn_prod >= TURN_CUT){
			cout<<'*';
				pro<<'*';
		}
		
		else{
			cout<<'_';
				pro<<'_';
		}
		pro<<endl;
		cout<<endl;
	}
	
	if(alpha_count>beta_count)
	{
		cout<<"\nDominent Structure : AlphaHelix";
		pro<<"\n\nDominent Structure : AlphaHelix";
	}
	else{
		cout<<"\nDominant Structure : BetaSheets";
		pro<<"\n\nDominant Structure : BetaSheets";
	}
pro.close();	
}
