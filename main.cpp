#include <iostream>
using namespace std;

// Prototipos
int getSizeOfMat();
void startGame(int n);

int main() {
  int n = 0;
  n = getSizeOfMat();
  startGame(n);
}

// Le pide al usuario el tamaño de la matriz
int getSizeOfMat() {
  int n;
  do {
    cout << "Ingresa tamaño de la matriz(>1): ";
    cin >> n;
  } while(n<2);
  return n;
}

// Le pide al usuario la ficha con la que jugará
char setPlayer(char ficha) {
  while(ficha != 'x' && ficha != 'o') {
    cout << "Escoge tu ficha(o o x): ";
    cin >> ficha;
  }
  return ficha;
}

// Imprimir ganador
void printWinner(char ficha) {
  cout << "###########################\n";
  cout << "El ganador es la ficha " << ficha << " :D\n";
  cout << "###########################\n";
}

// Comienza el juego
void startGame(int n) {
  char ficha = 0;
  bool isWon = false;
  int timesMatch = 0;
  int timesPlayed = 0;
  char val = 0;

  ficha = setPlayer(ficha);
  
  // Crea la matriz
  // inicializo matriz
  char** mat = NULL;
  // Definir el espacio y el tipo de datos que tendrá la matriz
  mat = new char* [n];
  // Agregando las columnas
  for(int i=0; i<n; i++) {
    mat[i] = new char[n];
  }
  // Dando valores a mi matriz
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      mat[i][j] = '*';
    }
  }
  // Imprimir mi matriz
  cout << "---------------------------\n";
  cout << "Tablero de " << n << 'x' << n << ": \n";
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout << mat[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << "---------------------------\n";  

  // Jugada
  while(!isWon) {
    int x, y;
    bool ficha_rep = false;

    do {
      // Input example: 0 1
      cout << "Posición del jugador con la ficha " << ficha << ": ";
      cin >> x >> y;

      if(x<n && y<n) {
        if(mat[x][y] == '*') {
          ficha_rep = true;
        }
      }
    } while(!ficha_rep);

    // Veces que se realiza una jugada
    timesPlayed++;

    // Limpia pantalla
    system("clear");

    // Asignando jugada con x u o;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        if(i == x && j == y) {
          mat[i][j] = ficha;
        }
      }
    }

    cout << "---------------------------\n";
    cout << "Tablero: \n";
    // Imprimir mi matriz
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        cout << mat[i][j] << ' ';
      }
      cout << '\n';
    }
    cout << "---------------------------\n";

    // Verificar si es empate
    if(timesPlayed == n*n){
      cout << "##########################\n";
      cout << "x y o quedaron empates o:\n";
      cout << "##########################\n";
      break;
    }

    // Encuentra al ganador de las filas
    for(int i=0; i<n; i++) {
      val = mat[i][0];
      for(int j=0; j<n; j++) {
        if(val == mat[i][j] && val !='*') {
          timesMatch++;
          if(n == timesMatch) {
            printWinner(ficha);
            isWon = true;
            break;
          }
        }
      }
      timesMatch = 0;
    }

    // Encuentra al ganador de las columnas
    for(int i=0; i<n; i++) {
      val = mat[0][i];
      for(int j=0; j<n; j++) {
        if(val == mat[j][i] && val !='*') {
          timesMatch++;
          if(n == timesMatch) {
            printWinner(ficha);
            isWon = true;
            break;
          }
        }
      }
      timesMatch = 0;
    }

    // Encuentra al ganador de las diagonal izq
    for(int i=0; i<n; i++) {
      val = mat[0][0];
      for(int j=0; j<n; j++) {
        if(i == j) {
          if(val == mat[i][j] && val !='*') {
            timesMatch++;
            if(n == timesMatch) {
              printWinner(ficha);
              isWon = true;
              break;
            }
          }
        }
      }
    } 
    timesMatch = 0;

    // Encuentra al ganador de las diagonal der
    for(int i=0; i<n; i++) {
      val = mat[0][n-1];
      for(int j=0; j<n; j++) {
        if(i + j == n-1) {
          if(val == mat[i][j] && val !='*') {
            timesMatch++;
            if(n == timesMatch) {
              printWinner(ficha);
              isWon = true;
              break;
            }
          }
        }
      }
    } 
    timesMatch = 0;

    // Cambia ficha para la siguiente jugada
    ficha!='x' ? ficha='x': ficha='o';
  }

  // Limpiar espacio de memoria 
  for(int i=0; i<n; i++) {
    delete [] mat[i];
  }

  delete [] mat;
}