#include<iostream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

typedef struct{
	int number;
	int shape;
} Card;

string shape (int n){
	switch (n){
	case 0:
		return "diamond";
	case 1:
		return "heart";
	case 2:
		return "spade";
	case 3:
		return "club";
	}
}

Card cards[5];

void getCards(){
	for (int i=0;i<5;i++){
		cout<<"Enter card "<<i+1<<" number(1-10, 11: J, 12: Q, 13: K): ";
		cin>>cards[i].number;
		while (cards[i].number < 1 || cards[i].number > 13){
			cout<<"Invalid number. Re-enter again.";
			cin>>cards[i].number;
		}
		
		int u_shape = -1;
		
		while (u_shape == -1){
			cout<<"Enter card "<<i+1<<" shape(0: diamond, 1: heart, 2:spade, 3:club): ";
			cin>>u_shape;
			if(u_shape < 0 || u_shape >3){
				cout<<"Invalid shape."<<endl;
				u_shape = -1;
			}
			else{
				cards[i].shape = u_shape;
			}
		}
		
		for (int j = 0;j < i;j++){
			if(cards[j].number == cards[i].number && cards[j].shape == cards[i].shape){
				cout<<"Duplicated cards. Enter another valid card."<<endl;
				i -= 1;
				break;
			}
		}
	}
}

int numberOfShapes(){
	int a = 0,b = 0,c = 0,d = 0;
	for (int i = 0;i < 5;i++){
		switch (cards[i].shape){
			case 0:
				a = 1; break;
			case 1:
				b = 1; break;
			case 2:
				c = 1; break;
			case 3:
				d = 1; break;
		}
	}
	return a + b + c + d;
}

void processCards(){
	if (numberOfShapes() == 1){
		if (cards[0].number - cards[4].number){
			if (cards[0].number == 13){
				cout<<"Royal Flush"<<endl;
			}else{
				cout<<"Straight Flush"<<endl;
			}
		}
		else{
			cout<<"Flush"<<endl;
		}
	}
	else if(cards[0].number == cards[3].number || cards[1].number == cards[4].number){
		cout<<"Four of a kind"<<endl;
	}
	else if((cards[0].number == cards[2].number && cards[3].number == cards[4].number) || (cards[0].number == cards[1].number && cards[2].number == cards[4].number)){
		cout<<"Full house"<<endl;		
	}
	else if((cards[0].number - cards[1].number == 1) && (cards[1].number - cards[2].number == 1) &&
			(cards[2].number - cards[3].number == 1) && (cards[3].number - cards[4].number == 1)){
		cout<<"Straight"<<endl;
	}
	else if((cards[0].number == cards[2].number) || (cards[1].number == cards[3].number) || (cards[2].number == cards[4].number)){
		cout<<"Three of a kind"<<endl;
	}
	else if((cards[0].number == cards[1].number && cards[2].number == cards[3].number) || (cards[0].number == cards[1].number && cards[3].number == cards[4].number) ||
			(cards[1].number == cards[2].number && cards[3].number == cards[4].number)){
			cout<<"2 pairs"<<endl;
	}
	else if(cards[0].number == cards[1].number || cards[1].number == cards[2].number || cards[2].number == cards[3].number || cards[3].number == cards[4].number){
		cout<<"Pair"<<endl;
	}
	else{
		cout<<"High card"<<endl;
	}
}

void printCards(){
	for(int i = 0;i<5;i++){
		cout<<"Card "<<i+1<<" number: "<<cards[i].number<<"\tShape: "<<shape(cards[i].shape)<<endl;
	}
}

int compCards (const void* c, const void* d){
	Card* a = (Card*) c,
		* b = (Card*) d;
	
	if (a ->number > b->number) 		return -1;
	else if (a ->number < b->number) 	return 1;
	else 								return 0;
	
}





int main(){
	getCards();
	
	qsort(cards, 5, sizeof(Card),compCards);
	
	processCards();
	
	printCards();
	
	return 0;
}
