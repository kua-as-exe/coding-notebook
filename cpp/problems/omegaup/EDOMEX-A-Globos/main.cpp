#include <iostream>
#include <vector>
using namespace std;

struct cilindro { long long int x, r; };
struct globo { long long int x, r, l; };

long long int B;
int N, M;

vector<cilindro> cilindros;
vector<globo> globos;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  cin >> B;
  cin >> N >> M;
  cilindros.resize(N);
  globos.resize(M);
  
  /* long long int maxr = 0; */

  for(int i = 0; i < N; i++){
    cin >> cilindros[i].x >> cilindros[i].r;
    /* maxr = max(maxr, cilindros[i].r); */
  }
  for(int i = 0; i < M; i++){
    cin >> globos[i].x >> globos[i].r >> globos[i].l;

  }
 
  cout << M; 

  return 0;
}
