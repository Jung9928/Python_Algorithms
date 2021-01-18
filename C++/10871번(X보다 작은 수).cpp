/*
	#### 문제 풀이 TIP ####
	1) ios::sync_with_stdio(0) 코드는 c++ 입출력 stream만 사용하겠다는 선언과도 같다.
	   c++ 컴파일러는 c/c++ 스타일의 입출력 혼용이 가능하기 때문에 표준 입출력들이 동기화 되어 있다.
	   이러한 동기화를 비활성화 시켜줌으로써, cout, cin 입출력 시, 독립적인 c++ 입출력 버퍼를 사용하도록 할 수 있다.

	   위 코드를 사용함으로써 얻는 이점은 버퍼 동기화 작업을 없앰으로써, 코테라는 제한적인 상황에서 속도향상을 기대할 수 있다.
	   그러므로, 코테에서 만약 c++을 사용하는데 c와 c++ 입출력 함수를 혼용해서 사용할 것이 아니라면
	   위 코드를 사용하여 속도향상에 이용할 수 있다.

	   다만 thread를 사용해야 할 경우, 입출력 순서가 엉망이 될 수 있으므로 코테에서만 사용하도록 하자.
	   
	   왜냐하면, c++ stream들은 thread-safe(쓰레드 안정성 보장)을 한다. 
	   멀티 쓰레드 프로그래밍을 할 경우, 여러 쓰레드에서 각각 입출력을 수행할 수 있고, race condition이 발생하지 않지만
	   동기화를 비활성화 했으므로 당연히 예상하지 않는 결과를 얻게 된다.

	2) cin.tie(nullptr) 또는 cin.tie(0) 코드는 cout의 출력 버퍼를 비우는 작업을 생략하게 된다.
	   즉, 기존의 입출력 함수인 cin과 cout이 stream과 하나로 묶여있는 것을 untie 함으로써,
	   출력 버퍼를 비우는 작업을 생략하므로 입출력 속도 향상을 기대할 수 있다.

	   사용하는 이유는 백준같은 경우, 입력 값의 순서따위는 채점 대상이 되지 않고
	   오로지 결과 값만을 가지고 채점하게 되므로, cin과 cout, stream을 묶어줄 필요가 없는 것

	   그럼 cin, cout이 stream과 묶인(tie)다면? => 프로그램이 사용자에게 입력을 요청하기 전에 
	   출력버퍼가 플러시될 것이다.

	   예를 들면 다음과 같다.
	   
	   std::cout << "Enter name:";
	   std::cin >> name;

	   위 코드에서 기대하는 결과는 맨 처음 "Enter name:"이라는 문자열이 출력되고
	   사용자가 name 변수에 입력 값을 저장하는 순서를 기대할 것이다.

	   근데 untie를 해버리면 "Enter name:"은 출력되지 않고 바로 사용자에게 입력하라는 명령이 수행된다.
	   이렇듯 어떤 것이 먼저 실행될 지 예측할 수 없다..

	   그러므로, 코테에서만 사용하는 것을 매우 권장함.

*/

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, t;		// 정수 n개, x는 조건으로 사용되는 정수, 주어지는 정수 입력 

	cin >> n >> x;		// n과 x 입력
	while (n--)			// n번 입력해야 하므로, 입력 한 후, n은 1씩 감소
	{
		cin >> t;		// 정수를 n번 입력. 
		if (t < x)		// 입력한 정수 t값과 조건 값인 x를 비교
			cout << t << ' ';		// t가 x보다 작으면 공백으로 구분해 출력.
	}
	return 0;
}