#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    if(mat.size()==0) return false;
	
    int i=0,j=n-1;
    
    while(i<m && j>=0)
    {
        if(mat[i][j]==target) return true;
        
        if(target<mat[i][j]) j--;
        else i++;
    }
    
    return false;
}