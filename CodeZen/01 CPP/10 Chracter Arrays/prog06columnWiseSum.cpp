#include <iostream>
using namespace std;

int main()
{

    /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int arr[1000][1000];
    int m, n;

    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    int *colsum = new int[n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            colsum[j] += arr[i][j];
        }
    }

    for (int j = 0; j < n; j++)
        cout << colsum[j] << " ";
// }
// Sample Input :
// 4 2
// 1 2
// 3 4
// 5 6
// 7 8
// Sample Output :
// 16 20