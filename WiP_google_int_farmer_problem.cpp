#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <map> 
/*
There is a farmer and they want to farm their land with maximum area where good land is present.
The land is represented as a matrix with 1s and 0s. 1s means good land and 0s means bad land.
The farmer only want to farm in a square good land with maximum area.
Please help the farmer to find the co-ordinates and maximum area of the land they can farm in good land.

example:

0 1 0 0 1
1 0 0 1 0
0 1 1 1 0
1 1 1 1 0
1 1 1 1 1
0 0 0 0 0

Expected output => starting cordinator and the length

(2,1) 3

*/

/* Practice with classes and basics of cpp*/
class Field{
private:
    std::vector<std::vector<int>> dati;
    int nrighe = 0;
    int ncolonne = 0;
public:
    Field(int x, int y) : nrighe(x), ncolonne(y), dati(x, std::vector<int>(y, 0)) {
        // Inizializza con valori solo se la matrice è 6x5/ esempio
        if (x == 6 && y == 5) {
            dati = {{0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Field& f){
        for (const auto& riga : f.dati) {
            for (int valore : riga) {
                os << valore << " ";
            }
            os << std::endl;
        } os << std::endl;
        
        return os;
    }

};

/* End of practice*/

/*Actual solution*/
typedef struct{
    int x;
    int y;
    int length;
}field_t;

field_t max_field(std::vector<std::vector<int>> , int nrow, int ncol){
    field_t res;
    for(int i=0; i< nrow;  i++){
        for(int j=0; j<ncol; j++){
            if(matrix[i][j] != 0){
                int x = i + 1;
                int y = j + 1;
                int length = 1;
                bool flag_square = true; /*true se il quadrato è ancora pieno di 1, false se trovo uno 0*/

                while(x < nrow && y < ncol && flag_square){
                    /*Ora verifico se il quadrato è riempito di 1*/
                    if(matrix[x][y] == 1){
                        /*Cerco andando a ritroso per le righe se ci sono gli 1*/
                        for(int t = x; t >= i; t--){
                            if(matrix[t][y] != 1){
                                flag_square = false;
                            }
                        }
                        /*Cerco andando a ritroso per le colonne se ci sono gli 1*/
                        for(int t = y; t >= j; t--){
                            if(matrix[x][t] != 1){
                                flag_square = false;
                            }
                        }

                        x++;
                        y++;
                        length = flag_square? length+1 : length;
                    }else{
                        flag_square = false;
                    }
                }
                
            }
        }
    }
    return res;
}

int main (){
    std::unique_ptr<Field> f1 = std::make_unique<Field>(5,6);
    std::cout << *f1 << std::endl;

    
}
