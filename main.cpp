#include <iostream> //FINALLLLLL
#include <stdlib.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;
int n; // vertices
int m; // edges
// int graph[MAXN][MAXN];
const int MAXN = 16;
// vector<bool>check(20,false);
vector<int> BY1(30, 0);
vector<int> BY2(30, 0);
vector<int> BY3(30, 0);
vector<int> BY4(30, 0);
vector<int> BY5(30, 0);

int distanceBY1 = 0;
int distanceBY2 = 0;
int distanceBY3 = 0;
int distanceBY4 = 0;
int distanceBY5 = 0;
int d1=0;
int d2=0;
int d3=0;
int d4=0;
int d5=0;

int graph[MAXN][MAXN] = {0}; // weighted adjacency matrix

int nearest_neighbor(int start, vector<int> &tour)
{
bool visited[MAXN] = {false}; // whether a vertex has been visited
visited[start] = true;
tour.push_back(start);

int cost = 0;
while (tour.size() < n)
{
int min_cost = INT_MAX;
int min_vertex = -1;
for (int i = 0; i < n; i++)
{
if (visited[i])
{
for (int j = 0; j < n; j++)
{
if (!visited[j] && graph[i][j] != 0 && graph[i][j] < min_cost)
{
min_cost = graph[i][j];
min_vertex = j;

}

}

}

}
if (min_vertex == -1)
{
// the graph is not connected, start a new component
for (int i = 0; i < n; i++)
{
if (!visited[i])
{
start = i;
visited[start] = true;
tour.push_back(start);
break;

}

}

}
else
{
tour.push_back(min_vertex);
visited[min_vertex] = true;
cost += min_cost;

}

}

// add the cost of returning to the starting vertex
tour.push_back(start);
cost += graph[tour.back()][start];

return cost;
}

int findd(vector<vector<int>> dist, int n, int s, vector<bool> check)
{
int minto = 1000;
int a = 0;
int alpha = 0;
for (alpha = 0; alpha < n; alpha++)

{
if (dist[s][alpha] < minto && check[alpha] != true)

{
a = alpha;
minto = dist[s][alpha];

}

}

return a;
}

void printSolution(vector<vector<int>> dist, int n)
{
cout << "The following matrix shows the shortest "
"distances"
" between every pair of vertices \n";

for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
{
if (dist[i][j] == 1000)
cout << "INF"<< " ";
else cout << dist[i][j] << " ";

}
cout << endl;


}
}

int floydd(vector<int> tour, vector<vector<int>> dist, int n, int vertices)
{
for (int k = 0; k < n; k++)
{
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
{
if ((dist[i][j] > (dist[i][k] + dist[k][j])) && dist[k][j] != INT_MAX
&& dist[i][k] != INT_MAX)

{
dist[i][j] = dist[i][k] + dist[k][j];

}

}

}

}
int count = 0;
int s = 0;
//tour.push_back(0);
vector<bool> check(n, false);
do
{
int ans = findd(dist, n, s, check);
tour.push_back(ans);
check[ans] = true;
s = ans;
count++;

}
while (count != (vertices + 1));
tour.push_back(0);

printSolution(dist, n);

//path printing

int costt = 0;
cout << "~~~" << endl;
for (int i = 0; i < 168; i++)

{
cout << "*";
cout.flush();
// ensure the * is immediately displayed

// wait 50 milliseconds between each *

}
cout << "Pay-Out for the delivery boy is : " << (n - 1) * 50 << endl;
for (int i = 0; i < 168; i++)

{
cout << "*";
cout.flush();
// ensure the * is immediately displayed

// wait 50 milliseconds between each *

}
for (int i = 0; i < tour.size(); i++)

{
cout << tour[i] << "-->";
costt += dist[i][i + 1];

}

return costt;
}

int partition(vector<int> &arr, int low, int high)
{
int pivot = arr[high];
int i = low - 1;

for (int j = low; j <= high - 1; j++)
{
if (arr[j] < pivot)
{
i++;
swap(arr[i], arr[j]);

}

}

swap(arr[i + 1], arr[high]);
return i + 1;
}

