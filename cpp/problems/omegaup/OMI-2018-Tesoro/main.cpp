#include <bits/stdc++.h>
using namespace std;

int n, m;
vector < pair < int, int > > tesoros; // Guarda las coordenadas de los tesoros
vector < pair < int, int > > reportados; // Guarda los tesoros reportados
int no_preguntas; // Guarda el número de preguntas que llevas hechas
int llamadas_cavar;

bool error_cavar = false;
// En el momento que Cavar regrese false ya no podrás llamar a Cavar nuevamente
bool Cavar(int i, int j) {
	printf("\nLlamada a Cavar(%d, %d)\n", i, j);
	llamadas_cavar++;

	if(error_cavar)
		puts("Ya no puedes llamar a Cavar.");

	// Verifica si hay un tesoro en esa casilla
	bool encontrado = false;
	for(int k = 0; k < tesoros.size() && !encontrado; ++k) {
		if(tesoros[k].first == i && tesoros[k].second == j)
			encontrado = true;
	}

	// Verifica si ya habías reportado ese tesoro
	bool ya_reportado = false;
	for(int k = 0; k < reportados.size(); ++k)
		if(reportados[k].first == i
		&& reportados[k].second == j)
			ya_reportado = true;

	if(encontrado && !ya_reportado && llamadas_cavar <= tesoros.size()) {
		puts("Encontraste un tesoro!");
		reportados.push_back({i,j});
		return true;
	}


	if(llamadas_cavar > tesoros.size())
		puts("Has excedido la cantidad de llamadas a Cavar.");
	else if(!encontrado)
		puts("Lo siento. No hay un tesoro en esa casilla.");
	else
		puts("Tesoro anteriormente reportado.");

	error_cavar = true;

	return false;
}

int Preguntar(int i, int j) {
	no_preguntas++; // Una pregunta más
	/* printf("\nLlamada a preguntar(%d, %d)\n", i, j); */

	// Checa si la casilla consultada está fuera del mapa
	if(i <= 0 || j <= 0 || i > n || j > m) {
		/* puts("Consulta fuera del espacio de cobertura."); */
		return -1;
	}

	// Recorre todos los tesoros para contestar la pregunta
	int respuesta = 0;
	for(int k = 0; k < tesoros.size(); ++k) {
		if(tesoros[k].first <= i && tesoros[k].second <= j)
			respuesta++;
	}
	return respuesta;
}

// Main
//	int Preguntar(int i, int j)
//	bool Cavar(int i, int j)
int checked[1005][1005];
int mapa[1005][1005];
int mapa2[1005][1005];
int mapa3[1005][1005];

void vset(int i, int j, int k){
  mapa[i][j] = k;
  checked[i][j] = 1;
}

int v(int i, int j){
  if ( !checked[i][j] )
    vset(i, j, Preguntar(i, j));
  return mapa[i][j];
}

void founded(int i, int j){
  mapa3[i][j] = 1;
  for(int a = i; a <= n; a++)
    for( int b = j; b <= m; b++ )
      mapa2[a][b] ++;
}

void printMap(){
  for( int i = 1; i <= n; i++ ){
    for ( int j = 1; j <= m; j++ )
      printf("%d ", mapa[i][j]);
    printf("| ");
    for ( int j = 1; j <= m; j++ )
      printf("%d ", mapa2[i][j]);
    printf("| ");
    for ( int j = 1; j <= m; j++ )
      printf("%d ", mapa3[i][j]);
    printf("\n");
  }
  printf("\n");
}

void BuscaTesoros(int n, int m, int k) {

  mapa[1][1] = v(1, 1);
  if( mapa[1][1] == 1 ) founded(1, 1);
  
  for( int i = 2; i <= n; i++){
    printf("i: %d\n", i);
    printMap();
    mapa[i][i] = v(i, i);
    int current = mapa[i][i]-mapa[i-1][i-1];

    if( current > 0 ){

      int r = v(i-1, i)-v(i-1, i-1);
      if( r > 0 ) {
        if( i == 2 ) founded(i-1, i);
        else {
          int rr = r;
          for( int a = i-1; a >= 1 && rr ; a--){
            int t = v(a, i);
            if( t > v(i-1, i-1) && t > mapa2[a][i]){
              if(a == 1 || (  a > 1 && t > v(a-1, i) ) ) {
                founded(a, i); 
                rr--;
              }
            }
          }
        }
      }

      int u = current-r;
      if( u > 0 ) {
        if( i == 2 ) founded(i, i-1);
        else {
          int uu = u;
          for( int a = i-1; a >= 1 && uu; a--){
            int t = v(i, a);
            if( t > v(i-1, i-1) && t > mapa2[i][a] && t > v(i, a-1) ){
              if(a == 1 || (  a > 1 && t > v(i, a-1) ) ) {
                founded(i, a); 
                uu--;
              }
            }
          }
        }
      } 
      vset(i, i-1, u+v(i-1, i-1));

    }

  }
  printMap();
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j) {
			char car; scanf(" %c", &car);
			if(car == '1') tesoros.push_back({i, j});
		}
  }

	fclose(stdin);

	printf("Llamando a BuscaTesoros(%d, %d, %lu)\n", n, m, tesoros.size());
	BuscaTesoros(n, m, tesoros.size()); // Llamada inicial a tu función

	printf("\nHiciste %d preguntas.\n", no_preguntas);

	if(tesoros.size() > reportados.size())
		printf("\nSolo encontraste %lu tesoros :(\n", reportados.size());
	else
		puts("Excelente! Encontraste todos los tesoros.");

	return 0;
}
