/*
 * Programm to implement frequency reuse
 * Prateek Prasher
 */

#include <iostream>
using namespace std;

// A point 
struct point
{
    int x,
        y;
        
    point(): x(0), y(0)
    {   }
    
    point(int i, int j) : x(i), y(j)
    {   }
    
    void setPoint(int i, int j)
    {
        x = i;
        y = j;
    }
    
    void print()
    {
        cout << "(" << x << ", " << y << ")";
    }
};

// Grid parameters
int mat[10][10];
int size = 0;

// Funtion to check validity of pt
bool isValid(point &pt)
{
    if(pt.x < 0 || pt.y < 0)
        return false;
    
    if(pt.x > size || pt.y > size)
        return false;
    return true;
}

// Function to check neighbors for identical frequency
bool neighborHasFreq(int &freq, point pt)
{
    point ptArr[8];
    ptArr[0].setPoint(pt.x - 1, pt.y);
    ptArr[1].setPoint(pt.x - 1, pt.y +1);
    ptArr[2].setPoint(pt.x, pt.y + 1);
    ptArr[3].setPoint(pt.x + 1, pt.y + 1);
    ptArr[4].setPoint(pt.x + 1, pt.y);
    ptArr[5].setPoint(pt.x + 1, pt.y - 1);
    ptArr[6].setPoint(pt.x, pt.y - 1);
    ptArr[7].setPoint(pt.x - 1, pt.y - 1); 
    
    for(int i = 0; i < 8; i++)
    { 
        if(isValid(ptArr[i]))
        {
            if(mat[ptArr[i].x][ptArr[i].y] == freq)
            {
                //cout << "pt "; ptArr[i].print(); cout << "has same" << freq<< endl;
                return true;
            }
        }          
    }
    
    return false;
}

int main()
{
    int currFreq = 1;
    
    cout << "Enter size of grid: "; 
    cin >> size; 
    
    // Allocate the frequency
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            currFreq = 1;
            
            //cout << "Curr " << i << ", " << j << endl;
            while(neighborHasFreq(currFreq, point(i, j)))
            {
                currFreq++;
            }
            
            mat[i][j] = currFreq;
            //cout << "Curr assigned" <<currFreq<< endl;  
        }
    }
    
    // Print the original matrix
    cout << endl << "The original matrix is: " << endl;
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << mat[i][j] << "    ";
        }
        cout << endl;
    }    
    
    // Get the position to replace
    point pt;
    cout << endl << "Enter space seprated values i, j: ";
    cin >> pt.x >> pt.y;
    
    // Now print the modified matrix
    cout << endl << "The modified matrix is: " << endl;
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i == pt.x && j == pt.y)
            	cout << " " << "    ";
            else
            	cout << mat[i][j] << "    ";
        }
        cout << endl;
    }
    
    
    // Re-allocate the frequency
    currFreq = 1;
    
    while(neighborHasFreq(currFreq, point(pt.x, pt.y)))
    {
    	currFreq++;
    }
            
    mat[pt.x][pt.y] = currFreq;
    
    // Matrix after reallocation of frequency 
    cout << endl << "The final matrix is: " << endl;
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << mat[i][j] << "    ";
        }
        cout << endl;
    } 
}