void quicksort(vector<int> &arr, int low, int high)
{
if (low < high)
{
int pivot = arr[low];
int i = low + 1, j = high;
while (i <= j)
{
while (i <= j && arr[i] >= pivot) i++;
while (i <= j && arr[j] < pivot) j--;
if (i <= j)
{
swap(arr[i], arr[j]);
i++;
j--;

}

}
swap(arr[low], arr[j]);
quicksort(arr, low, j - 1);
quicksort(arr, j + 1, high);

}
}
int bill()
{

cout << endl;

cout << endl;
int food;
int check2;
int totalcost = 0;

do

{
cout << "enter code" << endl;
cin >> food;

switch (food)

{
case 1:
cout << "\t\t\t\t\t1 X Paneer : Rs.100 " << endl;
totalcost += 100;
break;
case 2:
cout << "\t\t\t\t\t1 X Dal : Rs.200 " << endl;
totalcost += 200;
break;
case 3:
cout << "\t\t\t\t\t1 X Chinese : Rs.300 " << endl;
totalcost += 300;
break;
case 4:
cout << "\t\t\t\t\t1 X Breads : Rs.400 " << endl;
totalcost += 400;
break;
case 5:
cout << "\t\t\t\t\t1 X Italian : Rs.500 " << endl;
totalcost += 500;
break;

}


}

while (food != -1);

return totalcost;
}
int vert()
{

cout << endl;
cout << "enter number of deliveries and edges between them : ";
int m;
cin >> n >> m;
for (int i = 0; i < m; i++)
{
int u, v, w;
cin >> u >> v >> w;
graph[u][v] = w;
graph[v][u] = w;

}
int vt;
cout << endl;
cout << "Enter Delivery Person code : ";
cin >> vt;
if (vt==1){
    d1=d1+1;
}
else if (vt==2){
    d2=d2+1;
}
else if (vt==3){
    d3=d3+1;
}
else if (vt==4){
    d4=d4+1;
}
else {
    d5=d5+1;
}
switch (vt)

{
case 1:
BY1.push_back(n - 1);
break;
case 2:
BY2.push_back(n - 1);
break;
case 3:
BY3.push_back(n - 1);
break;
case 4:
BY4.push_back(n - 1);
break;
default : BY5.push_back(n - 1);
break;

}
vector<int> tour;
int start = 0;


int cost = nearest_neighbor(start, tour);

cout << "Minimal tour starting from " << start << ": ";
for (int vertex : tour)
{
cout << vertex << " ";

}
cout << "~~~" << endl;
cout << "Pay-Out for the delivery boy is : " << (n - 1) * 50 << endl;

return 0;
}

