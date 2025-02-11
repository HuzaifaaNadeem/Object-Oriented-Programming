#include <iostream>
#include <cstring>
using namespace std;

char* shft_chr(char* txt, int n) {
    int len = strlen(txt);
    if (n <= 0 || n >= len) {
        return txt;
    }
    
    char* newTxt = new char[len + 1];
    char* pOld = txt + (len - n);
    char* pNew = newTxt;
    
    for (int i = 0; i < n; i++) {
        *pNew++ = *pOld++;
    }
    
    pOld = txt;
    for (int i = 0; i < len - n; i++) {
        *pNew++ = *pOld++;
    }
    
    *pNew = '\0';
    return newTxt;
}

int main() {
    char txt[100];
    int n;
    
    cout << "Enter a string: ";
    cin >> txt;
    cout << "Enter the number of characters to shift: ";
    cin >> n;
    
    char* shftTxt = shft_chr(txt, n);
    cout << "Shifted string after shifting last " << n << " characters: " << shftTxt << endl;
    
    delete[] shftTxt;
    return 0;
}
