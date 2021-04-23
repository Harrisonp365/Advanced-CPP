////////////////////////////////////TWONUMBERSUM//////////////////////////////////////////////////
/*
#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
//FOR LOOP THROUGH ARRAY STARTING AT INDEX 0, STORE AS FIRST NUM
 for(int i = 0; i < array.size() - 1; i++)
 {
	 int firstNum = array[i];
	 //START AT INDEX POS 1 AND STORE NUMBER
		for(int j = i + 1; j < array.size(); j++)
		{
			int secondNum = array[j];
			//CHECK IF ADDITION OF BOTH NUMBERS = TARGET
				if(firstNum + secondNum == targetSum)
					return vector<int>{firstNum, secondNum};
		}
 }
return {};
}
------------------------------------------------------------------------------------------------
////////////////////////////////////VALID SUBSEQUENCE//////////////////////////////////////////
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
// STORE BOTH ARR INDEX POINTS
  int arrIndex = 0;
  int seqIndex = 0;

	while(arrIndex < array.size() && seqIndex < sequence.size()) // MAKE SURE NO OUT OF BOUNDS
	{
		if(array[arrIndex] == sequence[seqIndex])
			seqIndex++;
		arrIndex++;
	}
  return seqIndex == sequence.size(); // IF THIS HAPPENS THE RETURNS TRUE
}
--------------------------------------------------------------------------------------------------
/////////////////////////////////////SQURE ROOT OF ORIGINAL ARR//////////////////////////////
#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
// CREATE NEW VECTOR FOR SQUR ROOT
	vector<int>sortedSquareArr(array.size(), 0);
	//LOOP THROUGH ARR AND STORE NUM
  for(int i = 0; i < array.size(); i++)
	{
		int num = array[i];
		sortedSquareArr[i] = num * num; // X TOGETHER
	}
	//SORT NEW ARR IN ACCENDING ORDER
	sort(sortedSquareArr.begin(), sortedSquareArr.end()); 
  return sortedSquareArr;
}
-----------------------------------------------------------------------------------------------
/////////////////////////////////TOURNAMENT WINNER USING TWO ARRAYS////////////////////////////

#include <vector>
#include <unordered_map>
using namespace std;
//EASIER TO UNDERSTAND HOW THE ARRAYS WORK WITH THEIR INDEXS
const int HomeTeamWon = 1;
//DEFINE AND UPDATE FUNCTION
void updateScores(string team, int points, unordered_map<string, int> &scores);

string tournamentWinner(vector<vector<string>> competitions,
						vector<int> results)
{
//KEEP CURRENT BEST TEAM UPDATED (TEAM WITH MOST POINTS)
	string currentBestTeam = "";
	unordered_map<string, int> scores = {{currentBestTeam, 0}};

	for(int i = 0; i < competitions.size(); i++)
	{
		auto result = results[i];
		auto competition = competitions[i];
		auto homeTeam = competition[0];
		auto awayTeam = competition[1];
		auto winningTeam = result == HomeTeamWon ? homeTeam : awayTeam;

		updateScores(winningTeam, 3, scores);

		if(scores[winningTeam] > scores[currentBestTeam])
		{
			currentBestTeam = winningTeam;
		}
	}
  return currentBestTeam;
}

	void updateScores(string team, int points, unordered_map<string, int> &scores)
	{
		if(scores.find(team) == scores.end())
			scores[team] = 0;

		scores[team] += points;
	}
-----------------------------------------------------------------------------------------------
/////////////////////////////// BASIC BUBBLE SORT ALGO///////////////////////////////////
BASIC TIME COMPLEXITY O(N2) AND IS STABLE
void BubbleSort(arr, n) 
{
	int i;
	int j;

	for(int i = 0; i < n -1; i++)
	{
		for(int j = 0; j < n - i - 1; ++j)
		{
			if(arr[j] > arr[j + 1]
			{
				swap(arr[j], arr[j + 1]
			}
		}
	}
}
---------------------------------------------------------------------------------------------
/////////////////////////////////// SELECTION SORT ///////////////////////////////////////
BASIC TIME COMPLEXITY O(N2) AND IS NOT STABLE
void selectSort(arr, n)
{
	for(int i = 0; i < n - 1; i++)
	{
		minIndex = i;
		for(j = 0; j < n; j++)
		{
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[minIndex], arr[j]);
	}
}
-------------------------------------------------------------------------------------------------
/////////////////////////////////// INSERT SORT //////////////////////////////////////////////
BASIC TIME COMPLEXITY O(N2)  AND STABLE
void InsertSort(arr, n)
{
	int i, j, temp;

	for(int i = 1; i < n; i++) // CHECK ARRAY FOR EACH NUMBER
	{
		temp = arr[i];
		j = i -1;
		while(j >= 0 && arr[j] > temp) // CHECK WHERE TO INSERT NUMBER WE ARE CHECKING
		{
			arr[j + 1] == arr[j]; // SWAPPING THE VALUES OF THE ARRAY
			j--; // CHECK ALL INDEX VALUES BEFORE INDEX WE ARE CHECKING
		}
		arr[j + 1] = temp;
	}
}
-------------------------------------------------------------------------------------------------
///////////////////////////////////// MERGE SORT ////////////////////////////////////////////////
BASIC TIME COMPLEXITY O(LOGn) AND IS STABLE
void mergeSort(arr, left, right)
{
	if(right < left)
	{
		middle = (left + right) / 2;
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		merge(arr, left, middle, right)
	}
}
--------------------------------------------------------------------------------------------------
//////////////////////////////////// QUICK SORT /////////////////////////////////////////////
BASIC TIME COMPLEXITY 0(nLOGn) AND IS STABLE
void quickSort(arr, left, right)
{
	if(left < right) 
	{
		p = partition(arr, left, right);
		quickSort(arr, left, p - 1);
		quickSort(arr, p + 1, right);
	}
}

auto Partition(arr, left, right)
{
	pivot = arr[right]; //PIVOT POINT IS LAST INDEX IN ARR
	i = left - 1;

	for(j = left; j <= right - 1; j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j];
		}
	}
	swap(arr[i + 1], arr[right]);
	return(i + 1);
}
-------------------------------------------------------------------------------------------------
/////////////////////////////////// DYNAMIC FIBONACCI ////////////////////////////////////////

int f(int n)
{
	int arr[n];
	arr[0] = 0;
	arr[1] = 1;

	if(n = 0 || 1)
	return;

	for(int i = 2; i <= n; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		return arr[n];
	}
}
-----------------------------------------------------------------------------------------------
/////////////////////////////////// HackerRank Box It ////////////////////////////////////
//class Box
{
public:
	Box();
	//Box(int l, int b, int h);
	//Box(const Box box);

	//int getLength(); // return box length
	//int getBreadth();
	//int getHeight();
	//long long CalculateVolume();

	//friend bool operator<(Box& b1, Box& b2);
	//friend ostream& operator<<(ostream& out, Box& B);
private:
	//int l;
	//int b;
	//int h;
};

//int main()
{


	return 0;
}

//Box::Box()
{
	l = 0;
	b = 0;
	h = 0;
}

//Box::Box(int length, int breadth, int height)
{
	l = length;
	b = breadth;
	h = height;
}

//Box::Box(const Box& B)
{
	l = B.l;
	b = B.b;
	h = B.h;
}

//int Box::getLength()
{
	return (l);
}

//int Box::getBreadth()
{
	return (b);
}

//int Box::getHeight()
{
	return (h);
}

//long long Box::CalculateVolume()
{
	return ((long long)l * b * h);
}

//bool operator<(Box& b1, Box& b2)
{
	if ((b1.l < b2.l) || (b1.b < b2.b && b1.l == b2.l) ||
		(b1.h < b2.h && b1.b == b2.b && b1 == b2.l))
		return (true);
	else
		return (false);
}

//ostream& operator<<(ostream& out, Box& B)
{
	out << B.l << " " << B.b << " " << B.h;
	return out;
}
------------------------------------------------------------------------------------------------
////////////////////////////////////// HOURGLASS ////////////////////////////////////////////
OPTION1:
int hourGlassSum(vector<vector<int>>arr)
{
	int result = -63;

	for(int row = 0; row <= 3; ++row)
	{
		for(int col = 0; col <= 3; ++col)
		{
			int sum = arr[row][col] + arr[row][col + 1] + arr[row][col + 2] + arr[row + 1][col +1]
			+ arr[row + 2][col] + arr[row +2][col + 1] + arr[row + 2] [col + 2];

			result = std::max(result, sum);
 		}
	}
	return result;

}

int main()
{
	vector<vector<int>> arr(6);
	for (int i = 0; i < 6; i++) {
		arr[i].resize(6);

		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int result = hourGlassSum(arr);
	cout << result << "\n";
	return 0;
}

OPTION2:

int hourGlassSum(vector<vector<int>>arr)
{
	int maxSum = -63;

	for(int i = 0; i < arr.size() - 2; i++)
	{
		for(int j = 2; j < arr[0].size(); j++)
		{
			int k = j -2, hourglass = 0;

			 while(k <= j)
			{
				hourglass += arr[i][k] + arr[i + 2][k];
				++k;
			}
			hourglass += arr[i + 1][j - 1]; //middle val
			maxSum = max(hourglass, maxSum);
		}
	}
	return maxSum;
}

same main loop;
*/

