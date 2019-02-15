#include <stdio.h>

#include <stdlib.h>

char m[3][3];
char valida(void);
void init_m(void);
void turno_j(void);
void turno_ia(void);
void muestra_m(void);

void init_m(void){
    
    int i, j;
    
    for(i=0; i<3; i++)
    
    for(j=0; j<3; j++) m[i][j] = ' ';

}


void turno_j(void){

    int x, y;
    
    printf("Ingresa las cordenadas del tablero : ");
    
    scanf("%d%*c%d", &x, &y);
    
    x--; y--;
    
    if(m[x][y]!= ' '){
    
    printf("Movimiento no permitido\n");
    
    turno_j();

}

else m[x][y] = 'x';

}


void turno_ia(void){
    int i, j;
    for(i=0; i<3; i++){
    for(j=0; j<3; j++)
    if(m[i][j]==' ') break;
    if(m[i][j]==' ') break;
    
    }
    if(i*j==9) {
    printf("Empate\n");
    exit(0);
}

else

m[i][j] = 'o';

}

void muestra_m(void){
int t;

    for(t=0; t<3; t++) {
    
        printf(" %c | %c | %c ",m[t][0],
        
        m[t][1], m [t][2]);
        
        if(t!=2) {
            printf("\n---|---|---\n");
        }
    
    }

printf("\n");

}

void tab_i(void){
int t, j=0;
        printf("Cordenadas del tablero");
        printf("\n");
        printf("1 1 |1 2 |1 3 ");
        printf("\n----|----|----\n");
        printf("2 1 |2 2 |2 3 ");
        printf("\n----|----|----\n");
        printf("3 1 |3 2 |3 3 ");

printf("\n");
printf("**Ejemplo Ingresa las cordenadas del tablero: 1 1**\n");
printf("\n");

}


char valida(void)

{

    int i;
    
    for(i=0; i<3; i++)
    
        if(m[i][0]==m[i][1] && m[i][0]==m[i][2]) {
        
            return m[i][0];
        
        }
        
        for(i=0; i<3; i++)
        
            if(m[0][i]==m[1][i] && m[0][i]==m[2][i]){
                
                return m[0][i];
                
            }
        
        if(m[0][0]==m[1][1] && m[1][1]==m[2][2]){
            
            return m[0][0];
            
        }
        
        if(m[0][2]==m[1][1] && m[1][1]==m[2][0]){
            
            return m[0][2];
            
        }
    
    return ' ';

}

int main(void){
    tab_i();
    char aca;
    aca = ' ';
    init_m();
    do {
        muestra_m();
        turno_j();
        aca = valida();
        if(aca!= ' ') break;
        turno_ia();
        aca = valida();
    
    } while(aca== ' ');
    
    if(aca=='X'){
        printf("GPerdiste\n");
    }
    else {
        printf("Ganaste\n");
    }
    muestra_m();
    return 0;
}