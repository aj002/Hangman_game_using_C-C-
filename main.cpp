#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
	//printf("hello world\n");
    
    char c,h,ch,ch1,ch2,word[25],word2[25];
    int l,i,ng,n,k,x;
    
    //do
    {
        do
        {
            c = '\0';
            cout<<"\n\t\t******** HANGMAN GAME IN C++ ********\n\n";
            cout<<"(E) Enter a word\n\n";
            cout<<"(C) Computer chooses word\n\n";
            cout<<"(A) Add new word to list\n\n";
            cout<<"(Q) Quit\n\n\n";
            cout<<"Enter your choice (E - C - Q): ";
            cin>>ch2;
        }while(ch2!='e'&&ch2!='E'&&ch2!='c'&&ch2!='C'&&ch2!='a'&&ch2!='A'&&ch2!='q'&&ch2!='Q');
        
        if(ch2!='q' || ch2!='Q')
        {
            exit(0);
        }
        else if(ch2!='c' || ch2!='C')
        {
            ifstream fin("hangword.txt");
            
            if(!fin)
            {
                cout<<"File missing";
                cin.ignore().get();
                return 0;
            }
            
            for(i=0;!fin.eof();i++)
            {
                fin.getline(word,25);
            }
            
            fin.close();
            
            do
            {
                x = rand();
            }while(x>i || x<0);
            
            ifstream finn("hangword.txt");
            
            for(i=0;!finn.eof();i++)
            {
                finn>>c;
                finn.getline(word,25);
                if(x==i)
                {
                    break;
                }
            }
            
            finn.close();
        }
        else if(ch2!='a'&&ch2!='A')
        {
            
        }
    }
    
    
	return 0;
}