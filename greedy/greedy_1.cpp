/*백준 2839번 - 설탕 배달
 *
 * 1. 정확하게 N 킬로그램의 설탕 배달
 * 2. 3kg, 5kg 봉지 있음
 * 3. 가장 적은 개수의 봉지를 가지고 배달하고자 함
 * 4. 몇개의 봉지를 가지고 가면 될 지 구해야 함
 * */

#include <iostream>
using namespace std;
#define WEIGHT3KG 3
#define WEIGHT5KG 5
#define NO_SOLUTION -1
bool Greedy(unsigned short* pTotalWeight, unsigned short* pBagCount){
	/*주어진 무게를 정확하게 만들 수 없으면 return false
	 * 만들 수 있다면 return true
	 * */
	unsigned short remain = *pTotalWeight;
	
	while(true){
		if(remain == 0){
			return true;
		}
		else if(remain - WEIGHT5KG >= 0){
			remain -= WEIGHT5KG;
			*pBagCount += 1;
		}
		else{//remain - WEIGHT5KG < 0
			break;
		}
	} 
	
	unsigned short numOf5KG = *pBagCount;

	while(numOf5KG != 0){
		if(remain == 0){
			return true;
		}
		else if(remain - WEIGHT3KG >= 0){
			remain -= WEIGHT3KG;
			*pBagCount += 1;
		}
		else{
			remain += WEIGHT5KG;
			*pBagCount -= 1;
		}
	}

	if(*pTotalWeight % WEIGHT3KG == 0){
		*pBagCount = *pTotalWeight / WEIGHT3KG;
		return true;
	}
	else{
		return false;
	}
}

int main(void){
	unsigned short totalWeight;
	cin >> totalWeight;
	unsigned short bagCount = 0;
	
	if(Greedy(&totalWeight, &bagCount)){
	
		cout << bagCount << endl; 
	}
	else{

		cout << NO_SOLUTION << endl; 
	}
	
	
	return 0;
}
