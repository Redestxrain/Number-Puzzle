#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#include <ctime> 
#include <string>
#include <windows.h>

using namespace std;


//檢查拼圖是否有解
int ans_check(int *p, int n){
	int i = 0 , j , sum = 0, x, y, position = 0;
	for(i; i < n; ++i){
		for(j = 15; j > i; --j){
			if(p[i] > p[j])sum += 1; //倒序和加 1 
		}
		if (p[i] == 16){
			x = i / 4;	y = i % 4;
			position = (4 - x) +(4 - y);
		} 
	}
	if ((position + sum)%2 == 0)return 1;
	else return 0;
}


//數字交換位置 
void value_ch(int &a, int &b){
	int k;
	k = a;
	a = b;
	b = k;
}

//改變字碼顏色
void SetColor(unsigned short ForeColor=4,unsigned short BackGroundColor=0)
//給予參數默許值，使它可以接受0/1/2個參數
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); //本例以輸出為例
    SetConsoleTextAttribute(hCon,ForeColor|BackGroundColor);
};

int ColorCode(int f,int b)
{
    return f + 16*b;
} 
////////////////////////////////////////////



int main(){
	
	system("color f0");	
	
	//隨機分配初始值 
	top:
	srand((unsigned)time( NULL ));
	int puzzle_i[16];
	int number[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int i,j,k,l,reset,move = 0;
	for(i = 0; i<16; ++i){
		puzzle_i[i] = number[j = rand()%(16 - i)];
		number[j] = number[15-i];
	}
	/////////////////////////////
	
	//引入函式(1) 
	reset = ans_check(puzzle_i, 16);
	if(reset == 0)goto top;
	////////////////////////////
	
	//分配數字至4X4矩陣
	int puzzle[4][4];
	for (i = 0; i < 4; ++i){
		for (j = 0; j < 4; ++j){
			puzzle[i][j] = puzzle_i[i*4 + j];
		}
	} 
	////////////////////////////
	
	
	//開頭畫面
	int mode;
	string title = "數字拼圖";
	string mode_1 = "1.自由模式(不限制步數)";
	string mode_2 = "2.挑戰模式(限制100步)";
	string mode_3 = "3.急速模式(限制50秒)";
	string hint = "請選擇模式：";
	cout << title <<'\n'<<'\n'<<mode_1<<'\n'<<mode_2<<'\n'<<mode_3<<'\n'<<'\n'<< hint ;
	mode_select:
	cin >> mode;
	
	if(mode >= 1 && mode <= 3)system("cls");
	else{
		cout<<"請重新輸入：";
		goto mode_select; 
	} 
	
	//角色介紹、選擇 
	int character[6] = {4 , 12, 14, 10, 1, 13} ; //矩陣內為色碼 
	
	int page_n = 0;
	
	choose:
	if(page_n == 2){system("color 70");	i = 7;}
	else{system("color f0");i = 15;} 
	SetColor(ColorCode(0,i));	cout << "角色選擇"<<endl<<endl; 
	SetColor(ColorCode(4,i));	cout <<"〥"<<' ';
	SetColor(ColorCode(12,i));	cout <<"〥"<<' ';
	SetColor(ColorCode(14,i));	cout <<"〥"<<' ';
	SetColor(ColorCode(10,i));	cout <<"〥"<<' ';
	SetColor(ColorCode(1,i));	cout <<"〥"<<' ';
	SetColor(ColorCode(13,i));	cout <<"〥"<<' ';
	SetColor(ColorCode(0,i));	cout<<endl<<"___________________________"; 
	cout <<endl<<endl<<"左右方向鍵切換角色介紹"<<endl<<"Enter 鍵選擇角色" ; 
	cout<<endl<<endl<<"___________________________";
	
	if(page_n == 0){
		cout<<endl<<endl;
		SetColor(ColorCode(4,15));	
		cout <<"〥"<<' '<<"元首"<<endl<<endl;
		cout <<"「霸氣，狂野，恐懼的具現，稱霸世界的元首」"; 
		cout << endl<<endl <<setw(10)<<"  (1/6) >";
	}
	if(page_n == 1){
		cout<<endl<<endl;
		SetColor(ColorCode(12,15));
		cout <<"〥"<<' '<<"腹黑變態"<<endl<<endl;
		cout <<"青澀、腹黑、病態的愛戀，求愛的化身，渴望幸福之人";
		cout << endl<<endl <<setw(10)<<"< (2/6) >"; 
	}
	if(page_n == 2){
		cout<<endl<<endl;
		SetColor(ColorCode(14,i));
		cout <<"〥"<<' '<<"焦糖布丁"<<endl<<endl;
		cout <<"活♂力♂  青♂春♂  哲♂學♂  守♂護♂"; 
		cout << endl<<endl <<setw(10)<<"< (3/6) >";
	}
	if(page_n == 3){
		cout<<endl<<endl;
		SetColor(ColorCode(10,i));
		cout <<"〥"<<' '<<"王"<<endl<<endl;
		cout <<"王的慈悲，王的大度，當然是選擇原諒她"; 
		cout << endl<<endl <<setw(10)<<"< (4/6) >";
	}
	if(page_n == 4){
		cout<<endl<<endl;
		SetColor(ColorCode(1,15));
		cout <<"〥"<<' '<<"辣個男人"<<endl<<endl;
		cout <<"快還要更快，十秒內沒拼出來算我輸"; 
		cout << endl<<endl <<setw(10)<<"< (5/6) >";
	}
	if(page_n == 5){
		cout<<endl<<endl;
		SetColor(ColorCode(13,15));
		cout <<"〥"<<' '<<"曇"<<endl<<endl;
		cout <<"害躁、沉默，謎般的存在，如玻璃般脆弱，如夢般飄渺"; 
		cout << endl<<endl <<setw(10)<<"< (6/6)  ";
	}
	
	int page = _getch(); 
	
	if(page == 75){if(page_n != 0)page_n -= 1;}//左移 
	if(page == 77){if(page_n != 5)page_n += 1;}//右移   
	
	if(page == 13); 
	
	else{system("cls"); 
	goto choose;} 
	

	system("cls");
	
	int bg = 0; bg = i;
	
	time_t tstart,tstop,trun; 
	tstart = time(NULL);
	
	//顯示拼圖
	start:
	
	trun = time(NULL);
	
	cout<<endl;
	SetColor(ColorCode(0,bg));	
	
	for (i = 0; i < 4; ++i){
		for (j = 0; j < 4; ++j){
			if(puzzle[i][j] == 16){
				
				SetColor(ColorCode(character[page_n],bg));	
				cout << setw(5) <<"〥";
				SetColor(ColorCode(0,bg));	
				k = i;	l = j;
				
			}
			
			else{
				if(puzzle[i][j] == i*4 + j + 1)SetColor(ColorCode(character[page_n],bg));
				cout << setw(5) <<puzzle[i][j];
				if(puzzle[i][j] == i*4 + j + 1)SetColor(ColorCode(0,bg));
			 } 
		}
		
		cout<<endl<<endl;
	} 
	if(mode == 1)cout<<"花費步數："<<move / 2 ;
	else if(mode == 2) cout<<"剩餘步數："<<100 - (move / 2);
	else cout<<'\r'<<"剩餘秒數："<<50 - (trun  - tstart)<<" 秒"<<flush;

	////////////////////////////
	
	
	int c = _getch();
	
	//引入函式(2) 
	if(c == 72){ if(k != 0)value_ch(puzzle[k][l],puzzle[k-1][l]); }//上移 
	if(c == 80){ if(k != 3)value_ch(puzzle[k][l],puzzle[k+1][l]); }//下移 
	if(c == 75){ if(l != 0)value_ch(puzzle[k][l],puzzle[k][l-1]); }//左移 
	if(c == 77){ if(l != 3)value_ch(puzzle[k][l],puzzle[k][l+1]); }//右移 
	
	
	/////////////////////////////
	
	//遊戲結束條件
	int check[16];
	for(i = 0; i < 4; ++i){
		for(j = 0; j < 4; ++j){
			if(puzzle[i][j] == i*4 + j + 1)check[i*4 + j] = 1;
			else check[i*4 + j] = 0;
		}
	}
	
	int end = 0;
	for(i = 0; i < 16; ++i)end +=check[i];
	
	if(end == 16){
		system("cls");
		tstop = time(NULL);
		
		SetColor(ColorCode(character[page_n],bg));
		cout << "你找到阿達密藏的寶藏!!"<<endl;
		cout <<endl<<"總共耗費："<<move/2+1<<"步"<<endl;
		cout <<"通關時間："<<tstop - tstart<<"秒"; 
		return 0;
	}
	
	if (100 - (move/2) == 1 && mode == 2){
			system("cls");
		tstop = time(NULL);
		
		SetColor(ColorCode(character[page_n],bg));
		cout << "挑戰失敗，再接再厲!!"<<endl;
		return 0;
	}
	if ((trun - tstart) == 50 && mode == 3){
			system("cls");
		tstop = time(NULL);
		
		SetColor(ColorCode(character[page_n],bg));
		cout << "挑戰失敗，再接再厲!!"<<endl;
		return 0;
	}
	
	++ move;
	
	system("cls");
	goto start;
} 
