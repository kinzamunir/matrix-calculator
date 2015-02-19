
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "Tests.h"

using namespace std;

int main(){

	int answer=0;
	int flag=0;
	int first[20][20], second[20][20]={-1};
	int a = 0;
	int b = 0;
	char str[256];
	cout << "Enter the name of an existing text file: ";
	cin.get(str, 256);    // get c-string
	ifstream is;
	is.open(str);     // open file

	//check if file exists
	if(!is)
    {
		cout << "File doesn't exist.\n";
        return -1;
    } 

	
	//i represents row, j represents column
	int i = 0; int j = 0;
	int check = 0;
	char c;

	while (is.get(c))          // loop getting single characters
	{
		//+ sign indicates no more matrixes exist.
		if(c=='+'){
			cout<<"End of file reached."<<endl;
			flag=-1;
			break;
		}
		//. represents a new row
		if (c == '.') 
		{ 
		//addition of new row increments i
		i++;
		//saves the number of rows of every matrix
		rows[check]=i+1;
		j = 0; 
		}
		else if (c == '/') { // '/' represents a new matrix
			j = 0;
			i = 0;	
			if(check==1){
				//take no more than two matrixes
				check=0;
				break;
			}
			else
			check++;
			rows[check]=0;
			columns[check]=0;

		}
		else if(isdigit(c)){
			//fill the array accordingly
			if (check == 0){
				first[i][j] = int(c - '0');	
			}
		else if (check==1)
			{
				second[i][j] = int(c - '0');
			}

			//save number of columns of each matrix
				columns[check]=j+1;
			
			//column is incremented
			j++;

			
		}
	} 


	cout << "What operation do you want to perform?\n1-Addition\n2-Addition of three matrixes\n3-Subtraction\n4-Multiplication\n5-Multiplication & Addition\n6-Subtraction of three matrixes\n7-Multiplication & Subtraction"<<endl;
	cin >> answer;
	if(answer==1){
	//Add two matrices
	addition(first, second);
	}
	else if(answer==3){
	//Subtract two matrices
	subtraction(first, second);
	}
	else if(answer==4){
	//Multiply two matrices
	multiplication(first, second);
	}
	else if(answer==2 || answer==5 || answer==6 || answer==7){

	//if there is no 3rd matrix, we will not do this part. 
	if(flag==-1){
	cout<<"End of file reached. No third matrix."<<endl;
	is.close();
	return 0;
	}

	if(answer==2){
    //add first two 
	addition(first, second);
	}
	else if(answer==6){
   //subtract first two 
		subtraction(first, second);
	}
	else{
    //multiply first two
	multiplication(first, second);
	}

	//get one more.
		while (is.get(c))          // loop getting single characters
	{
		if(c=='+'){
			cout<<"End of file reached."<<endl;
			flag=-1;
			break;
		}
		//. represents a new row
		if (c == '.') 
		{ 
		i++;
		
		rows[check]=i+1;
		j = 0; 
		}
		else if (c == '/') { // '/' represents a new matrix
			j = 0;
			i = 0;
			check=0;
			break;

		}
		else if(isdigit(c)){
			if (check == 0){
				first[i][j] = int(c - '0');
			
				columns[check]=j+1;
				
			}
		else if (check==1)
			{
				second[i][j] = int(c - '0');
			
				columns[check]=j+1;
			
			}
			
			j++;
			
		}
	} 

	if(answer==2){
	//assuming addition result is now matrix 2
	rows[1]=rows[2];
	columns[1]=columns[2];
	//Adding three matrices
	addition(first, Aresult);
	}
	else if(answer==6){
    //assuming subtraction result is now matrix 2
	rows[1]=rows[3];
	columns[1]=columns[3];
	//Adding three matrices
	subtraction(first, Sresult);
	}
	else{
	//assuming multiplication result is now matrix 2
	rows[1]=rows[4];
	columns[1]=columns[4];

	if(answer==5){
	//Multiply 2 matrices and then add a 3rd one to the result.
	addition(first, Mresult);
	}
	else{
    //Multiply 2 matrices and then subtract a 3rd one to the result.
		subtraction(first, Mresult);
	}
	}
	
	}
	else{
		cout<< "Incorrect Input" <<endl;
	}
 
	is.close();
	return 0;


}