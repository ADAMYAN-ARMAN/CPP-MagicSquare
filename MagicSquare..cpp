/*Sum of lines are your number
Sum of columns are your number
Sum of main diagonal are your number
Sum of ancillary diagonal are your number
Sum of the edge points are you number*/
#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>
using namespace std;
class Magic {
	string fn;
	int **x, n, divn, a; 
	public:
		Magic (){
			a=0;
			divn=1;
			
			//Allocation of dynamic memory.
			x = new int *[4];
	
			for(int i = 0; i < 4; ++i){
				x[i] = new int [4];
			}
	
	
			//Check: Dynamic memory allocated or not.
			if(x == NULL) {
				exit(1);
			}
			
			for(int i = 0;i < 4; ++i){
				if(x[i] == NULL){
					exit(1);
				}
			}
		}
		
		bool forcheckdigit (string a);
		int digitcount (int n);
		void magicsquare ();
		
		
		~Magic (){
			for (int i=0; i<4; ++i){
				delete []x[i];
			}
			
			delete []x;
		}
};



bool Magic::forcheckdigit (string a)
{
    if(a.size()==0) return false;
    
    
	for(unsigned int i=0; i<a.size(); i++) {
	    if((a[i]>='0' && a[i]<='9')==false) {
	    	return false;
	    }
	}
	    
	return true;
}


int Magic::digitcount(int n){
	int k, a=0;
	k=n;
	do {
		k=k/10;
		++a;
	} while (k!=0);
	
	return a;
}




void Magic::magicsquare(){
	writeagain:
	cout<<"Your number (min. 4): "; getline(cin, fn);
		
	//string fn to int n
	if (forcheckdigit(fn)){
		istringstream line (fn);
		line>>n;
	}
	
	else {
		system("cls");
		goto writeagain;
	}
	
	if (n<4){
		system("cls");
		goto writeagain;
	}
	
	
	//Divide variable n
	
	for (int i=2; i<26; ++i){
		while (n%i==0 && n/i>4){
			n/=i;
			divn*=i;
		}
	}
	
	
	//Build Magic Square
	
	again:
	
	//For edge points
	srand (time(NULL));
	do {
		a=0;
		x[a][a]=rand()%(n-2)+1;
		x[a][3]=rand()%(n-2)+1;
		x[3][a]=rand()%(n-2)+1;
		x[3][3]=rand()%(n-2)+1;
	} while (x[a][a]+x[a][3]+x[3][a]+x[3][3]!=n);
	
	
	
	//For main diagonal
	srand (time(NULL));
	do {
		for (int i=1; i<3; ++i){
			x[i][i]=rand()%(n-2)+1;
		}
	} while (x[0][0]+x[1][1]+x[2][2]+x[3][3]!=n);
	
	
	
	//For ancillary diagonal
	srand (time(NULL));
	do {
		for (int i=1; i<3; ++i){
			x[i][4-1-i]=rand()%(n-2)+1;
		}
	} while (x[3][0]+x[2][1]+x[1][2]+x[0][3]!=n);
	
	



	//For lines
	srand (time(NULL));
	while (a!=4){
	
		do {
			for (int i=0; i<4; ++i){
				
				//To exclude the main dialog
				if (a!=i){
					
					//To exclude the edge points in ancillary diagonal
					if (a!=0 || i!=3){
						if (a!=3 || i!=0){
							
							//To exclude the center points in ancillary diagonal
							if (a!=1 || i!=2){
								if (a!=2 || i!=1){
									x[a][i]=rand()%(n-2)+1;
								}
							}
						}
					}
				}
				
					
					
			}

		} while (x[a][0]+x[a][1]+x[a][2]+x[a][3]!=n);
		
		++a;
	}
	
	
	
	for (int i=0; i<4; ++i){
		if (x[0][i]+x[1][i]+x[2][i]+x[3][i]!=n){
			goto again;
		}
	}
	
	for (int i=0; i<4; ++i){
		for (int j=0; j<4; ++j){
			x[i][j]*=divn;
		}
	}
	
	
	
	for (int i=0; i<4; ++i){
		for (int j=0; j<4; ++j){
			cout<<x[i][j]<<setfill(' ')<<setw(3-digitcount(x[i][j]))<<" ";
		}
		cout<<endl;
	}
}


int main (){
	Magic ob;
	ob.magicsquare();
	
	system("pause");
	return 0;
}
