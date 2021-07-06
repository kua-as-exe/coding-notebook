#include <iostream>
using namespace std;

#define lli long long int
lli n, t, x[5000000], m;

lli sum(int i, int j){
  lli s = x[j];
  if(i > 0) 
    s -= x[i-1];
  return s;
}

void printX(){
  cout << endl << "i: \t";
  for(int i = 0; i < n; i++)
    cout << i << "\t";
  cout << endl << "x: \t";
  for(int i = 0; i < n; i++)
    cout << x[i] << "\t";
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  cin >> x[0];
  for(int i = 1; i < n; i++){
    cin >> t;
    m = max(m, t);
    x[i] = t + x[i-1];
  }

  // printX();
  // cout << "Max: " << m << endl;

  lli total = x[n-1];

  bool posible = true;

  lli validPosCount = total/(n-1);
  // printf("Posiciones válidas: %lld\n", validPosCount);
  lli lastPos = n-1;
  for(int p = 0; p < validPosCount; p++){
    // printf("Probando para %d:\n", p);
    int a = 0, b = lastPos, f = -1;
    while(a <= b && f == -1){
      int ti = (a+b)/2;
      lli s = sum(ti, lastPos);
      // printf(" %d-%d: (%d) %lld\n", a, b,ti, s);
      if( s == m ) f = ti;
      else if(s > m) a = ti+1;
      else if(s < m) b = ti-1;
    }
    // printf("- %d\n", f);
    if(f == -1){
      posible = false;
      break;
    }
    lastPos = f-1;
  }

  if(posible){
    // printf("Posible\n");
    cout << validPosCount;
    return 0;
  }

  // for(lli k = 1; k <= x[n-1]/2; k++){
  //   if (last%k == 0){
  //     lli F = last/k, f = 0;
  //     for(lli i = 0; i < n && f < F; i++)
  //       if(x[i]%k == 0)
  //         f++;
      
  //     if(f == F){
  //       cout << f;
  //       return 0;
  //     }
  //   }
  // }
  
  cout << 1;
  return 0;
}
