#include <iostream>
#include <math.h>
using namespace std;
int main(){
  float x, y, z;
  cin >> x >> y >> z;
  cout << (((2*x+y)/z)*(pow(y, 3)-z))/((x+2*y+3*z)/(z-2*y-3*x)+pow(x,2)+pow(z,2));
  return 0;
}