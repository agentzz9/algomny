#include <iostream>
#include <vector>
using namespace std;
int getQuadrant(int n, vector <string> grid){
    
    if(grid[0][n-1]=='p')
    {
        return 1;    
    }
    else if(grid[0][0]=='p')
    {
        return 2;    
    }
    else if(grid[n-1][0]=='p')
    {
        return 3;
    }
    else
    {
        return 4;    
    }

}
void printForHorizontal(int n, vector <string> grid, int quadrant){

    if(quadrant==1 || quadrant==4)
    {
          for(int i=1;i<=n/2;i++){
                
          printf("RIGHT\n");      
          }      
    }
    else
    {
        
        for(int i=1;i<=n/2;i++){
                
          printf("LEFT\n");      
          }   
        
    }
}
void printForVertical(int n, vector <string> grid, int quadrant){

    if(quadrant==3 || quadrant==4)
    {
          for(int i=1;i<=n/2;i++){
                
          printf("DOWN\n");      
          }      
    }
    else
    {
        
        for(int i=1;i<=n/2;i++){
                
          printf("UP\n");      
          }   
        
    }
}

void displayPathtoPrincess(int n, vector <string> grid){
    
    
    int quadrant = getQuadrant(n,grid);
    
    printForHorizontal(n,grid,quadrant);
    printForVertical(n,grid,quadrant);
    
    getchar();
    
    //your logic here
}
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
