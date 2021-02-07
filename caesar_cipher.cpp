#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char msg[20];
    cout << "Enter the message: ";
    cin >> msg;
    int msg_size = strlen(msg);
    char ciphertext[msg_size], deciphertext[msg_size];
    cout << "Original message: " << msg << endl;
    int key;
    cout << "Enter the value of key: ";
    cin >> key;

    cout << "Ciphertext: ";
    for(int i = 0; i < msg_size; i++){
        ciphertext[i] = char(int('a') + (((int(msg[i]) % int('a')) + key) % 26));
    }
    ciphertext[msg_size] = '\0';
    cout << ciphertext;

    cout << endl << "Deciphertext: ";
    for(int i = 0; i < msg_size; i++){
        int temp = int(ciphertext[i]) - (key % 26);
        if(temp >= int('a'))
            deciphertext[i] = char(temp);
        else{
            int temp1 = int('a') - temp - 1;
            deciphertext[i] = char(int('z') - temp1 % 26);
        }

    }
    deciphertext[msg_size] = '\0';
    cout << deciphertext;

    return 0;
}
