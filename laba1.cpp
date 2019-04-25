#include "iostream"

#define VAR 314  // Указать три последние цифры своего студ шифра

int y, n, r, N_op, z;

int f(int x)
{									N_op++;		// ( x )
	n++; 							N_op++;  	// ++
	//std::cout<< " f("<<x<<")";		
	N_op++;		// cout
									N_op++;		// (x>0)	
	if (x>0)
		{
			r++;					N_op++;		// ++
/* (*) */	
		///  return f(x/3)+ f(x-2)+f(0);  N_op+=8; // / (.) + - (.) + (.) return
			N_op+=9;
			return f(x / 2) + f(x - 2) * f(3*x/5);	
		}
	else 
		{	
			//std::cout<< std::endl;	
			N_op++;		// cout	
			z++;	N_op++;				N_op++;		// ++	
		 	return 1;				N_op++;		// return
		}
}

void variant(void)
{
	int var = (VAR<100)?VAR+100:VAR;
	
	int v1, v2, v3;
	
	v1 = var % 10		; 
	v2 = var / 10 	% 10; 
	v3 = var / 100  % 10; 
	std::cout <<std::endl<<std::endl<< "(Student: "<<VAR<<")----> f";
	if (v1 > 5)	std::cout <<"(x - "<<v1%3+1<<")";
				else std::cout <<"(x / "<<v1%2+2<<")";
	std::cout << " + f";			
	if (v2 < 5)	std::cout <<"(x - "<<v2%3+1<<")";
				else std::cout <<"(x / "<<v2%2+2<<")";
				
	if (((v3+v2+v1)%3)==0)	std::cout << " - f("<<v1+1<<"*x/"<<v1+3<<")"			<< std::endl;			
	if (((v3+v2+v1)%3)==1)	std::cout << " + f("<<"x -"<<v2+1<<") "		<< std::endl;			
	if (((v3+v2+v1)%3)==2)	std::cout << " * f(3*x/5)"	<< std::endl;			

}

int main(void)
{
	int  N = 10;
	for(int i=1; i<N;i++){
	
	n=0; 		// Общее количество вызовов
	r= 0; 		// Общее количество внутренних узлов
	z= 0; 		// Общее количество листьев
	N_op=0;		// Общее количество инструкций
		// Глубина рекурсии
	
	f(i);
	
	std::cout<<" N = "<< i << " r = "<< r << " z = " << z<< " N_op ="<<N_op<<std::endl;
}
	variant();
}
