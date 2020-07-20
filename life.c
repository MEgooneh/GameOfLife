#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int w = 30 , h = 30 ;
int world[30][30] ;
void draw(){
    //put your console command to clear the output
    for(int i = 0 ; i < 30 ; i++)
    printf( "\n");
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            if(world[i][j] == 1)
                printf( "@" );
            else
                printf( " " );
        }
        printf( "\n" ) ;
    }
}
void config(){
    int add[30][30] , lifes ;
    for(int i = 0  ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            lifes = 0 ;
            for(int x = i-1 ; x <= i+1 ; x++ ){
                    for(int y = j-1 ; y <= j+1 ; y++){
                        if(world[(y+h) % h][(w+x) % w] )
                            lifes++;
                    }
            }
            if(world[j][i])lifes-- ;
            add[j][i] = (lifes == 3 || (lifes == 2 && world[j][i]) ) ;
        }
    }
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++)
            world[i][j] = add[i][j] ;
    }
}
int main(){
    srand(time(0));
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            if(rand()  < RAND_MAX / 5)
                world[i][j] = 1 ;
            else
                world[i][j] = 0 ;
        }
    }
    while(1){
    draw() ;
    config() ;
    usleep(1000000) ;
}
}