void work()
{
int opt;

cout << "1. Do you want to Determine Employee Of the Week?" << endl;
cout << "2. Create New order" << endl;
cin >> opt;
if (opt == 1)

{

vector<int> arr;
for (int i = 0; i < 5; i++)
{
int detail;
if (i==0){
cout << "Delivery by Boy " << i + 1 <<" is "<< d1<<endl;
detail = d1;
arr.push_back(detail);
}
else if (i==1){
cout << "Delivery by Boy " << i + 1 <<" is "<< d2<<endl;
detail = d2;
arr.push_back(detail);
}
else if (i==2){
cout << "Delivery by Boy " << i + 1 <<" is "<< d3<<endl;
detail = d3;
arr.push_back(detail);
}
else if (i==3){
cout << "Delivery by Boy " << i + 1 <<" is "<< d4<<endl;
detail = d4;
arr.push_back(detail);
}
else {
cout << "Delivery by Boy " << i + 1 <<" is "<< d5<<endl;
detail = d5;
arr.push_back(detail);
}

}

// Sort the array in descending order
quicksort(arr, 0, arr.size() - 1);
reverse(arr.begin(), arr.end());

// Print the sorted array
cout << "Sorted order of details ";
for (int i = 0; i < arr.size(); i++)
{
cout << arr[i] << " ";

}

// Print the very first element of the sorted array
cout << "\nEmployee of the week Deliveries are " << arr[4] << endl;

}

else if (opt == 2)
{
int rows, cols, vertices, costy = 0;
cout << "Enter number of deliveries : ";
cin >> rows;
vertices = rows;
cols = rows + 1;
rows = rows + 1;
//bill
cout << "\t\t\t\t\t\t\tCODES FOR FODD ITEMS / MENU:-" << endl;
MessageBox(NULL, "1) for paneer \n 2)for dal \n 3)for chinese \n 4)for breads \n 5)for italian \n -1 For BILLING ", "MENU", MB_OK);
for (int i = 0; i < vertices; i++)

{
cout << endl
 << endl;
cout << "\t\t\t\t\t\t\t ~PAPII DI HATTI~\t\t\t\t\t\t\t" << endl
  << endl;
// Get the current time point
auto now = chrono::system_clock::now();

// Convert the time point to a time_t object
time_t time = chrono::system_clock::to_time_t(now);

// Print the time stamp
cout << "\t\tTime : " << ctime(&time);
cout << "\t\t GSTIN: 21145879610" << endl;
int tc = bill();
for (int i = 0; i < 168; i++)

{
cout << "-";
cout.flush();
// ensure the * is immediately displayed
this_thread::sleep_for(chrono::milliseconds(1));
// wait 50 milliseconds between each *

}
cout << endl;
cout << "\t\t\t\t\t\t\t Bill for " << i << " order is ==> " << tc << endl;
for (int i = 0; i < 168; i++)

{
cout << "-";
cout.flush();
// ensure the * is immediately displayed
this_thread::sleep_for(chrono::milliseconds(1));
// wait 50 milliseconds between each *

}
cout << endl;
cout << endl;


}

vector<vector<int>> matrix(rows, vector<int>(cols));
vector<int> tour;
if (vertices <= 5)
{
cout << "Enter delivery coordinates ~~ Enter 1000000 for distance between same coordinate ( 1000000 here is taken as infinity) :\n";
for (int i = 0; i < rows; i++)
{
for (int j = 0; j < cols; j++)
{
if (i == j)

{
matrix[i][j] = 0;

}
else
{
cout << "Enter distance between " << i << " " << j << " ";
cin >> matrix[i][j];

}

}
cout << endl;

}
cout << "The coordinates you entered are :\n";
for (int i = 0; i < rows; i++)
{
for (int j = 0; j < cols; j++)
{
cout << matrix[i][j] << " ";


}
cout << endl;

}
}

if (vertices <= 5)

{
int vt = 0;
cout << "Enter the code for delivery person available" << endl;
cin >> vt;
if (vt==1){
    d1=d1+1;
}
else if (vt==2){
    d2=d2+1;
}
else if (vt==3){
    d3=d3+1;
}
else if (vt==4){
    d4=d4+1;
}
else {
    d5=d5+1;
}

switch (vt)

{
case 1:
BY1.push_back(vertices);
break;
case 2:
BY2.push_back(vertices);
break;
case 3:
BY3.push_back(vertices);
break;
case 4:
BY4.push_back(vertices);
break;
default : BY5.push_back(vertices);
break;

}
switch (vt)

{
case 1:
distanceBY1 += floydd(tour, matrix, rows, vertices);
break;
case 2:
distanceBY2 += floydd(tour, matrix, rows, vertices);
break;
case 3:
distanceBY3 += floydd(tour, matrix, rows, vertices);
break;
case 4:
distanceBY4 += floydd(tour, matrix, rows, vertices);
break;
default : distanceBY5 += floydd(tour, matrix, rows, vertices);
break;
}

}

else
{
vert();

}
}

}
int main()
{

system("color 5F");
for (int i = 0; i < 168; i++)

{
cout << "*";
cout.flush();
// ensure the * is immediately displayed

// wait 50 milliseconds between each *

}
cout << endl;
cout << "\t\t\t\t\t\t\t** WELCOME TO REASTURANT LOGISITIC SERVICES **" << endl
 << endl;
cout << "\t\t \t\t\t*HERE YOU CAN CHOOSE FOR DELIVERY TASK ASSIGNMENT OR EMPLOYEE INCENTIVE MANAGEMENT *" << endl
 << endl;

for (int i = 0; i < 168; i++)

{
cout << "*";
cout.flush();
// ensure the * is immediately displayed

// wait 50 milliseconds between each *

}
cout << endl;
int sa = 1;
while (sa == 1)
{
work();

cout << "Enter 1 if you want to continue : ";
cin >> sa;
}
return 0;
}
