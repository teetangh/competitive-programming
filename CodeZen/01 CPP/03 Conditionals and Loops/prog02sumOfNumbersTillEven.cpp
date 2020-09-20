#include <iostream>
using namespace std;

int main()
{

    /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int N;
    int sum = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 0)
            sum = sum + i;
    }

    cout << sum;
}

// Input Format :
// Integer N
// Output Format :
// Required Sum 
// Sample Input 1 :
//  6
// Sample Output 1 :
// 12